#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
int red[510][510];
int black[510][510];
int dp[510][510];
int main()
{
	cin >> n >> m;
	int ans = 0;
	memset(red, 0, sizeof(red));
	memset(black, 0, sizeof(black));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) //红色向左
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			red[i][j] = red[i][j - 1] + x;
		}
	for (int i = 1; i <= n; i++)//黑色向上
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			black[i][j] = black[i-1][j] + x;
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i ][j-1] + black[i][j], dp[i-1][j] + red[i][j]);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	cout << ans;
}