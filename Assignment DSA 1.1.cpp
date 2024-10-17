#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
			}
		}
	}	
}
int main()
{
	int n;
	cin >> n;
	cout << "Input sequence: 0 for red, 1 for white, 2 for blue" << endl;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		do
		{
			cin >> a[i];
			if (a[i] > 2 || a[i] < 0) cout << "Invalid Input" << endl;
		} while (a[i] > 2 || a[i] < 0);
	}
	sort(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) cout << "red ";
		else if (a[i] == 1) cout << "white ";
		else if (a[i] == 2) cout << "blue ";
	}
	cout << endl;
	system("pause");
}