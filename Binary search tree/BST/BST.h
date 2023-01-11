#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define VALUE_TYPE int32_t
#define KEY_TYPE int32_t

struct treeNode
{
    struct treeNode *leftNode;
    struct treeNode *rightNode;
    KEY_TYPE key;
    VALUE_TYPE value;
};

struct treeNode *bstFind(struct treeNode node, KEY_TYPE key);
bool bstInsert(struct treeNode node, KEY_TYPE key, VALUE_TYPE value);
bool bstRemove(struct treeNode node, KEY_TYPE key);
bool showTree(struct treeNode node, uint8_t num);
