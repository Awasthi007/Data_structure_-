Longest Consecutive Sequence
Send Feedback
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16

.................................................................................................................................................................
  ..................................................................................................................................................................
/*

#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
unordered_map<int, bool> visitedElements;
unordered_map<int, int> elementToIndexMapping;
for (int i = 0; i < n; i++) {
elementToIndexMapping[arr[i]] = i;
if (visitedElements.count(arr[i]) == 0) {
visitedElements[arr[i]] = true;
}
}
vector<int> longestSequence;
int globalMaxSequenceLength = 1;
int globalMinStartIndex = 0;
for (int i = 0; i < n; i++) {
int num = arr[i];
int currentMinStartIndex = i;
int count = 0;
int tempNum = num;
// Forward
while (visitedElements.count(tempNum) == 1 &&
visitedElements[tempNum] == true) {
visitedElements[tempNum] = false;
count++;
tempNum++;
}
// Backward
tempNum = num - 1;
while (visitedElements.count(tempNum) == 1 &&
visitedElements[tempNum] == true) {
visitedElements[tempNum] = false;
count++;
currentMinStartIndex = elementToIndexMapping[tempNum];
tempNum--;
}
if (count > globalMaxSequenceLength) {
globalMaxSequenceLength = count;
globalMinStartIndex = currentMinStartIndex;
} else if (count == globalMaxSequenceLength) {
if (currentMinStartIndex < globalMinStartIndex) {
globalMinStartIndex = currentMinStartIndex;
}
}
}
int globalStartNum = arr[globalMinStartIndex];
longestSequence.push_back(globalStartNum);
if (globalMaxSequenceLength > 1) {
longestSequence.push_back(globalStartNum + globalMaxSequenceLength - 1);
}
  return longestSequence;
}

*/
  
  #include<bits/stdc++.h>
int findindex(int* arr,int n,int q)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == q)
            return i;
    }
}
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) 
{
    // Your Code goes here
    unordered_map<int,bool> m;
    for(int i=0; i<n; i++)
    {
        m[arr[i]] = true;
    }
    int start = 0;
    int end = 0;
    int len_max = 0;
    int index = -1;
    for(int i=0; i<n; i++)
    {
        int a = arr[i];
        int p=a+1;
        int len = 1;
        if(m[a])
        {
            while(m[p])
            {
                len++;
                 m[p]=false;
                p++;
               
            }
        }
        int q=a-1;
        while(m[q])
        {
            len++;
             m[q]=false;
            q--;
           
        }
        
        if(len == len_max)
        {
            int u = findindex(arr,n,q+1);
            if(index == -1 || u < index)
            {
                start = q+1;
            	end = p-1;
            	len_max = len;
                index = u;
            }
            
        }
        else if(len > len_max)
        {
            int u = findindex(arr,n,q+1);
            
            start = q+1;
            end = p-1;
            len_max = len;
            index = u;
            
        }
        
        
    }
    vector<int> vec;
    vec.push_back(start);
    vec.push_back(end);
    return vec;
}
