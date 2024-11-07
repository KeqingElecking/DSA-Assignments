#include <iostream>
using namespace std;
struct sohang{
    int heso;
    int bac;
};
struct node{
    sohang data;
    node *next;
};
struct list{
    node *first;
    node *last;
};
void dathuc (list* ls, int bac)
{
    int i = 0;
    while (i < bac + 1)
    {
        node* newnode = new node;
        int x, S = 1;
        cin >> x;
        for (int j = 0; j <= i; j++) S *= x;
        newnode->data.heso = S;
        newnode->data.bac = i;
        newnode->next = 0;
        if (ls->first == 0) ls->first = ls->last = newnode;
        else
        {
            ls->last->next = newnode;
            ls->last = newnode;
        }
        i++;
    }
}
int sum(list* ls){
    node* p = ls->first;
    int S = 0;
    while(p != 0)
    {
        S += p->data.heso;
        p = p->next;
    }
    return S;
}
int main()
{
    list ls;
    list ls2;
    list *init = &ls;
    init->first = init->last = 0;
    list *init2 = &ls2;
    init2->first = init2->last = 0;
    int bac;
    cin >> bac;
    dathuc(init, bac);
    int bac2;
    cin >> bac2;
    dathuc(init2, bac2);
    cout << sum(init) + sum(init2);
    system("pause");
}