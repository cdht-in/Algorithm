/*
	
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before 

*/

#include <unordered_map>
#include <iostream>

using namespace std;

struct LRUListNode{
	int key;
	int val;
	LRUListNode* next;
	LRUListNode* prev;
	
	LRUListNode()
	{
		key = 0;
		val = 0;
		next = 0;
		prev = 0;
	}
};

class LRUCache{
	
	unordered_map<int,LRUListNode*> map;
	int capacity;
	int c;
	LRUListNode* head;
	LRUListNode* p;
	
	void MoveNodeToEnd(LRUListNode* node)
	{
		//if node is the end of the list
		if(node == p)
		{
			return;
		}
		
		//remove the node from it's location
		node->prev->next = node->next;
		if(node->next)
		{
			node->next->prev = node->prev;
		}
		
		//put it in the end
		p->next = node;
		node->prev = p;
		node->next = 0;
		p = p->next;
		
		//remap the node
		map[node->key] = p;
	}
		
public:
    LRUCache(int capacity) {
		this->capacity = capacity;
		this->c = 0;
		head = new LRUListNode;
		p = head;
    }
    
    int get(int key) {
		if(map.find(key) == map.end())
        {
        	return -1;
        }
		MoveNodeToEnd(map[key]);
		return p->val;
    }
    
    void set(int key, int value) {
        //check if the key is in the cache first
		if(map.find(key) == map.end())
		{
			//dump the least recent used one, e.g. the head
			if(c == capacity)
			{
				//if capacity is 0
				if(head->next == 0)
					return;
				
				//if capacity is 1
				if(p == head->next)
				{
					p = head;
				}
				
				LRUListNode* tmp = head->next;
				
				head->next = head->next->next;
				
				if(head->next)
				{
					head->next->prev = head;	
				}
								
				map.erase(tmp->key);
				delete tmp;
			    c--;
			}
			
			LRUListNode* node = new LRUListNode;
			node->key = key;
			node->val = value;
			
			p->next = node;
			node->prev = p;
			node->next = 0;
			
			p = p->next;
			c++;
			
			map[key] = node;
			
		}
		else
		{
			MoveNodeToEnd(map[key]);
			p->val = value;
		}
    }
};


int main()
{
	LRUCache cache(1);
	cache.set(2,1);
	cache.get(2);
	cache.set(3,2);
	cache.get(2);
	cache.get(3);
	
}