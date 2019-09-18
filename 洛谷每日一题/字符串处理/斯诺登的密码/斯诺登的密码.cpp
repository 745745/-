#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(string& a, string& b);

string A[27] = { "one","two","three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third" };
string B[27] = { "01","04", "09", "16", "25", "36", "49", "64", "81", "00", "21", "44", "69", "96", "25", "56", "89", "24", "61", "00","01","04","04","01","04","09" };
int main()
{
	int count = 0;
	string C[7];
	for (int i = 0; i < 6; i++)
	{
		string D;
		cin >> D;
		for (int j = 0; j < 27; j++)
		{
			if (D == A[j])
			{
				C[count] = B[j];
				count++;
				break;
			}
		}
	}
	if (!count)
	{
		cout << 0;
		return 0; 
	}
	sort(C, C + count-1, cmp);
	bool a = true;
	for (int i = 0; i < count; i++)
	{
		if (a && C[i] == "00")
			continue;
		else if ( a && C[i][0] == '0')
		{
			cout << C[i][1];
			a = false;
		}
		else
		{
			a = false;
			cout << C[i];
		}
	}
}

bool cmp(string& a, string& b)
{
	return a + b < b + a;
}
