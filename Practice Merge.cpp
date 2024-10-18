#include <iostream>
using namespace std;
void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    int arr1[N], arr2[M], merge[N + M];
    input(arr1, N);
    input(arr2, M);
    int i = 0, j = 0, flag = 0;
    while (i < N && j < M)
    {
        if (arr1[i] < arr2[j])
        {
            merge[flag] = arr1[i];
            i++;
        }
        else
        {
            merge[flag] = arr2[j];
            j++;
        }
        flag++;
    }
    if (i == N)
    {
        while (flag < N + M)
        {
            merge[flag] = arr2[j];
            j++;
            flag++;
        }
    }
    else if (j == M)
    {
        while (flag < N + M)
        {
            merge[flag] = arr1[i];
            i++;
            flag++;
        }
    }
    else cout << "FATAL ERROR" << endl;
    for (int i = 0; i < N + M; i++) cout << merge[i] << ":";
    system("pause");
}