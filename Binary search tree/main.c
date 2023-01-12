#include "BST.h"

int main(int argc, char** argv)
{
    struct treeNode node;

    bstInsert(&node, 11, 11);
    showTree(&node, 4);
    printf("\r\n");
}

