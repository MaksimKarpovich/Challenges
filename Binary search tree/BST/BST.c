#include"BST.h"

struct treeNode *bstFind(struct treeNode node, KEY_TYPE key)
{

}

BinaryTreeStatus bstInsert(struct treeNode node, KEY_TYPE key, VALUE_TYPE value)
{
    if(node.key == (KEY_TYPE)NULL)
    {
        node.leftNode = NULL;
        node.rightNode = NULL;
        node.key = key;
        node.value = value;
        return BINARY_TREE_OK;
    }

    if(node.key == key)
    {
        node.value = value;
        return BINARY_TREE_OK;
    }

    if(node.key < key)
    {
        bstInsert(*node.rightNode, key, value);
        return BINARY_TREE_OK;
    }
    else {
        bstInsert(*node.leftNode, key, value);
        return BINARY_TREE_OK;
    }

    return BINARY_TREE_ERROR;
}

BinaryTreeStatus bstRemove(struct treeNode node, KEY_TYPE key)
{

}

BinaryTreeStatus showTree(struct treeNode node, uint8_t num)
{

}


