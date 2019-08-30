//Complexity: max(n,m) A>=B Buffer
#include<iostream>
using namespace std;
int a[2*102], b[102];

void Print(int k){
  cout<<"The Sorted List:";
  for(int i = 0; i<=k; i++)
   cout<<" "<<a[i];
   cout<<endl;
}
void mergeList(int a[], int b[], int n, int m){
   int k = n+m-1;
   int i = n-1;
   int j = m - 1;
   //two pointer use
   while(i>=0 && j>=0){
     if(a[i]>b[j]) a[k--] = a[i--];
     else a[k--]= b[j--];
   }
   while(j>=0) a[k--] = b[j--];
   Print(n+m-1);
}
int main()
{
    int n , m;
    cin>>n>>m;
    for(int i =0; i<n; i++) cin>>a[i];
    for(int i =0;i<m; i++) cin>>b[i];
    mergeList(a,b,n,m);
    return 0;
}
