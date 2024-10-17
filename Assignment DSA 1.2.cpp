#include <iostream>
#include <cmath>
using namespace std;
bool findBlum (int n)
{
	if (n <= 1) return false;
	int cnt = 0;
	for (int i = 2; i < n; i++)
	{
		while (n % i == 0)
		{
			n /= i;
			cnt++;
		}
		if (cnt > 2) return false;
	}
	if (n > 1) cnt++;
	if (cnt == 2) return true;
	return false;
}
bool binary (int l, int r, int arr[], int targ)
{
	if (l >= r) return false;
	int half = l + (r - l) / 2;
	if (arr[half] == targ) return true;
	if (arr[half] < targ)
	{
		return binary(half + 1, r, arr, targ);
	}
	else
	{
		return binary(l, half, arr, targ);
	}
}
void sumblum (int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (binary(0, n, arr, arr[i] + arr[j])) cout << "[" << arr[i] << "; " << arr[j] << "]" << endl;
		}
	}
}
int main()
{
	int N;
	cin >> N;
	int arr[N], flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (findBlum(i))
		{
			cout << i << " : ";
			arr[flag] = i;
			flag++;
		}
	}
	cout << endl;
	sumblum(arr, flag - 1);
	int x;
	do
	{
		cin >> x;
	} while (findBlum(x) != 0);
	if (x < N) cout << "Ton tai " << x << " trong day";
	else cout << "Khong ton tai";
	system("pause");
}