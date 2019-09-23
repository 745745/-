#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int ans = -1000000001;
int num[1000010];
int nums[1000010];
int A[1000010];
int B[1000010];
int h[1000010] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	A[1] = 1;
	B[n] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		nums[n - i+1]=num[i];
	}
	int len = 1;
	h[0] = -1000000001;
	h[1] = num[1];
	for (int i = 2; i <= n; i++)
	{
		if (num[i] == h[len])
			A[i] = len;
		if (num[i] > h[len])
		{
			len++;
			h[len] = num[i];
			A[i] = len;
		}
		if (num[i] < h[len])
		{
			h[lower_bound(h , h + len+1, num[i]) - h] = num[i];
			//A[i] = lower_bound(h , h + len+1, num[i]) - h;
			A[i] = len;
		}

	}
	memset(h, 0, sizeof(h));
	len = 1;
	h[0] = -1000000001;
	h[1] = nums[1];
	for (int i = 2; i <= n; i++)
	{
		if (nums[i] == h[len])
			B[i] = len;
		if (nums[i] > h[len])
		{
			len++;
			h[len] = nums[i];
			B[i] = len;
		}
		if (nums[i] < h[len])
		{
			h[lower_bound(h, h + len + 1, nums[i]) - h] = nums[i];
			//B[i] = lower_bound(h, h + len + 1, nums[i]) - h;
			B[i] = len;
		}

	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(min(A[i], B[n-i+1]) * 2 - 1, ans);
	}
	cout << ans;
}