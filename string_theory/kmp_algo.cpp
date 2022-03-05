String Search
Send Feedback
You are given an string S and a test string T. You have to find whether string S is a substring of the string T.
Input Format:
First line of input will contain an integer T, representing the number of test cases
Each test case is as follows:
Line 1: contains the string S.
Line 2: contains the string T.
Constraints:
1 <= T <= 100
1 <= |S|, |T| <= 10^5
Output Format:
For each test case print "Yes" if S is present in T or "No" otherwise.
Sample Input 1:
2
ye
wnpnzijdi
ao
jaoalc
Sample Output 1:
No
Yes


||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


#include<bits/stdc++.h>
using namespace std;

int* getlps(string pattern)
{
    int len = pattern.length();
    int* lps = new int[len];
    
    int i=1,j=0;
    
    lps[0] = 0;
    
    while(i < len)
    {
        if(pattern[i] == pattern[j])
        {
            lps[i] = j+1;
            i++;j++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string text, string pattern)
{
    int textlen = text.length();
    int patlen = pattern.length();
    
    int i=0,j=0;
    int* lps = getlps(pattern);
    
    while(i < textlen && j < patlen)
    {
        if(text[i] == pattern[j])
        {
            i++;j++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    
    if( j == patlen)
    {
        return true;
    }
    return false;
}




int main()
{
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        
        bool temp = kmp(t,s);
        if(temp)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
