#include "tree.h"
#include <vector>
#include <iostream>
using namespace std;
#include <stdexcept>

// Create a node with given information
IntTree::IntTree(int d){
    data = d;
}

//destructor of the IntTree class : to destroy memory space used by each component of the vector
IntTree::~IntTree(){
    for(std::vector<IntTree*>::iterator it = sons.begin(); it != sons.end(); it++){
        delete *it;
    }
}

// Return information of this node
int IntTree::getData(){
    return data;
}

// Set information of this node
void IntTree::setData(int d){
    data = d;
}

// Return the number of sons of this node
int IntTree::nbSons(){
    return (sons.size());
}

// Return the son at position pos, if any (considering left-most son is at position 0)
IntTree* IntTree::getSon(int pos){
    return (sons.at(pos));
}

// Replace the exisiting son at position pos with newSon (left-most son at position 0)
void IntTree::setSon(int pos, IntTree* newSon){
    sons.at(pos) = newSon;
}

// Add newSon as supplementary right-most son of this node
void IntTree::addAsLastSon(IntTree* newSon){
    sons.push_back(newSon);
}

// Remove right-most son of this node
void IntTree::removeLastSon(){
    if(sons.empty()){
         throw sons.size();
    }
    else{
        sons.pop_back();
    }
}


//Basic function to display the tree
void IntTree::display(){
    if (sons.empty()){
        throw sons.size();
    }
    else{
        cout << data << " ";
        for (int i = 0; i< nbSons(); i++){
            getSon(i)->display();
        }
    }
}
// Display the tree : recurrent function used to display the tree.
// We browse the tree with a function that takes the nod like a parameter

void IntTree::display(string prefix, string indent){
    if (sons.empty()){
        throw sons.size();
    }
    else{
        cout << prefix << indent << data << endl;
        indent = indent + " ";
        for (int i = 0; i<nbSons(); i++){
            getSon(i)->display(prefix, indent);
        }
    }
}

