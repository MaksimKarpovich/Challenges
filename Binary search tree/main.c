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
    const uint8_t keyToRemove = 122;
//    bstRemove(&node, keyToRemove);
    printf("After remooving %d\r\n", keyToRemove);
    showTree(&node, 4);

}

