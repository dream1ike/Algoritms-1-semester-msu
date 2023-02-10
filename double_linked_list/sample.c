#include <stdlib.h>
#include <stdio.h>
typedef struct list
{
  double num; 
  list *next;
  list *prev; 
}list;

list* init(double a)
{
    list* lst = (list*)malloc(sizeof(list));
    lst -> prev = NULL;
    lst -> next = NULL;
    lst -> num = a;
    return lst;
}

list* addelem(list* lst, double a)
{
    list *new_lst, *temp;
    new_lst = (list*)malloc(sizeof(list));
    new_lst -> prev = lst;
    temp = lst -> next;
    new_lst -> next = temp;
    new_lst -> num = a;
    lst -> next = new_lst;
    if (temp != NULL) temp -> prev = new_lst;
    return new_lst;
}

list* deletelem(double a)
{
    
}

int main()
{
    return 0;
}