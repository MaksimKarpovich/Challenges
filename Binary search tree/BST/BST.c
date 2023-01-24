#include"BST.h"
#include <malloc.h>
#include <stdbool.h>

struct treeNode *bstFind(struct treeNode *node, KEY_TYPE key)
{
    if(node == NULL)
    {
        printf("The binary tree with the selected root does not contain a node with key %d\r\n", key);
        return NULL;
    }
    if(node->key == key)
        return node;
    else if(node->key < key)
        return bstFind(node->rightNode, key);
    else
        return bstFind(node->leftNode, key);
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

BinaryTreeStatus bstInternalRemove(struct treeNode *node, KEY_TYPE key, struct treeNode *parentNode, Direction direction)
{
    if(node == NULL)
    {
        printf("Could not remove node!\r\n");
        return BINARY_TREE_EMPTY;
    }

    if(node->key < key)
    {
        if(node->rightNode != NULL)
            return bstInternalRemove(node->rightNode, key, node, DIRECTION_RIGHT);
        else
        {
            printf("Could not remove node!\r\n");
            return BINARY_TREE_ERROR;
        }
    } else if(node->key > key)
    {
        if(node->leftNode != NULL)
            return bstInternalRemove(node->leftNode, key, node, DIRECTION_LEFT);
        else
        {
            printf("Could not remove node!\r\n");
            return BINARY_TREE_ERROR;
        }
    } else
    {
        if((node->leftNode == NULL) && (node->rightNode == NULL))
        {
            if(parentNode != NULL)
            {
                if(direction == DIRECTION_RIGHT)
                    parentNode->rightNode = NULL;
                if(direction == DIRECTION_LEFT)
                    parentNode->leftNode = NULL;
            }
            free(node);
            return BINARY_TREE_OK;
        }

        if((node->leftNode != NULL) && (node->rightNode == NULL))
        {
            node->key = node->leftNode->key;
            node->value = node->leftNode->value;
            struct treeNode* leftNodeTemp = node->leftNode;
            node->rightNode = node->leftNode->rightNode;
            node->leftNode = node->leftNode->leftNode;
            free(leftNodeTemp);
            return BINARY_TREE_OK;
        }

        if((node->leftNode == NULL) && (node->rightNode != NULL))
        {
            node->key = node->rightNode->key;
            node->value = node->rightNode->value;
            struct treeNode* rightNodeTemp = node->rightNode;
            node->rightNode = node->rightNode->rightNode;
            node->leftNode = node->rightNode->leftNode;
            free(rightNodeTemp);
            return BINARY_TREE_OK;
        }

        if((node->leftNode != NULL) && (node->rightNode != NULL))
        {
            if(node->rightNode->leftNode == NULL)
            {
                node->key = node->rightNode->key;
                node->value = node->rightNode->value;
                struct treeNode* rightNodeTemp = node->rightNode;
                node->rightNode = node->rightNode->rightNode;
                free(rightNodeTemp);
                return BINARY_TREE_OK;
            } else
            {
                struct treeNode internalNode = *node->rightNode;
                while(internalNode.leftNode != NULL)
                {
                    internalNode = *internalNode.leftNode;
                }
                node->value = internalNode.value;
                node->key = internalNode.key;
                free(internalNode.parentNode->leftNode);
                internalNode.parentNode->leftNode = NULL;
                return BINARY_TREE_OK;
            }
        }
    }
}
