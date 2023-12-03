#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include "node.h"
#include<string>

#pragma once

class expressionTree
{
public:
    expressionTree();
    void insert(std::string);
    int getDepth(node*);
    void print(node*);
    node* getRoot() {return root;}
    void isValidExpression(node*, bool&);
    bool isOperator(std::string);
    node* getOperatorLeafNode(node*); 
    std::string randomOperandOrOperator(int = 0); 
    void generateRandomTree();  
    ~expressionTree();

private:
node* root;

};

#endif