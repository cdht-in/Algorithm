#include <iostream>

using namespace std;

typedef int Topic;

const Topic NO_HELP_TOPIC = -1;
const Topic PRINT_TOPIC = 1;
const Topic PAPER_ORIENTATION_TOPIC = 2;
const Topic APPLICATION_TOPIC = 1;

class HelpHandler
{
	HelpHandler* mSuccessor;
	Topic mTopic;
	
public:
	HelpHandler(HelpHandler* handler = 0, Topic topic = NO_HELP_TOPIC): mSuccessor(handler), mTopic(topic){}
				
	virtual bool HasHelp()
	{
		return mTopic != NO_HELP_TOPIC;
	}
	
	virtual void SetHandler(HelpHandler* handler, Topic topic)
	{
		mSuccessor = handler,
		mTopic = topic;
	}
	
	virtual void HandleHelp()
	{
		if(mSuccessor != 0)
		{
			mSuccessor->HandleHelp();
		}
	}	
};

class Widget : public HelpHandler
{
	Widget* mParent;
	
protected:
	Widget(Widget* parent = 0, Topic topic = NO_HELP_TOPIC): mParent(parent),HelpHandler(parent,topic){}
};

class Button : public Widget
{
public:
	Button(Widget* d = 0, Topic topic = NO_HELP_TOPIC): Widget(d,topic){}
	
	virtual void HandleHelp()
	{
		if(HasHelp())
		{
			cout << "handle from button" << endl;
		}
		else
		{
			HelpHandler::HandleHelp();
		}
	}
};

class Dialog : public Widget
{
public:
	Dialog(HelpHandler* d = 0, Topic topic = NO_HELP_TOPIC): Widget(0)
	{
		SetHandler(d,topic);
	}
	
	virtual void HandleHelp()
	{
		if(HasHelp())
		{
			cout << "handle from dialog" << endl;
		}
		else
		{
			HelpHandler::HandleHelp();
		}
	}
};

class Application: public HelpHandler
{
public:
	
	Application(Topic topic = NO_HELP_TOPIC): HelpHandler(0,topic){}
	
	virtual void HandleHelp()
	{
		if(HasHelp())
		{
			cout << "handle from application" << endl;
		}
		else
		{
			HelpHandler::HandleHelp();
		}
	}
	
};
	
int main()
{
	//usage to chain them together
	Application* application = new Application(APPLICATION_TOPIC);
	
	Dialog* dialog = new Dialog(application,PRINT_TOPIC);
	
	Button* button = new Button(dialog,PAPER_ORIENTATION_TOPIC);
	
	button->HandleHelp();
}