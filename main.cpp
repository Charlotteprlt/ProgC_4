#include "tree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;
#include <stdexcept>
#include <math.h>

//Premiers exercices d'affichage d'un arbre
//int main(){
//    Tree<int>* root = new Tree<int>(12);
//    root->addAsLastSon(new Tree<int>(8));
//    root->getSon(0)->addAsLastSon(new Tree<int>(4));
//    root->getSon(0)->addAsLastSon(new Tree<int>(9));
//    root->addAsLastSon(new Tree<int>(23));
//    root->getSon(1)->addAsLastSon(new Tree<int>(17));
//    root->getSon(1)->getSon(0)->addAsLastSon(new Tree<int>(15));
//    root->display();
//    root->display("*", " ");
//    return 0;
//}


//tests d'erreurs
int main(){
    try{
        IntTree* errtree= new IntTree(9);
        errtree->removeLastSon();
        IntTree* root_1 = new IntTree(10);
        root_1->addAsLastSon(new IntTree(9));
        root_1->getSon(0)->addAsLastSon(new IntTree(12));
        root_1->getSon(0)->addAsLastSon(new IntTree(28));
        root_1->addAsLastSon(new IntTree(3));
        root_1->getSon(1)->addAsLastSon(new IntTree(10));
        root_1->getSon(1)->getSon(0)->addAsLastSon(new IntTree(19));
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Range error: " << oor.what() << '\n';
    }
    catch(unsigned int exn)
    {
        std::cerr  << "Empty vector" << endl;
    }
    catch(const int a)
    {
        std::cerr << "Out of range of the vector" << endl;
    }
    catch (const std::length_error& le) {
          std::cerr << "Length error: " << le.what() << '\n';
      }
    return 0;
}
