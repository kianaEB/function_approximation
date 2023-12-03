#include "node.cpp"
#include "expressionTree.cpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    // expressionTree* trees = new expressionTree[1];
    // for(int i = 0; i < 1; ++i)
    // {
    //     trees[i].generateRandomTree();
    // }

    expressionTree tree;
    while(tree.getDepth(tree.getRoot()) < 3)
    {
        tree.insert(tree.randomOperandOrOperator());
    }
    tree.print(tree.getRoot());
    // std::cout << std::endl;
    // std:: cout << tree.getDepth(tree.getRoot());

}

