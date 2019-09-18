#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

char x[27];
string A, B,C;
bool noele(char* a, char b,int x);

int main()
{
	memset(x, 0, sizeof(x));
	cin >> A >> B >> C;
	for (int i = 0; i < A.length(); i++)
	{
		if (x[A[i] - 'A'] == B[i] || x[A[i] - 'A'] == NULL)
		{
			if(noele(x,B[i], A[i] - 'A'))
			x[A[i] - 'A'] = B[i];
			else
			{
				cout << "Failed";
				return 0;
			}
		}
		else
		{
			cout << "Failed";
			return 0;
		}
	}
	for (int i = 0; i <26; i++)
	{
		if (x[i] == NULL)
		{
			cout << "Failed";
			return 0;
		}
	}
	for (int i = 0; i < C.length(); i++)
	{
		if (x[C[i] - 'A'] == NULL)
		{
			cout << "Failed";
			return 0;
		}
	}
	for (int i = 0; i < C.length(); i++)
		cout << x[C[i] - 'A'];
}

bool noele(char* a, char b,int x)
{
	for (int i = 0; i < 26; i++)
	{
		if (a[i] == b&&i!=x)
			return false;
	}
	return true;
}