#include "expressionTree.h"
#include "node.h"
#include <string>
#include <vector>
#include <iostream>

expressionTree::expressionTree()
              :root(nullptr)  
{

}

void expressionTree::insert(std::string leaf)
{

    node* add = new node;
    add->setElement(leaf); 
    if (root == nullptr) {
        root = add;
        add->p = nullptr;
        add->left = nullptr;
    }
    else {
        node* lastOperatorLeaf = getOperatorLeafNode(root);
        if (lastOperatorLeaf != NULL) 
        {
            if (lastOperatorLeaf->left == NULL) 
            {
                lastOperatorLeaf->left = add;
                add->p = lastOperatorLeaf;
            }
            else
                if (lastOperatorLeaf->right == NULL) 
                {
                    lastOperatorLeaf->right = add;
                    add->p = lastOperatorLeaf;
                }
        }
    }    
}

int expressionTree::getDepth(node* node)
{
    // if (node == nullptr)
    //     return 0;
    // else{
    //     int lDepth = getDepth(node->left);
    //     int rDepth = getDepth(node->right);

    //     if (lDepth > rDepth)
    //         return(lDepth + 1);
    //     else return(rDepth + 1);
    // }

   if(!node)
        return 0;
    else
        return 1 + std::max(getDepth(node->left), getDepth(node->right));     
}

bool expressionTree::isOperator(std::string op)
{
    if(op == "+" || op == "-" || op == "*"
    || op == "^" || op == "/")    
        return true;
    else
        return false;    
}

node* expressionTree::getOperatorLeafNode(node* root)
{
    node* res = nullptr;
    if (root == nullptr)
        return nullptr;
    else if (isOperator(root->element)) 
    {
        if (root->left == NULL || root->right == NULL)
            return root;
        if(root->left != NULL)
            res = getOperatorLeafNode(root->left);
        if (res == NULL && root->right != NULL)
            res = getOperatorLeafNode(root->right);
    }
    return res;    
}

std::string expressionTree::randomOperandOrOperator(int temp)
{
    std::string operators[5] = {"+", "-", "*", "^", "/"};
     std::string operands [25] = {"-10", "-9", "-8", "-7", "-6", "-5", "-4", "-3", "-2", "-1", "0",
                                         "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Sin(x)", "Cos(x)", "x", "y"};
    if(temp == 1)
    {
        return operands[rand() % (sizeof(operands)/ sizeof(std::string))];
    }
    
    int percentage = rand() % 100 + 1;
    if (percentage >= 50) 
    {
        return operands[rand() % (sizeof(operands)/ sizeof(std::string))];
    }
    else 
    {
        return operators[rand() % (sizeof(operators)/ sizeof(std::string))];
    }                                     
}

void expressionTree::print(node* root)
{
   if (root != NULL)
    {
      if (isOperator(root->element) || isdigit(root->element[0]))
            std::cout << "(";
      print(root->left);
      std::cout << root->element;
      print(root->right);
      if (isOperator(root->element) || isdigit(root->element[0]))
            std::cout << ")";
    }    
}

void expressionTree::isValidExpression(node* node, bool& check)
{
    if(node)
    {
        if(isOperator(node->element) && (node->left == nullptr || node->right == nullptr))
            check = false;        
        isValidExpression(node->left, check);
        isValidExpression(node->right, check);    
    }   
}

void expressionTree::generateRandomTree()
{    
    int maxDepth = rand()% 5 +1;
    bool check = false;
    if(maxDepth == 1)
    {
        this->insert(randomOperandOrOperator(1));
    }
    else
    {
            while(this->getDepth(this->getRoot()) < maxDepth)
        {
            this->insert(randomOperandOrOperator());
        }
        // this->isValidExpression(this->getRoot(), check);
        // while(!check)
        // {
        //     this->insert(randomOperandOrOperator(1));
        //     this->isValidExpression(this->getRoot(), check);
        // }
    }
}

expressionTree::~expressionTree()
{

}