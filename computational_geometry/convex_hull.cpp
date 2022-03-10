#include<bits/stdc++.h>
using namespace std;
class points
{
    public:
    int x,y;
};

 bool tochange(points p1, points p2, points p3)
 {
     int x1 = p2.x-p1.x;
     int y1 = p2.y - p1.y;
     
     int x2 = p3.x - p2.x;
     int y2 = p3.y - p2.y;
     
     int ans = (x1*y2) - (y1*x2);
     
     return ans > 0;
     
     
 }
 
 
 void convexHull(points arr[], int n)
 {
     int left = 0;
     for(int i=1; i<n; i++)
     {
         if(arr[i].x < arr[left].x)
            left = i;
     }
     vector<points> hull;
     int p = left;
     
     do{
         int q = (p+1)%n;
         hull.push_back(arr[p]);
         
         for(int i=0; i<n; i++)
         {
             if(tochange(arr[p], arr[q], arr[i]))
             {
                 q = i;
             }
         }
         p = q;
     }while(p!=left);
     
     for(auto i : hull)
     {
         cout<<i.x<<" "<<i.y<<endl;
     }
     return;
 }



int main()
{
    points arr[] = {{2,2}, {1,2},{4,0}, {3,3},{0,0}, {0,4},{4,4}};
    
     //cout<<crosser(p1, p2, p3);
     convexHull(arr, 7);
     
     
    return 0;
}
