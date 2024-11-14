#include <iostream>
#include <string.h>
using namespace std;
struct word{
    char wrd[10];
    word *next;
};
struct sentence{
    word *first;
    word *last;
};

void initialize(sentence* sen)
{
    sen->first = sen->last = 0;
    char buff;
    while (1)
    {
        std::cin >> std::noskipws >> buff;  // Read the character, not skipping whitespace
        if (buff == '\n') {
            break;  // Stop loop if Enter key is detected
        }
        std::cin.putback(buff); 

        word* p = new word;
        scanf("%s", &p->wrd);
        p->next = 0;
        if (sen->first == 0) sen->first = sen->last = p;
        else
        {
            sen->last->next = p;
            sen->last = p;
        }
    }
}

void most_used(sentence* sen, int &total, int &maxi)
{
    word* p = sen->first;
    char max[10];
    int cnt = 0;
    int cmax = 0;
    int tol = 0;
    strcpy(max, p->wrd);
    while(p != 0)
    {
        if (strcmp(p->wrd, max) == 0)
        {
            cnt++;
            if (cnt > cmax) 
            {
                strcpy(max, p->wrd);
                cmax = cnt;
            }
        }
        else
        {
            cnt = 1;
        }
        tol++;
        p = p->next;
    }
    total = tol;
    maxi = cmax;
}

void elimination(sentence* sen)
{

}

int main(){
    sentence x;
    sentence* xptr = &x;
    initialize(xptr);
    xptr = &x;
    int total, max;
    most_used(xptr, total, max);
    cout << total << max;
    system("pause");
    return 0;
}