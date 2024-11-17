#include <stdio.h>
struct date {
    int day;
    int month;
    int year;
};

struct pseudo_folder {
    char name[10];
    int byte;
    date creation_date;
    pseudo_folder* next;
};

struct directory {
    pseudo_folder* first;
    pseudo_folder* last;
};

void init(directory* dir, int n)
{
    dir->first = dir->last = 0;
    while(n > 0)
    {
        pseudo_folder* fld = new pseudo_folder;
        fld->next = NULL;
        gets(fld->name);
        fflush(stdin);
        scanf("%d %d %d %d", &fld->creation_date.day, &fld->creation_date.month, &fld->creation_date.year, &fld->byte);
        getchar();
        if (dir->first == 0){
            dir->first = fld;
            dir->last = fld;
        }
        else
        {
            dir->last->next = fld;
            dir->last = fld;
        }
        n--;
    }
    dir->last->next = 0;
}

int sosanh(date a, date b)
{
    if (a.year > b.year) return 1;
    else if (a.year < b.year) return -1;
    else
    {
        if (a.month > b.month) return 1;
        else if (a.month < b.month) return -1;
        else
        {
            if (a.day > b.day) return 1;
            else if (a.day < b.day) return -1;
            else return 0;
        }
    }
}
void sort_size(directory* dir)
{
    pseudo_folder* p = 0;
    while (dir->first != 0)
    {
        pseudo_folder* i = dir->first;
        pseudo_folder** max = &dir->first;
        while (i->next != 0)
        {
            if (i->byte < (*max)->byte) max = &i->next;
            i = i->next;
        }
        pseudo_folder* temp = *max;
        *max = temp->next;
        temp->next = p;
        p = temp;
    }
    dir->first = dir->last = p;
    while (dir->last != 0 && dir->last->next != 0) dir->last = dir->last->next;
}

void del(directory* dir, int size)
{
    int sum = 0;
    while (sum < size || (dir->first != dir->last))
    {
        pseudo_folder* p = dir->first;
        dir->first = p->next;
        delete p;
    }
}

void print(directory* dir)
{
    pseudo_folder* p = dir->first;
    while (p != 0)
    {
        printf("This is file %s, with creation date %d/%d/%d, and size %d\n", p->name, p->creation_date.day, p->creation_date.month, p->creation_date.year, p->byte);
        p = p->next;
    }
}

int main() {
    directory folder;
    directory* fptr = &folder;
    int n;
    scanf("%d", &n);
    getchar();
    init(fptr, n);
    fptr = &folder;
    sort_size(fptr);
    fptr = &folder;
    int max;
    scanf("%d", &max);
    del(fptr, max);
    fptr = &folder;
    print(fptr);
    return 0;
}