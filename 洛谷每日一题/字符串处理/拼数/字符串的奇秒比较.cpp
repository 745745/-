#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string& a, string& b)
{
	return a + b > b + a;
}


int main()
{
	string A[21];
	string b;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	sort(A + 1, A + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		cout << A[i];
	}
}