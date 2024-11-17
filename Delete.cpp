#include <stdio.h>
#include <iostream>

using namespace std;
struct node{
    int data;
    node *next;
};

struct list{
    node *first;
    node *last;
};

void initialize(list* ls, int n)
{
    ls->first = ls->last = 0;
    int i = 1;
    while (i <= n)
    {
        node* p = new node;
        p->data = i;
        if (ls->first == 0) ls->first = ls->last = p;
        else
        {
            ls->last->next = p;
            ls->last = p;
        }
        i++;
    }
    ls->last->next = 0;
}

void del_first(list* ls)
{
    node* p = ls->first;
    ls->first = p->next;
    delete p;
}

void del_last(list* ls)
{
    node* p = ls->first;
    node* q = ls->first;
    while ((p->next) != 0)
    {
        while (p->next != q) q = q->next;
        p = p->next;
    }
    q->next = 0;
    delete p;
}

void del_random(list* ls, int index)
{
    node* p = ls->first;
    node* q = ls->first;
    int i = 0;
    while (i < index)
    {
        while (p->next != q) q = q->next;
        p = p->next;
        i++;
    }
    q->next = 0;
    delete p;  
}

int main(){
    list ls;
    list* pls;
    initialize(pls, 20);
    pls = &ls;
    del_first(pls);
    pls = &ls;
    del_last(pls);
    pls = &ls;
    del_random(pls, 12);
}