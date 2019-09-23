#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* A = new int[n + 1];
	int tot=0;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		tot += A[i];
	}
	int avg = tot / n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (A[i] > avg)
		{
			ans++;
			A[i + 1] += A[i] - avg;
		}
		if (A[i] < avg)
		{
			ans++;
			A[i + 1] -= avg - A[i];
		}
	}
	cout << ans;

}