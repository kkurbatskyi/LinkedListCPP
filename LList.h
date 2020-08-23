#ifndef LLIST_H
#define LLIST_H
/* 
 * 
Author: Kostiantyn Kurbatskyi
Class that implements a Linked List with an array
 * 
 */

#include <string>
class  LList {
   public:
      // build a list
      LList();
      // determine if the list is empty
      bool isEmpty() const;
      // give the length of the list
      int length() const;
      // insert ch at the beginning (at the front) of the linked list
      // return true if successful, false otherwise
      bool cons(char ch);
      // append ch to the end of the linked list
      // return true if successful, false otherwise
      bool append(char ch);
      // delete the first occurrence of ch in the list 
      // if the deletion happens, return true, false otherwise
      bool remove(char ch); 
      // search ch in the list, return true if found, false otherwise
      bool search(char ch) const;
      // mutator method (function) that reverses the list
      void reverse();
      // returns a string consisting of all the characters of the list
      // in the order in which they are in the list 
      // the string returned starts with a "[" followed by a blank 
      // followed by each character of the list with its subsequent blank
      // and finishes with a "]"
      // e.g. the string returned would be  "[ a b d ]"
      std::string toString() const;
      // copy constructor
      LList(const LList&);
      // overload the assignment operator      
      LList& operator = (const LList& other);
      // destructor 
      ~LList();
      #ifndef NDEBUG
      // dump the array, print the contents with std::cerr
      void dumpNodesArray() const;
      // initialize the item field to UNINITIALIZED_ITEM so that when we are 
      // printing the array, we see a # to indicate that the field is not initialized
      static const char UNINITIALIZED_ITEM = '#';
      #endif 
   private:
	  struct Node {
		  int next;
		  char item;
	  };

	  bool isFull() const;

	  //Grows an array when needed
	  void makeRoom();

	  static const int DEFAULT_SIZE = 5;
	  static const int END = -1;

	  Node* list;
	  Node* freeList;
      // index of first node in the linked list
      int head;
      // index of the first node of the 'free linked list'
      int free;

	  int capacity;
};
#endif
