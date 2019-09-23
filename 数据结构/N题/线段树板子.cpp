#include<iostream>
#include<algorithm>
using namespace std;
long long ans=0;
struct node
{
	long long l=0,r=0,sum=0,max=0,min=0;
	long long lazy = 0;
}tree[4000100];

void build(int l,int r,int k);
void range_view(int l, int r, int k);
void down(int k);
long long range_max(int l, int r, int k);
long long range_min(int l, int r, int k);
void addlazy(int l, int r, int K,int k);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q,o;
	int L, R, K;
	cin >> n >> q;
	build(1, n, 1);
	for (int i = 1; i <= q; i++)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> L >> R >> K;
			addlazy(L, R, K,1);
			continue;
		}
		if (o == 2)
		{
			cin >> L >> R;
			range_view(L,R,1);
			cout << ans<<endl;
			ans = 0;
			continue;
		}
		if (o == 3)
		{
			cin >> L >> R;
			cout << range_max(L, R, 1) - range_min(L, R, 1)<<endl;
			continue;
		}
	}
	return 0;
}

void build(int l, int r, int k)
{
	tree[k].l = l;
	tree[k].r = r;
	if (tree[k].l == tree[k].r)
	{
		tree[k].sum=0;
		tree[k].min = 0;
		tree[k].max = 0;
		return;
	}
	int m = (l + r) / 2;
	build(l, m, k << 1);
	build(m + 1, r, k << 1 | 1);
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
	tree[k].max = max(tree[k << 1].max, tree[k << 1 | 1].max);
	tree[k].min = min(tree[k << 1].min, tree[k << 1 | 1].min);
}

void range_view(int l, int r,int k)
{
	if (tree[k].l >= l && tree[k].r <= r)
	{
		ans += tree[k].sum;
		return;
	}
	if (tree[k].lazy) 
		down(k);
	int m = (tree[k].l+tree[k].r) / 2;
	if (l <= m) range_view(l,r,k<<1);
	if (r > m)  range_view(l,r,k << 1 | 1);
}

void down(int k)
{
	tree[k << 1].lazy += tree[k].lazy;
	tree[k << 1|1].lazy += tree[k].lazy;
	tree[k<<1].sum += tree[k].lazy * (tree[k<<1].r - tree[k<<1].l + 1);
	tree[k << 1|1].sum += tree[k].lazy * (tree[k << 1|1].r - tree[k << 1|1].l + 1);
	tree[k << 1].max += tree[k].lazy;
	tree[k << 1|1].max += tree[k].lazy;
	tree[k << 1].min += tree[k].lazy;
	tree[k << 1 | 1].min += tree[k].lazy;
	tree[k].lazy = 0;
}

void addlazy(int l, int r, int K, int k)
{
	if (tree[k].l >= l && tree[k].r <= r)
	{
		if (l == r)
		{
			tree[k].sum += K;
			tree[k].max += K;
			tree[k].min += K;
			return;
		}
		tree[k].lazy += K;
		tree[k].sum += K* (tree[k].r - tree[k].l + 1);
		tree[k].max += K;
		tree[k].min += K;
		return;
	}
	if (tree[k].lazy)
		down(k);
	int m = (tree[k].l + tree[k].r) / 2;
	if (l <= m) addlazy(l, r, K, k << 1);
	if (r > m) addlazy(l, r, K, k << 1 | 1);
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
	tree[k].max = max(tree[k << 1].max, tree[k << 1 | 1].max);
	tree[k].min = min(tree[k << 1].min, tree[k << 1 | 1].min);
}


long long range_max(int l, int r, int k)
{
	if (tree[k].l == l && tree[k].r == r)
	{
		return tree[k].max;
	}
	if (tree[k].lazy)
		down(k);
	int m = (tree[k].l + tree[k].r) / 2;
	if (r <= m) return range_max(l, r, k << 1);
	else if (l > m) return range_max(l, r, k << 1 | 1);
	else return max(range_max(l, m, k << 1), range_max(m+1, r, k << 1 | 1));
	
}

long long range_min(int l, int r, int k)
{
	if (tree[k].l == l && tree[k].r == r)
	{
		return tree[k].min;
	}
	
	if (tree[k].lazy)
		down(k);
	int m = (tree[k].l + tree[k].r) / 2;
	if (r <= m) return range_min(l, r, k << 1);
	else if (l > m) return range_min(l, r, k << 1 | 1);
	else return min(range_min(l, m, k << 1), range_min(m+1, r, k << 1 | 1));
}
