#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employ.h"

int main() {
  TreeNode *root = NULL;
  char *name = (char *)malloc(100);
  //char choice = 'x';
  // char *choice = (char *)malloc(100);
  char choice[100] = "x";

  while(strcmp(choice,"q") != 0) {
    printf("Please make your choice of the following:\n");
    printf("I. Insert Name\n");
    printf("D. Delete Name\n");
    printf("P. Print Names of Empolyees\n");
    printf("q. Exit the program\n");
    // choice = fgets(choice, 100, stdin);
    scanf("%s",choice);
    int ret;
    ret = strcmp(choice,"I");
    printf("Strcmp %d\n%s\n",ret,choice);

    if(strcmp(choice,"I") == 0) {
      printf("Please enter name of employee:\n");
      //fgets(name, 100, stdin);
      scanf("%s",name);
      root = Insert(root, name);
    }

    else if(strcmp(choice,"D") == 0) {
      printf("Please enter name of employee you like to delete:\n");
      //fgets(name, 100, stdin);
      scanf("%s",name);
      root = Delete(root, name);
    }

    else if(strcmp(choice,"P") == 0) {
      PrintNames(root);
    }
  }
}

// name = fgets(name, 40, stdin);
