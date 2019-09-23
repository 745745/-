#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int n;
long long dp[1 << 18];
int enm[18];//击败敌人可获得的能力
int B[1<<18];//当前能力
string a[18];
string t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	for (int x = 1; x <= T; x++)
	{
		memset(dp, 0, sizeof(dp));
		memset(enm, 0, sizeof(enm));
		memset(B, 0, sizeof(B));
		cin >> n;
		cin >> t;
		for (int i = 1; i <= n; i++)
		{
			B[0] = B[0] | ((t[i - 1]-'0') << (i-1));
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			for (int j = 1; j <= n; j++)
				enm[i] = enm[i] | ((a[i][j - 1] - '0') << (j - 1));
		}
		for (int i = 1; i <= (1 << n) - 1; i++)
		{
			for (int j = 1; j <= n; j++)
				if (i & (1 << (j - 1)))
					B[i] =( B[i] | enm[j])|B[0];
		}
		dp[0] = 1;
		for (int s = 0; s <= (1 << n)-1; s++)
		{
			if (!dp[s])
				continue;
			for (int i = 1; i <=n; i++)
			{
				if (((s & (1 << (i - 1))) == 0) && (B[s] & (1 << (i - 1))))
				{
					dp[s | (1 << (i-1))] += dp[s];
				}
			}
		}
		cout << "Case " << x << ": " << dp[(1 << n) - 1] << endl;
		}
	}




