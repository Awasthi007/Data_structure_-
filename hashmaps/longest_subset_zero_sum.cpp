Longest subset zero sum
Send Feedback
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
  
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
 #include<bits/stdc++.h>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) 
{
    // Write your code here
    unordered_map<int,int> mapp;
    mapp[0] = -1;
    long int sum = 0;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
       int temp=0;
       sum += arr[i];
       if(mapp.count(sum) > 0)
       {
           temp = i-mapp[sum];
           ans = max(temp,ans);
       }
        else
            mapp[sum] = i;
    }
    return ans;
}
  
