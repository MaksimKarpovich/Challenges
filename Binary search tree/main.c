#include "BST_Show.h"
#include "BST.h"

int main(int argc, char** argv)
{
    struct treeNode node;

    bstInsert(&node, 11, 11);
    bstInsert(&node, 7, 7);
    bstInsert(&node, 16, 16);
    bstInsert(&node, 9, 9);
    bstInsert(&node, 4, 4);
    bstInsert(&node, 15, 15);
    bstInsert(&node, 14, 14);
    bstInsert(&node, 18, 18);
    bstInsert(&node, 17, 17);
    bstInsert(&node, 22, 22);

    showTree(&node, 4);
    const uint8_t keyToRemove = 16;
    bstRemove(&node, keyToRemove);
    printf("After removing node with key = %d\r\n", keyToRemove);
    showTree(&node, 4);

}

