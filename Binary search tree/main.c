#include "BST_Show.h"
#include "BST.h"

int main(int argc, char** argv)
{
    struct treeNode node;

    bstInsert(&node, 11, 11);
    bstInsert(&node, 7, 7);
    bstInsert(&node, 12, 12);
    bstInsert(&node, 9, 9);
    bstInsert(&node, 4, 4);
    showTree(&node, 4);

    struct treeNode * nodeFind = bstFind(&node, 71);
    if(nodeFind != NULL)
        printf("Adress of finden node = 0x%x\r\n", nodeFind);
}

