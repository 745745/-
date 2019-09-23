#include<iostream>
#include<cstring>
using namespace std;
int dp[2][2000010];
int n, k;
int now;
int pre = 0;
int main()
{
	memset(dp, 0, sizeof(dp));
	long long ans = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	char* num = new char[n + 10];
	memset(num, 0, sizeof(num + 10));
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++) {
		now = pre ^ 1;
		int tt = num[i] - '0';
		dp[now][tt % k]++;
		for (int j = 0; j < k; j++) {
			dp[now][(j * 10 + tt) % k] += dp[pre][j];   //j�Ǳ�k�����������dp��һλ��ʱ����Ҫ*10,��������Ҳ*10����tt.
			dp[pre][j] = 0;
		}
		pre = now;
		ans += dp[now][0];
	}
	cout << ans;
	delete num;
}