#ifndef EMPLOY_H
#define EMPLOY_H
#include <stdio.h>

/*binary tree structure*/
typedef struct TreeNode {
  char *name;
  struct TreeNode *lchild;
  struct TreeNode *rchild;
}TreeNode;

TreeNode *Insert(TreeNode *Tree, char *name);

TreeNode *Delete(TreeNode *Tree, char *name);

TreeNode *FindMin(TreeNode *Tree);

void PrintNames(TreeNode *Tree);

#endif

