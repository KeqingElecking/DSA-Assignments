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

void sort(list* ls)
{
    node* f = ls->first;
    while (f != 0)
    {
        node* max = f;
        node* g = f->next;
        while (g != 0)
        {
            if (g->data > max->data) max = g;
            g = g->next;
        }
        int temp = f->data;
        f->data = max->data;
        max->data = temp;
        f = f->next;
    }
}

void print(list* ls)
{
    node* p = ls->first;
    while (p != 0)
    {
        printf("%d", p->data);
        p = p->next;
    }
}

int main()
{
    list ls;
    list* ptr = &ls;
    initialize(ptr, 10);
    ptr = &ls;
    sort(ptr);
    ptr = &ls;
    print(ptr);
    system("pause");
}