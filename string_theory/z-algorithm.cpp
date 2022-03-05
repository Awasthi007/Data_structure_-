// define ctrl m to break infinite loop
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
#define vi vector<int>

void buildZ(int* Z, string str)
{
	int l = 0;
	int r = 0;

	int n = str.length();

	for (int i = 1; i < n; i++)
	{
		if (i > r)
		{
			// i does not lie between l and r
			// Z for this doesn't exist
			l = i;
			r = i;

			while (r < n && str[r - l] == str[r])
			{
				r++;
			}
			Z[i] = r - l;
			r--;

		}
		else
		{
			int k = i - l;
			if (Z[k] <= r - i)
			{
				//it lies between l and r
				// Z will exist previously
				Z[i] = Z[k];
			}
			else
			{
				// some part of Z is exactly included we have to start matching further.

				l = i;
				while (r < n && str[r - l] == str[r])
				{
					r++;
				}
				Z[i] = r - l;
				r--;
			}
		}
	}
}




void stringSearch(string text, string pattern)
{
	string str = pattern + "$" + text;
	int n = str.length();

	int* Z = new int[n]();

	buildZ(Z, str);

	for (int i = 0; i < n; i++)
	{
		if (Z[i] == pattern.length())
		{
			cout << i - pattern.length() - 1 << endl;
		}
	}
	return;
}



int main()
{


#ifndef ONLINE_JUDGE
	//for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
	//for getting output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string text, pattern;
	cin >> text;
	cin >> pattern;
	stringSearch(text, pattern);



	return 0;
}
