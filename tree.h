#pragma once
#include <vector>
#include <iostream>
using namespace std;
#include <stdexcept>


class IntTree {
    // Node information
    int data;
    // Sequence of sons (empty if none)
    vector<IntTree*> sons;
public:
    // Create a node with given information
    IntTree(int d);
    // Destruct a node and all its descendants
    ~IntTree();
    // Return information of this node
    int getData();
    // Set information of this node
    void setData(int d);
    // Return the number of sons of this node
    int nbSons();
    // Return the son at position pos, if any (considering left-most son is at position 0)
    IntTree* getSon(int pos);
    // Replace the exisiting son at position pos with newSon (left-most son at position 0)
    void setSon(int pos, IntTree* newSon);
    // Add newSon as supplementary right-most son of this node
    void addAsLastSon(IntTree* newSon);
    // Remove right-most son of this node
    void removeLastSon();
    // Display the tree
    void display();
    // Display the tree with indents
    void display(string prefix, string indent = " ");
};



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
        if (sons.empty()){
            throw sons.size();
        }
        else{
            sons.pop_back();
        }
    };
    // Display the tree with indents
    void display(string prefix, string indent = " "){
        if (sons.empty()){
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
    // Insert extra son at position pos, if pos exists
    void insertSon(int pos, Tree<T>* son){
        if (pos<0 or pos>sons.size()-1){
            throw 0;
        }
        sons.insert(sons.begin()+pos,son);
    };

    // Remove son at position pos, thus reducing nbSons
    void removeSon(int pos){
        if (pos<0 or pos>sons.size()-1){
            throw 0;
        }
        sons.erase(sons.begin()+pos);
    };

};


class exception {
public:
    exception () throw();
    exception (const exception&) throw();
    exception& operator= (const exception&) throw();
    virtual ~exception() throw();
    virtual const char* what() const throw();
};

