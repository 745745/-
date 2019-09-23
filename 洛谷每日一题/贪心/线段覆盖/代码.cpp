#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
struct line
{
	int start;
	int end;
};

bool cmp(const line& a, const line& b)
{
	if (a.end != b.end)
		return a.end < b.end;
	else return a.start < b.start;
}
int main()
{
	int n;
	cin >> n;
	line* A = new line[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i].start >> A[i].end;
	}
	sort(A + 1, A + n + 1, cmp);
	int x = A[1].end;
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		if (A[i].start >= x)
		{
			ans++;
			x = A[i].end;
		}
		else continue;
	}
	cout << ans;
}