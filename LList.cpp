/* 
Author: Kostiantyn Kurbatskyi
 */
#include "LList.h"

#include <iostream>

LList::LList() {
	this->list = new Node[DEFAULT_SIZE];

	this->freeList = this->list;
	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		this->freeList[i].item = UNINITIALIZED_ITEM;
		this->freeList[i].next = i + 1;
	}
	this->freeList[DEFAULT_SIZE - 1].next = END;


	this->head = END;
	this->free = 0;
	
	this->capacity = DEFAULT_SIZE;
}

bool LList::isEmpty() const
{
	return head == END;
}

bool LList::isFull() const
{
	return free == END;
}

int LList::length() const
{
	int count = 0;
	int temp = this->head;
	while (temp != END)
	{
		temp = this->list[temp].next;
		count++;
	}

	return count;
}

void LList::makeRoom() 
{
	if (isFull())
	{
		int newCapacity = this->capacity * 2;

		Node* newList = new Node[newCapacity];
		this->freeList = newList;
		for (int i = 0; i < newCapacity; i++)
		{
			newList[i].item = UNINITIALIZED_ITEM; //fill with #
		}

		int temp = head;
		while (temp != END)
		{
			newList[temp].item = this->list[temp].item;
			newList[temp].next = this->list[temp].next;
			temp = this->list[temp].next;
		}

		for (int i = capacity; i < newCapacity; i++)
		{
			newList[i].next = this->free;
			this->free = i;
		}

		delete[] this->list;
		this->list = newList;

		this->capacity = newCapacity;
	}
}

bool LList::cons(char ch)
{
	if (this->isEmpty()) 
	{
		this->list[this->free].item = ch;
		this->head = this->free;
		this->free = this->freeList[this->free].next;
		this->list[this->head].next = END;


		try
		{
			this->makeRoom();
		}
		catch (const std::bad_alloc&)
		{
			return false;
		}


		return true;
	}

	int newFree = this->freeList[this->free].next;

	this->list[this->free].item = ch;
	this->list[this->free].next = this->head;
	this->head = this->free;
	this->free = newFree;
	
	
	try
	{
		this->makeRoom();
	}
	catch(const std::bad_alloc&)
	{
		return false;
	}
	

	return true;
}

bool LList::append(char ch)
{
	int temp = this->head;
	if (isEmpty())
	{
		this->list[this->free].item = ch;
		this->head = this->free;
		this->list[this->free].next = END;
		this->free = this->freeList[this->free].next;


		try
		{
			this->makeRoom();
		}
		catch (const std::bad_alloc&)
		{
			return false;
		}

		return true;
	}
	while (this->list[temp].next != -1) 
	{
		temp = this->list[temp].next;
	}
	
	this->list[temp].next = this->free;
	this->list[this->free].item = ch;
	this->free = this->freeList[this->free].next;

	try
	{
		this->makeRoom();
	}
	catch (const std::bad_alloc&)
	{
		return false;
	}

	return true;
}

bool LList::remove(char ch)
{

	int tempHead = this->head;
	if (this->list[tempHead].item == ch)
	{
		Node temp = this->list[this->list[tempHead].next];
		head = this->list[tempHead].next;

		temp.next = this->free;
		this->free = tempHead;
		this->list[this->free].item = UNINITIALIZED_ITEM;

		return true;
	}

	while (this->list[tempHead].next != END && this->list[this->list[tempHead].next].item != ch)
	{
		tempHead = this->list[tempHead].next;
	}
	if (this->list[tempHead].next == END)
	{
		return false;
	}

	int tempInt = this->list[tempHead].next;
	//Node temp = this->list[this->list[tempHead].next];
	this->list[tempHead].next = this->list[this->list[tempHead].next].next;
	this->list[tempInt].next = free;
	this->list[tempInt].item = UNINITIALIZED_ITEM;
	this->free = tempInt;
	return true;
}

bool LList::search(char ch) const
{
	int tempHead = this->head;
	while (tempHead != END && this->list[tempHead].item != ch) 
	{
		tempHead = list[tempHead].next;
	}
	if (tempHead == -1)
	{
		return false;
	}

	return true;
}


std::string LList::toString() const
{
	std::string str = "[ ";
	int temp = this->head;
	for (int i = this->head; i != END; i = this->list[i].next)
	{
		str += this->list[i].item + std::string(" ");
	}
	return	str + "]";
}

// copy constructor
LList::LList(const LList& other) {
   try {
      this->capacity = other.capacity;
	  this->list = new Node[this->capacity];
	  this->freeList = this->list;
	  int temp = other.head;
	  int count = 0;
	  while (temp != -1) 
	  {
		  this->list[count].item = other.list[temp].item;
		  this->list[count].next = count + 1;
		  temp = other.list[temp].next;
		  count++;
	  }
	  this->list[count - 1].next = END;
	  this->head = 0;
	  this->free = count;
	  while (count != capacity)
	  {
		  this->freeList[count].next = count + 1;
		  count++;
	  }
	  this->freeList[count - 1].next = END;
   }
   catch (const std::bad_alloc&) {
      std::cerr << "in copy constructor: not enough heap memory -- bye, exiting the program";
      exit(2);
   } 
}

// destructor
LList::~LList() 
{
	delete[] list;
}

// overload the assignment operator
LList& LList::operator = (const LList& other) {
      try {
         return LList(other);
      }
      catch (const std::bad_alloc&) {
         std::cerr << "in overloaded = operator,not enough heap memory -- bye, exiting the program";
         exit(3); 
      }
   return *this;
}

#ifndef NDEBUG
using std::cerr;
void LList::dumpNodesArray() const {
   cerr << "head = " << head << "\tfree = " << free << "\n";
}
#endif
