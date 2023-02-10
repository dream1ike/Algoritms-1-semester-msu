#include <stdlib.h>
#include <stdio.h>
typedef struct list{
    int field;
    list* ptr;
}list;

list* init(int a)
{
    list* lst;
    lst = (list*)malloc(sizeof(list));
    lst->field = a;
    lst->ptr = NULL;
    return lst;
}
list* addelement (list *lst, int number)
{
    list *temp, *p;
    temp = (list*)malloc(sizeof(list));
    p = lst->ptr;
    lst->ptr = temp;
    temp->field = number;
    temp->ptr = p;
    return temp;
}
list* deleteelem(list *lst, list* root)
{
    list* temp;
    temp = root;
    while (temp->ptr != lst)
    {
        temp = temp->ptr;
    }
    temp->ptr = lst->ptr;
    free(lst);
    return temp;
}

list* deletehead(list* root)
{
    list* tmp;
    tmp = root->ptr;
    free(root);
    return tmp;
}

void listprint(list* lst)
{
    list* p;
    p = lst;
    do 
    {
        printf("%d ", p -> field);
        p = p->ptr;
    } while(p != NULL);
}

list* swap (list* lst1, list* lst2, list* head)
{
    list *prev1, *prev2, *next1, *next2;
    prev1 = head;
    prev2 = head;
    if (prev1 == lst1) prev1 = NULL;
    else
        while (prev1->ptr != lst1)
            prev1 = prev1->ptr;
    if (prev2 == lst2) prev2 = NULL;
    else    
        while(prev2->ptr != lst2)
            prev2 = prev2->ptr;
    next1 = lst1->ptr;
    next2 = lst2->ptr;
    if(lst2 == next1)
    {
        lst2->ptr = lst1;
        lst1->ptr = next2;
        if (lst1 != head)
            prev1->ptr = lst2;
    }
    else
        if (lst1 == next2)
        {
            lst1->ptr = lst2;
            lst2->ptr = next1;
            if (lst2 != head) prev2->ptr = lst2;
        }
        else
        {
            if (lst1 != head) prev1->ptr = lst2;
            lst2->ptr = next1;
            if(lst2 != head) prev2->ptr = lst1;
            lst1->ptr = next2;
        }
        if (lst1 == head) return lst2;
        if (lst2 == head) return lst1;
        return head;
}

int main(){
    list* lst = init(5);
    
    while (lst != NULL)
    {
        printf("elem = %d", lst ->field);
        lst = lst ->ptr;
    }
    
    return 0;
}