// define ctrl m to break infinite loop
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
#define vi vector<int>

void solve(string s, string p)
{
	int n = s.length();
	int m = p.length();

	for (int i = 0; i <= n - m; i++)
	{
		bool found = true;
		for (int j = 0; j < m; j++)
		{
			if (s[i + j] != p[j])
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout << "true" << endl;
			return;
		}
	}

	cout << "false" << endl;
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

	int t;
	cin >> t;

	while (t--)
	{
		string s, p;
		cin >> s;
		cin >> p;

		solve(s, p);
	}


	return 0;
}
