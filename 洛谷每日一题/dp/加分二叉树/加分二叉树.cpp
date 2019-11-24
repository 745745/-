#include<iostream>
using namespace std;
int dp[31][31];
int root[31][31];

int f(int l, int r);
void print(int l, int r);



int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= 30; j++)
		{
			dp[i][j] = -1;
			root[i][j] = 0;
		}
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i][i];
	}

	cout << f(1, n)<<endl;
	print(1,n);
}

int f(int l, int r)
{
	if (r < l)
		return 1;
	if (dp[l][r]!=-1)
		return dp[l][r];
	if (l == r)
		return dp[l][l];
	for (int i = l; i <= r; i++)
	{
		int x = f(l, i - 1) * f(i + 1, r) + dp[i][i];
		if (x > dp[l][r])
		{
			dp[l][r] = x;
			root[l][r] = i;
		}
	}
	return dp[l][r];
}

void print(int l, int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		cout << l;
		return;
	}
	cout << root[l][r];
	print(l, root[l][r]-1);
	print(root[l][r] + 1, r);
}

