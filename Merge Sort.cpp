#include <iostream>
using namespace std;
void merge (int arr[], int l, int r, int m)
{
    int i = l;
    int j = m + 1;
    while (i < j && j <= r)
    {
        if (arr[i] <= arr[j]) i++;
        else
        {
            int temp = arr[j];
            for (int k = j; k > i; k--)
            {
                arr[k] = arr[k - 1];
            }
            arr[i] = temp;
            i++; j++; m++;
        }
    }
}
void spilt(int arr[], int l, int r)
{
    if (l >= r) return;
    int m = (l + r) / 2;
    spilt(arr, l, m);
    spilt(arr, m + 1, r);
    merge(arr, l, r, m);
}
void mergesort(int arr[], int n)
{
    if (n < 2) return;
    spilt(arr, 0, n - 1);
}
int main()
{
    int arr[] = {240, 51, 73, 101, 21, 13, 25, 11, 37, 89, 30 ,15};
    mergesort(arr, 12);
    for (int i = 0; i < 12; i++) cout << arr[i] << ":";
    cout << endl;
    system("pause");
}