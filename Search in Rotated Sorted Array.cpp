//Complexity: O(logn)
//Pitfall: Duplicate element O(n) for Linear Search
#include<iostream>
using namespace std;
int a[2*102];

int RotationIbinarySearch(int a[], int low, int up, int findNum){
   while(low<=up){
      int mid = (low+up)/2;
      if(a[mid] == findNum) return mid;
      else if(a[low]<=a[mid]){
        if(findNum>a[mid]) low = mid + 1;
        else if(findNum>=a[low]) up = mid-1;
        else low = mid + 1;
      }
     else if(a[mid]>findNum) up = mid-1;
     else if(a[up]>=findNum) low = mid + 1;
     else up = mid - 1;
   }
   return -1;
}
int main()
{
    int n , m;
    cin>>n>>m;
    for(int i =0; i<n; i++) cin>>a[i];
    cout<<RotationIbinarySearch(a,0,n-1, m)<<endl;
    return 0;
}
