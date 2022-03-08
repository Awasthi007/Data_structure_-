Area Of Convex Polygon
Send Feedback
A convex polygon is a set of n vertices that are joined by n edges, such that no two edges intersect and all angles are less than 180 degrees. We can represent a polygon by listing all the vertices, starting at one vertex and following the edges until that vertex is reached again. Thus, element 0 in the array represents the first vertex. The first vertex is connected to the second vertex (element 1), the second vertex is connected to the third vertex (element 2) and so on. The last element represents the last vertex, which is connected to the first vertex.
Given the vertices of a polygon, return its exact area.
Note: Get the integer part of the area. (It can be long). So get your answer in double, and typecast it into long.
Input Format:
First line of input will contain T(number of test cases), each test case follows.
Line 1: Integer N denoting the number of points.
Next N lines will denote the N cordinates (x,y) in a anticlockwise order.
Constraints:
1 <= T <= 10^5
1 <= N <= 50
1 <= X <= Y <= 10^5
The given polygon is guranted to be convex.
Output Format:
For each test case, print the area of polygon in new line.
Sample Input 1:
1
4
1 5
2 2
9 2
7 5
Sample Output 1:
19
  
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  // define ctrl m to break infinite loop
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
#define vi vector<int>

class Point
{
public:
	double x, y;
};

class polygon
{
public:
	Point* points;
	polygon(int n)
	{
		points = new Point[n];
	}
};


double solve(polygon p, int n)
{
	double area = 0;

	for (int i = 1; i < n - 1; i++) // because we have to access i and i+1 simultaneously
	{
		double x1 = p.points[i].x - p.points[0].x;
		double y1 = p.points[i].y - p.points[0].y;

		double x2 = p.points[i + 1].x - p.points[0].x;
		double y2 = p.points[i + 1].y - p.points[0].y;

		double crossP = (x1 * y2) - (y1 * x2);
		area += crossP;
	}

	area = abs(area) / 2;
	return area;
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
	cout << "sides" << endl;
	int n;
	cin >> n;

	polygon p(n);

	cout << "coordinates" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> p.points[i].x;
		cin >> p.points[i].y;
	}
	cout << "area" << endl;
	cout << solve(p, n);
	return 0;
}
  
