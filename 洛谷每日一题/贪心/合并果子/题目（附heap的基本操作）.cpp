#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class heap //Ð¡¸ù¶Ñ
{	
private:
	int n;
	int* A;
public:
	int p;
	void insert(int x);
	void up(int x);
	void down(int x);
	void pop();
	int top();
	heap(int x);
	~heap();
};

void heap::insert(int x)
{
	p++;
	A[p] = x;
	up(p);
}

void heap::up(int x)
{
	while (x / 2 >= 1)
	{
		if (A[x] < A[x / 2])
		{
			swap(A[x], A[x / 2]);
			x /= 2;
		}
		else break;
	}
}

void heap::down(int x)
{
	while (x * 2 <= p)
	{
		int y = x * 2;
		if (A[y] > A[y + 1]&&y+1<=n)
			y = y + 1;
		if (A[x] > A[y])
		{
			swap(A[x], A[y]);
			x = y;
		}
		else break;
	}
}

void heap::pop()
{
	if (p > 0)
	{
		A[1] = A[p];
		p--;
		down(1);
	}
	else 
	{
		cout << "empty heap\n";
		return;
	}
}

int heap::top()
{
	return A[1];
}

heap::heap(int x)
{
	n = x;
	A = new int[n+1];
	A[0] = 0;
	p = 0;
}

heap::~heap()
{
	delete[]A;
}


int main()
{
	int x,y;
	cin >> x;
	long long ans = 0;
	heap q(x);
	for (int i = 1; i <= x; i++)
	{
		cin >> y;
		q.insert(y);
	}
	while (q.p!=1)
	{
		long long a=0;
		a += q.top();
		q.pop();
		a += q.top();
		q.pop();
		ans += a;
		q.insert(a);
	}
	cout << ans;
}