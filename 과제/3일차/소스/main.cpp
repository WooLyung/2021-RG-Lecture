#include <iostream>
#pragma warning disable(4996)
using namespace std;

int main()
{
	int n, m;
	int a = 0;
	int c = 0;
	cin >> n >> m;
	for (int i = n; i <= m; i++)
	{
		int b = 0;
		for (int j = 1; j <= i; j++)
			if (!(i % j)) b++;
		if (b == 2)
		{
			a += i;
			if (!c) c = i;
		}
	}
	if (a)
		cout << a << endl << c;
	else
		cout << -1;
}