#include "BST.h"

int main(int argc, char** argv)
{
    struct treeNode node;

    bstInsert(&node, 11, 11, NULL);
    bstInsert(&node, 7, 7, NULL);
    bstInsert(&node, 12, 12, NULL);
    bstInsert(&node, 9, 9, NULL);
    bstInsert(&node, 4, 4, NULL);
    showTree(&node, 4);
}

