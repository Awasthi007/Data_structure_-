Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0, for each test case in a new line
Constraints :
1 <= T <= 10
1 <= N <= 1000
1 <= M <= 1000
Sample Input :
1
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
  
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  // #include <iostream>
// #include<bits/stdc++.h>
// #include <vector>
// using namespace std;


// bool bfs( vector< vector<char> > &board , int n , int m ,int ci , int cj,vector< vector<bool> >&visited,string s)
// {
//     if(s.size()==0)
//     {
//         return true;
//     }
//     visited[ci][cj]=true;


//     bool ans = false;
//     if(ci+1<n && !visited[ci+1][cj] && board[ci+1][cj]==s[0])// down
//     {
//         if( bfs(board,n,m,ci+1,cj,visited, s.substr(1)))
//             return true;
//     }

//     if(ci-1>=0 && !visited[ci-1][cj] && board[ci-1][cj]==s[0])// up

//     {
//         if(  	bfs(board,n,m,ci-1,cj,visited, s.substr(1)))
//             return true;
//     }
//     if(cj-1>=0 && !visited[ci][cj-1] && board[ci][cj-1]==s[0])// left
//     {
//         if( bfs(board,n,m,ci,cj-1,visited, s.substr(1)))
//             return true;
//     }

//     if(cj+1<m && !visited[ci][cj+1] && board[ci][cj+1]==s[0])// right
//     {
//         if( bfs(board,n,m,ci,cj+1,visited, s.substr(1)))
//             return true;
//     }


//     if(ci+1<n && cj-1>=0&&!visited[ci+1][cj-1] && board[ci+1][cj-1]==s[0])// down left
//     {
//         if( bfs(board,n,m,ci+1,cj-1,visited, s.substr(1)))
//             return true;
//     }

//     if(ci+1<n && cj+1<m&&!visited[ci+1][cj+1] && board[ci+1][cj+1]==s[0])// down right
//     {
//         if( bfs(board,n,m,ci+1,cj+1,visited, s.substr(1)))
//             return true;
//     }


//     if(ci-1>=0 && cj-1>=0 && !visited[ci-1][cj-1] && board[ci-1][cj-1]==s[0])// up left 
//     {
//         if( bfs(board,n,m,ci-1,cj-1,visited, s.substr(1)))
//             return true;
//     }

//     if(ci-1>=0 && cj+1<m&& !visited[ci-1][cj+1] && board[ci-1][cj+1]==s[0])// up right
//     {
//         if(	 bfs(board,n,m,ci-1,cj+1,visited, s.substr(1)))
//             return true;
//     }
    
//  visited[ci][cj]=false;

//     return ans;
// }




// bool hasPath(vector<vector<char>> &board, int n, int m) {
// vector<vector<bool> >visited(n,vector<bool>(m, false));
//     for(int i=0; i<n ; i++)
//     {    for(int j=0 ; j< m; j++)
//     {
//         if(board[i][j]=='C')
//         {
            
//             string s ="ODINGNINJA";
       
//             if(bfs(board, n,m,i,j,visited,s))
//                 return true;

//         }
//     }
//     }
//     return false;

// }

// int main() {
//     int t;
//     cin>>t;
//     while(t--){int n, m;
//     cin >> n >> m;

//     vector<vector<char>> board(n, vector<char>(m));

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> board[i][j];
//         }
//     }

//     cout << (hasPath(board, n, m) ? 1 : 0)<<endl;}
// }




#include<bits/stdc++.h>
using namespace std;

bool helper(vector<vector<char>> &board, int n, int m, int ci, int cj,vector<vector<bool>> &visited, string s)
{
    if(s.length() == 0)
        return true;
    visited[ci][cj] = true;
    
    // up
    
    if((ci-1 >= 0) && board[ci-1][cj] == s[0] && !visited[ci-1][cj])
    {
        if(helper(board, n, m, ci-1,cj, visited, s.substr(1)))
        {
            return true;
        }
    }
    // down
    if((ci+1) < n && board[ci+1][cj] == s[0] && !visited[ci+1][cj])
    {
        if(helper(board, n, m, ci+1,cj, visited, s.substr(1)))
        {
            return true;
        }
    }
    
    // left
    
    if((cj-1) >= 0 && board[ci][cj-1] == s[0] && !visited[ci][cj-1])
    {
        if(helper(board, n, m, ci,cj-1, visited, s.substr(1)))
        {
            return true;
        }
    }
    
    // right
    if(cj+1 < m && board[ci][cj+1] == s[0] && !visited[ci][cj+1])
    {
        if(helper(board, n, m, ci,cj+1, visited, s.substr(1)))
        {
            return true;
        }
    }
    
    //top-right
    
    if((ci-1 >= 0) && (cj+1) < m && board[ci-1][cj+1]==s[0] && !visited[ci-1][cj+1])
    {
        if(helper(board, n, m, ci-1,cj+1, visited, s.substr(1)))
        {
            return true;
        }
    }
    
    //right-down
    if(ci + 1 < n && cj+1 < m && board[ci+1][cj+1] == s[0] && !visited[ci+1][cj+1])
    {
        if(helper(board, n, m, ci+1,cj+1, visited, s.substr(1)))
        {
            return true;
        }
    }
    //down-left
    if(ci+1 < n && cj-1 >= 0 && board[ci+1][cj-1]==s[0] && !visited[ci+1][cj-1] )
    {
        if(helper(board, n, m, ci+1,cj-1, visited, s.substr(1)))
        {
            return true;
        }
    }
    //left -top
    if(ci-1 >= 0 && cj-1 >=0 && board[ci-1][cj-1] == s[0] && !visited[ci-1][cj-1])
    {
        if(helper(board, n, m, ci-1,cj-1, visited, s.substr(1)))
        {
            return true;
        }
        
    }
    visited[ci][cj] = false;
    return false;
    
}


bool hasPath(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == 'C')
            {
                string s = "ODINGNINJA";
                bool ans = helper(board, n, m, i, j, visited, s);
                if(ans)
                    return true;
            }
        }
    }
    
    return false;
    
}


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        vector<vector<char>> board(n, vector<char>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>board[i][j];
            }
        }
        
        cout<<(hasPath(board,n,m) ? 1 : 0) <<endl;
    }
       
    return 0;
}
