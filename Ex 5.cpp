#include <stdio.h>
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
    ls->last->next = ls->first;
}
void elimination(list* ls, int k)
{
    node* p = ls->first;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    ls->last = p;
    node* del = p->next;
    ls->first = del->next;
    ls->last->next = ls->first;
    delete del;
}
int main()
{
    list players;
    list* p = &players;
    int n, k;
    scanf("%d%d", &n, &k);
    initialize(p, n);
    p = &players;
    while (n > 1)
    {
        elimination(p, k);
        n--;
    }
    node* x = p->first;
    printf("%d", x->data);
}