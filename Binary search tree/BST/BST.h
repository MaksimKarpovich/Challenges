#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define VALUE_TYPE int32_t
#define KEY_TYPE int32_t

typedef enum {
    BINARY_TREE_OK,
    BINARY_TREE_EMPTY,
    BINARY_TREE_ERROR,

} BinaryTreeStatus;

struct treeNode
{
    struct treeNode* leftNode;
    struct treeNode* rightNode;
    struct treeNode* parentNode;
    KEY_TYPE key;
    VALUE_TYPE value;
};

struct treeNode *bstFind(struct treeNode *node, KEY_TYPE key);
BinaryTreeStatus bstInsert(struct treeNode *node, KEY_TYPE key, VALUE_TYPE value, struct treeNode *parentNode);
BinaryTreeStatus bstRemove(struct treeNode *node, KEY_TYPE key);
BinaryTreeStatus showTree(struct treeNode *node, uint8_t num);
