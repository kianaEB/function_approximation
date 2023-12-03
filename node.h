#ifndef NODE_H
#define NODE_H
#include <string>

#pragma once

class node
{
    friend class expressionTree;
public:
    node(); 
    void setElement(std::string m) { element = m; }
    std::string getElement() const { return element; }
    ~node();
private:    
    std::string element;
    node* left;
    node* right;
    node* p;
};

#endif