#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAXQUEUE 10

struct gross 
{
    int price;
    char things[10];
    char name[20];
};

struct customer {
    gross who;          
    customer* next;
};

struct queue {
    customer* first;
    customer* last;
    int size;
};

void init(queue* qq)
{
    (*qq).first = (*qq).last = 0;
    qq->size = 0;
}

void add(queue* qq, customer x)
{
    customer* ptr = qq->first; 
    while (ptr != 0)
    {
        ptr = (*ptr).next;
    }
    customer* cus = (customer*) malloc(sizeof(customer));
    cus->who.price = x.who.price;
    strcmp(x.who.things, cus->who.things);
    strcmp(x.who.name, cus->who.name);
    if (qq->first = 0) qq->first = qq->last = cus;
    else {
        ptr->next = cus;
        qq->last = cus;
        cus->next = 0;
    }
    qq->size++;
}

void del(queue* qq)
{
    customer* ptr = (*qq).first;
    qq->first = ptr->next;
    free(ptr);
    qq->size--;
}

int full(queue* qq)
{
    if(qq->size < MAXQUEUE) return 0;
    return 1;
}

int empty(queue* qq)
{
    if ((*qq).first = (*qq).last) return 1;
    return 0;
}

int main()
{
    queue qq;
    init(&qq);
    printf("%d", empty(&qq));
}