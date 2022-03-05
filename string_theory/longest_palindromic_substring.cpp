// define ctrl m to break infinite loop
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
#define vi vector<int>

int lps(string s)
{
	int n = s.length();
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		// odd length
		int l = i;
		int r = i;

		while (l >= 0 && r < n && s[l] == s[r])
		{
			int curL = r - l + 1;
			if (curL > max)
			{
				max = curL;
			}
			l--; r++;
		}
		// even length

		l = i;
		r = i + 1;

		while (l >= 0 && r < n && s[l] == s[r])
		{
			int curL = r - l + 1;
			if (curL > max)
			{
				max = curL;
			}
			l--; r++;
		}


	}
	return max;

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



	string s;
	cin >> s;

	int ans = lps(s);
	cout << ans << endl;

	return 0;
}
