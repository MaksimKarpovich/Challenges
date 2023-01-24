#include "BST.h"
#include <stdbool.h>

BinaryTreeStatus addToNode(struct treeNode *node, char *sourceFileName)
{
    FILE *sourceFile;

    sourceFile = fopen(sourceFileName, "r");
    if(sourceFile == NULL)
    {
        printf("Can not open file %s\r\n", sourceFileName);
        return BINARY_TREE_ERROR;
    }

    KEY_TYPE key;
    VALUE_TYPE value;
    while(fscanf(sourceFile, "%hhu%d", &key, &value) != EOF)
        bstInsert(node, key, value);
}
