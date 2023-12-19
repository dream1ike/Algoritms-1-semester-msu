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
    list* last_elem = lst;
    while (last_elem->next != NULL)
    {
        
    }
    
}

list* deletelem(double a)
{
    
}

int main()
{
    return 0;
}