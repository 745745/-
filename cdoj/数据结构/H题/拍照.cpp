#include<queue>
#include <iostream>
#include<algorithm>
using namespace std;
typedef long long  ll;
struct total
{
	ll x;//x是其值
	int y;//y为其位置
}p[100010];
int n, m;
ll a;
ll sum[100010] = { 0 };
ll max(ll x, ll y);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		sum[i] = sum[i - 1] + a;
		p[i].x = sum[i];
		p[i].y = i;
	}
	deque <total> b;
	b.push_back({ 0,0 });
	ll ans = p[1].x;
	for (int i = 1; i <= n; i++)
	{
		while (!b.empty() && p[i].y - b.front().y > m)
		{
			b.pop_front();
		}
		if (!b.empty() && p[i].x > b.back().x)
		{
			b.push_back(p[i]);
		}
		else {
			while (!b.empty() && p[i].x < b.back().x)
				b.pop_back();
			b.push_back(p[i]);
		}
		if (b.size() != 1)
			ans = max(ans, (b.back().x) - (b.front().x));
		else ans = max(ans, b.back().x);
	}
	cout << ans;
	return 0;

}

ll max(ll x, ll y)
{
	if (x > y)
		return x;
	else return y;
}