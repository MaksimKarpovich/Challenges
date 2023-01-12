#include"BST.h"

#define MAX_DIGITS 3

struct treeNode *bstFind(struct treeNode *node, KEY_TYPE key)
{

}

BinaryTreeStatus bstInsert(struct treeNode *node, KEY_TYPE key, VALUE_TYPE value)
{
    if(node->key == (KEY_TYPE)NULL)
    {
        node->leftNode = NULL;
        node->rightNode = NULL;
        node->key = key;
        node->value = value;
        return BINARY_TREE_OK;
    }

    if(node->key == key)
    {
        node->value = value;
        return BINARY_TREE_OK;
    }

    if(node->key < key)
    {
        bstInsert(node->rightNode, key, value);
        return BINARY_TREE_OK;
    }
    else {
        bstInsert(node->leftNode, key, value);
        return BINARY_TREE_OK;
    }

    return BINARY_TREE_ERROR;
}

BinaryTreeStatus bstRemove(struct treeNode *node, KEY_TYPE key)
{

}

static uint8_t CountNumbers(uint8_t number)
{
    if(number == 0)
        return 1;

    int count = 0;

    if(number < 0)
        count++;

    while (number != 0)
    {
        ++count;
        number /= 10;
    }

    return count;
}


static uint32_t numLines(uint32_t line);

static uint32_t numSpaces(uint32_t line)
{
    if(line == 0)
        return 0;

    uint32_t lines = numLines(line - 1);
    uint32_t res = (numSpaces(line - 1) + MAX_DIGITS + 1 + lines);
    return res;

}

static uint32_t numLines(uint32_t line)
{
    uint32_t spaces = numSpaces(line);

    int32_t res = (spaces - MAX_DIGITS - 3);
    if(res < 0)
        return 0;
    return res;
}

BinaryTreeStatus showTree(struct treeNode *node, uint8_t num)
{
    if(node->key == (KEY_TYPE)NULL)
    {
        printf("Error: Can not show empty tree\r\n");
        return BINARY_TREE_EMPTY;
    }

    if(num == 0)
    {
        printf("Error: Can not show 0 three nodes\r\n");
        return BINARY_TREE_ERROR;
    }

    for(int k = num; k > 0; k--)
    {
        for(uint8_t i = 0; i < numSpaces(k); i++)
            printf(" ");

        for(uint8_t i = 0; i < numLines(k); i++)
            printf("_");

        for(int i = 0; i < MAX_DIGITS; i++)
            printf("0");

        for(int i = 0; i < CountNumbers(node->key); i++)
            printf("\b");

        printf("%d", node->key);

        for(uint8_t i = 0; i < numLines(k); i++)
            printf("_");

        printf("\r\n");

        for(uint8_t i = 0; i < numSpaces(k) - 1; i++)
            printf(" ");

        printf("/");

        for(uint8_t i = 0; i < (numLines(k) * 2) + MAX_DIGITS; i++)
            printf(" ");

        printf("\\\r\n");
    }
}


