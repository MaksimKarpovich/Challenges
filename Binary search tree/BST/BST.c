#include"BST.h"
#include <malloc.h>
#include <stdbool.h>

struct treeNode *bstFind(struct treeNode *node, KEY_TYPE key)
{

}

BinaryTreeStatus bstInternalInsert(struct treeNode *node, KEY_TYPE key, VALUE_TYPE value, struct treeNode *parentNode)
{
    node->parentNode = parentNode;

    if((node->parentNode == (KEY_TYPE)NULL) && (node->key == NULL))
    {
        node->parentNode = NULL;
        node->leftNode = NULL;
        node->rightNode = NULL;
        node->key = key;
        node->value = value;
        return BINARY_TREE_OK;
    }

    if((node->key == NULL))
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
        struct treeNode* rigthNode;
        rigthNode = malloc(sizeof(struct treeNode));
        if(node->rightNode == NULL)
            node->rightNode = rigthNode;
        bstInternalInsert(node->rightNode, key, value, node);
        return BINARY_TREE_OK;
    }
    else {
        struct treeNode* leftNode;
        leftNode = malloc(sizeof(struct treeNode));
        if(node->leftNode == NULL)
            node->leftNode = leftNode;
        bstInternalInsert(node->leftNode, key, value, node);
        return BINARY_TREE_OK;
    }

    return BINARY_TREE_ERROR;
}

BinaryTreeStatus bstRemove(struct treeNode *node, KEY_TYPE key)
{

}
