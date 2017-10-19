#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employ.h"

int main() {
  TreeNode *root = NULL;
  char *name = (char *)malloc(40);
  char choice = 'x';

  while(choice != 'q') {
    printf("Please make your choice of the following:\n");
    printf("I. Insert Name\n");
    printf("D. Delete Name\n");
    printf("P. Print Names of Empolyees\n");
    printf("q. Exit the program\n");
    scanf("%s",&choice);

    if(choice == 'I') {
      printf("Please enter name of employee:\n");
      name = fgets(name, 40, stdin);
      root = Insert(root, name);
    }

    else if(choice == 'D') {
      printf("Please enter name of employee you like to delete:\n");
      name = fgets(name, 40, stdin);
      root = Delete(root, name);
    }

    else if(choice == 'P') {
      PrintNames(root);
    }
  }
}

  name = fgets(name, 40, stdin);
