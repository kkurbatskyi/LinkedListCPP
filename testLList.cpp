/* 
Author: Kostiantyn Kurbatskyi
 */
#include "LList.h"
#include <iostream>

int main() {
   LList list;
	#ifndef NDEBUG
   list.dumpNodesArray();
	#endif
   list.cons('c');
   std::cout << "Cons \'c\' as first element\n";
	#ifndef NDEBUG
   list.dumpNodesArray();
	#endif
   std::cout << "\n";
   list.cons('c');
   list.cons('c');
   list.cons('d');
   list.cons('d');
   list.cons('d');
	#ifndef NDEBUG
   list.dumpNodesArray();
	#endif
   list.remove('c');
   std::cout << "Removing \'c\' (Expect element 2 to become free)\n";
	#ifndef NDEBUG
   list.dumpNodesArray();
	#endif
   std::cout << "\n";
   list.cons('d');
   list.cons('a');
   list.cons('r');
	#ifndef NDEBUG
   list.dumpNodesArray();
	#endif
   list.append('g');
   std::cout << "Appending \'g\'\n";
	#ifndef NDEBUG
   list.dumpNodesArray();
	#endif
   std::cout << "\n";
   std::cout << "Trying to find \'r\' (Expect true): "<< list.search('r') << '\n';
   std::cout << "Trying to find \'f\' (Expect false): " << list.search('f') << '\n';

   LList list2 = list;
   std::cout << "\nPrinting list: \n";
   std::cout << list.toString() << '\n';
   std::cout << "Printing the copy of list: \n";
   std::cout << list2.toString() << '\n';
   std::cout << "End of program\n\n";
   #ifndef NDEBUG
   list.dumpNodesArray();
   #endif

   system("pause");
   return 0;
}
*/