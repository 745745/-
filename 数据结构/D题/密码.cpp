#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, k;
int tot=0;
deque<char>s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> k)
	{
		if (n == k && k == 0)
		{
			cout << endl;
			continue;
		}
		char a;
		cin >> a;
		s.push_front(a);
		for (int i = 1; i <= n-1; i++)
		{
			cin >> a;
			while (!s.empty() && a > s.back() &&tot<n-k)
			{
				s.pop_back();
				tot++;
			}
			s.push_back(a);
		}

		if (k == 0)
		{
			tot = 0;
			cout << endl;
		s.clear();
		continue; }
		else {
			for (int i = 1; i <= k; i++)
			{
				cout << s.front();
				s.pop_front();
			}
			cout << endl;
			s.clear();
			tot = 0;
		}
	}
}