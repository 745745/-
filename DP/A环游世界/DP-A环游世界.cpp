#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n, s;
long long ans = 9223372036854775807;
struct p 
{
	int x;
	int y;
}d[20];
long long  dp[1<<19][19];
int  dis[20][20];

int main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i].x >> d[i].y;
	}
	for(int i=1;i<=n;i++)  //从第i个点到第j个点的距离
		for (int j = 1; j <= n; j++)
		{
			dis[i][j] = abs(d[i].x - d[j].x) +(abs(d[i].y - d[j].y));
			dis[j][i] = dis[i][j];
		}

	for (int a = 1; a <= (1 << n) - 1; a++)
	{
		for (int i = 1; i <= n; i++)
		{
			int x = 1 << (i - 1);
			if (a & x)
			{
				if (a == x)
					dp[a][i] = dis[s][i];
				else
				{
					dp[a][i] = 9223372036854775807;
					for (int j = 1; j <= n; j++)
						if (j != i && a&(1 << (j - 1)))
							dp[a][i] = min(dp[a][i] , dp[a ^ (1 << (i - 1))][j]+dis[j][i] );
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[(1 << n) - 1][i]);
	cout << ans;
}

