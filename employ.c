#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employ.h"
s
/*Inserts a new name into the binary search tree*/
TreeNode *Insert(TreeNode *Tree, char *name) {
  if(Tree==NULL) {
    TreeNode *temp;
    temp = (TreeNode *)malloc(2*sizeof(TreeNode));
    temp->name = name;
    temp->lchild = temp->rchild = NULL;
    return temp;
  }

  if(strcmp(name,Tree->name) > 0) {     //Places a name down the right of tree
    Tree = Insert(Tree->rchild,name);
  }

  else if(strcmp(name,Tree->name) < 0) {     //Places a name down left side
    Tree = Insert(Tree->lchild,name);
  }
  return Tree;
}

/*Deletes a name from the list*/
TreeNode *Delete(TreeNode *Tree, char *name) {
  TreeNode *temp;
  if(Tree==NULL) {
    printf("Unable to find employee");
  }

  else if(strcmp(name,Tree->name) < 0) {     //checks to see if name is in node
    Tree->lchild = Delete(Tree->lchild,name);
  }

  else if(strcmp(name,Tree->name) > 0) {     //checks to see if name is in node
    Tree->rchild = Delete(Tree->rchild,name);
  }

  else {     //now the name can be removed since this is the node
    
    if(Tree->rchild && Tree->lchild) {
      temp = FindMin(Tree->rchild);
      Tree->name = temp->name;
      Tree->rchild = Delete(Tree->rchild,temp->name);
    }

    else {
      temp = Tree;
      if(Tree->lchild == NULL)
	Tree = Tree->rchild;
      else if(Tree->rchild == NULL)
	Tree = Tree->lchild;
      free(temp);
    }
  }
  return Tree;
      
}

/*supports the delete method by replacing the current node with a child node*/
TreeNode *FindMin(TreeNode *Tree) {
  if(Tree==NULL) {
    return NULL;
  }

  if(Tree->lchild) {
    return FindMin(Tree->lchild);
  }

  else {
    return Tree;
  }
}

/*prints out all the names of the employees*/
void PrintNames(TreeNode *Tree) {
  if(Tree==NULL) {
    return;
  }

  PrintNames(Tree->lchild);
  printf("%s\n ", Tree->name);
  PrintNames(Tree->rchild);
}
