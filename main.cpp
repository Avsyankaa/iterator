#include "tree.hpp"
#include <iostream>

using namespace BSTree;

int main() {


    Tree<int> tree = {12,11,7,8,24,32,6,2,5,1,0,67,90};
	//tree.print_tree();

      auto it = tree.begin();
    std::cout << *it << std::endl;
    auto end = tree.end();
    for (; it != end; ++it ) {
         std::cout << *it << ' ';
    }



      std::cout << std::endl;

      auto rit = tree.rbegin();
      auto rend = tree.rend();
      for(; rit != rend; ++rit) {
        std::cout << *rit << ' ';
      }
       
      std::cout << std::endl; 
}

