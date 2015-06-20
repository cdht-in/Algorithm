#include <iostream>

using namespace std;

class HeapItem
{
     private:
          int m_iKey;                              // Heap item priority key
          double m_dData;                         // Dummy data value

     public:
          HeapItem();                              // Default constructor
          HeapItem(int key, double data);     // Constructor
          ~HeapItem();                         // Destructor
          int getKey();                         // Return item priority
          void setKey(int key);               // Set the priority key value
          double getData();                    // Return data item
          void setData(double data);          // Set the data item value
};

HeapItem::HeapItem()
{
     m_iKey = 0;
     m_dData = 0.0;
}

//-----------------------------------
// Constructor
//-----------------------------------
HeapItem::HeapItem(int key, double data)
{
     m_iKey = key;
     m_dData = data;
}

//-----------------------------------
// Destructor
//-----------------------------------
HeapItem::~HeapItem()
{
}

//-----------------------------------
// Return item priority
//-----------------------------------
int HeapItem::getKey()
{
     return m_iKey;
}

//-----------------------------------
// Set the priority key value
//-----------------------------------
void HeapItem::setKey(int key)
{
     m_iKey = key;
}

//-----------------------------------
// Return data item
//-----------------------------------
double HeapItem::getData()
{
     return m_dData;
}

//-----------------------------------
// Set the data item value
//-----------------------------------
void HeapItem::setData(double data)
{
     m_dData = data;
}

class Heap
{
     private:
          HeapItem     *m_Elements;                 // Pointer to dynamically allocated array
          int          m_iNumElements;              // Number of elements in the heap
          int          m_iHeapLength;               // Size of the array

     public:
          Heap(int size = 10);                     // Parameterized constructor
          ~Heap();                                 // Destructor
          void ReheapDown(int root, int bottom);   // Reheap after removing item
          void ReheapUp(int root, int bottom);     // Reheap after inserting item
          bool Enqueue(HeapItem *item);            // Add an item to the heap
          bool Enqueue(int key, double data);      // Add an item to the heap
          HeapItem *Dequeue();                     // Get item at the root
          int getNumElements();                    // Return number of elements in the heap
          void printAll();                         // Print all the elements in the heap
};

//---------------------------------------
// Parameterized default constructor
//---------------------------------------
Heap::Heap(int size)
{
     // Create heap of given size
     m_Elements = new HeapItem[size];
     m_iNumElements = 0;
     m_iHeapLength = size;
}

//---------------------------------------
// Destructor
//---------------------------------------
Heap::~Heap()
{
     delete[] m_Elements;
}

//---------------------------------------
// Reheap after removing item
//---------------------------------------
void Heap::ReheapDown(int root, int bottom)
{
     int maxChild;
     int rightChild;
     int leftChild;
     HeapItem temp;

     leftChild = root * 2 + 1;          // Get index of root's left child
     rightChild = root * 2 + 2;          // Get index of root's right child

     // Check base case in recursive calls.  If leftChild's index is less
     // than or equal to the bottom index we have not finished recursively 
     // reheaping.
     if(leftChild <= bottom)               
     {
          if(leftChild == bottom)          // If this root has no right child then 
          {
               maxChild = leftChild;     //     leftChild must hold max key
          }
          else
          {     // Get the one lowest in the tree (highest index in the array)
               if(m_Elements[leftChild].getKey() <= m_Elements[rightChild].getKey())
                    maxChild = rightChild;
               else
                    maxChild = leftChild;
          }
          if(m_Elements[root].getKey() < m_Elements[maxChild].getKey())
          {
               // Swap these two elements
               temp = m_Elements[root];
               m_Elements[root] = m_Elements[maxChild];
               m_Elements[maxChild] = temp;
               // Make recursive call till reheaping completed
               ReheapDown(maxChild, bottom);
          }
     }
}

//---------------------------------------
// Reheap after inserting item
//---------------------------------------
void Heap::ReheapUp(int root, int bottom)
{
     int parent;
     HeapItem temp;

     // Check base case in recursive calls.  If bottom's index is greater
     // than the root index we have not finished recursively reheaping.
     if(bottom > root)
     {
          parent = (bottom -1) / 2;
          if(m_Elements[parent].getKey() < m_Elements[bottom].getKey())
          {
               // Swap these two elements
               temp = m_Elements[parent];
               m_Elements[parent] = m_Elements[bottom];
               m_Elements[bottom] = temp;
               // Make recursive call till reheaping completed
               ReheapUp(root, parent);
          }
     }
}

//---------------------------------------
// Add an item to the heap
//---------------------------------------
bool Heap::Enqueue(HeapItem *item)
{
     if(m_iNumElements < m_iHeapLength)
     {
          m_Elements[m_iNumElements] = *item; // Copy item into array
          ReheapUp(0, m_iNumElements);
          m_iNumElements++;
          return true;
     }
     return false;
}

//---------------------------------------
// Add an item to the heap
//---------------------------------------
bool Heap::Enqueue(int key, double data)
{
     bool retVal;
     HeapItem *temp = new HeapItem(key, data);
     retVal = Enqueue(temp);
     delete temp;  // Delete this dynamically created one
     return retVal;
}

//---------------------------------------
// Get item at the root
//---------------------------------------
HeapItem *Heap::Dequeue()
{
     HeapItem *temp = new HeapItem(m_Elements[0].getKey(), m_Elements[0].getData());
     m_iNumElements--;
     // Copy last item into root
     m_Elements[0] = m_Elements[m_iNumElements];
     // Reheap the tree
     ReheapDown(0, m_iNumElements - 1);
     if(m_iNumElements == 0)
         return NULL;
     else
         return temp;
}

//---------------------------------------
// Return number of elements in the heap
//---------------------------------------
int Heap::getNumElements()
{
     return m_iNumElements;
}

//---------------------------------------
// Print all the elements in the heap
//---------------------------------------
void Heap::printAll()
{
     for(int i=0; i<m_iNumElements; i++)
     {
          cout << "Heap element " << i << ". key=" << m_Elements[i].getKey() << "  data=" <<
               m_Elements[i].getData() << endl;
     }
}

int main()
{
	Heap *theHeap = new Heap(10);  // Create a heap of the default size

	cout << "Building the heap and adding items\n\n";

	// Add some items
	theHeap->Enqueue(123, 1.23);
	theHeap->Enqueue(345, 3.45);
	theHeap->Enqueue(234, 2.34);
	theHeap->Enqueue(678, 6.78);
	theHeap->Enqueue(456, 4.56);
	theHeap->Enqueue(567, 5.67);
	theHeap->Enqueue(789, 7.89);

	// This will build a heap that looks like this
	//                    789 
	//                   /   \
	//                456     678
	//                / \     / \
	//              123 345 234 567

	// See what we got
	cout << "Elements in the heap.\n";
	theHeap->printAll();

	cout << "Dequeuing items from the heap.\n\n";
	
	HeapItem* temp;

	while((temp = theHeap->Dequeue()) != NULL)
	{
		cout << "Dequeueing " << temp->getKey() << endl;
		delete temp; // delete this one
		// See what we have left
		cout << "Elements in the heap.\n";
		theHeap->printAll();
		cout << endl;
	}
	
}