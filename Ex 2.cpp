#include <iostream>
using namespace std;

void no_man_year(int arr[], int n, int year_1st)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) cout << i << "; ";
        cnt++;
    }
    if (cnt == 0) cout << "No no man year";
}
int low_birth_cnt(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 10) cnt += arr[i];
    }
    return cnt;
}
int ppl_above_x(int arr[], int n, int milestn, int x, int year_1st)
{
    int cnt = 0;
    for (int i = 0; i < milestn - year_1st - x; i++)
    {
        cnt += arr[i];
    }
    return cnt;
}
int main()
{
    int first, last;
    do
    {
        cin >> first >> last;
        if (first > last) cout << "Invalid input" << endl;
    } while (first > last);
    int range = last - first + 1;
    int data[range];
    for (int i = 0; i < range; i++) cin >> data[i];
    int x, mile;
    cout << "Input limit age and milestone";
    cin >> x >> mile;
    no_man_year(data, range, first);
    cout << endl;
    cout << low_birth_cnt(data, range) << endl << ppl_above_x(data, range, mile, x, first) << endl;
    system("pause");
}