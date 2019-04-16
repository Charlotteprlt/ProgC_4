#pragma once
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Tree {
private :
    // Node information
    T data;
    // Sequence of sons (empty if none)
    vector<Tree<T>*> sons;
public:
    // Create a node with given information
    Tree<T>(T d){
        data = d;
    };
    // Destruct a node and all its descendants
    ~Tree<T>(){
        for(typename std::vector<Tree<T>*>::iterator it = sons.begin(); it != sons.end(); it++){
            delete *it;
        }
    }
    // Return the information of this node
    T getData(){
        return data;
    };
    // Set information of this node
    void setData(T d){
        data = d;
    };
    // Return the number of sons of this node
    int nbSons(){
        return sons.size();
    };
    // Return the son at position pos, if any (considering left-most son is at position 0)
    Tree<T>* getSon(int pos){
        return sons.at(pos);
    };
    // Replace the exisiting son at position pos with newSon (left-most son at position 0)
    void setSon(int pos, Tree<T>* newSon){
        sons.at(pos)=newSon;
    };
    // Add newSon as supplementary right-most son of this node
    void addAsLastSon(Tree<T>* newSon){
        sons.push_back(newSon);
    };
    // Remove right-most son of this node
    void removeLastSon(){
        if (!sons.empty()){
            sons.pop_back();
        }
    };
    // Display the tree with indents
    void display(string prefix, string indent = " "){
        if (nbSons() == 0){
            cout << prefix << indent << data << endl;
        }
        else{
            cout << prefix << indent << data << endl;
            indent = indent + " ";
            for (int i = 0; i<nbSons(); i++){
                getSon(i)->display(prefix, indent);
            }
        }
    };
};




