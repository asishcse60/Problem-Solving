#include<stdio.h>
#include<iostream>
using namespace std;
int A[20], B[20], n,m;

double findMedian(int A[], int B[], int left, int right, int toA, int toB){
    if(left > right) return findMedian(B, A, max(0,(toA + toB)/2 - toA),min(toB,(toA + toB)/2),toB, toA);
    int i = (left + right)/2;
    int j = (toA + toB)/2 - i - 1;
    if(j >=0 && A[i]<B[j])  return findMedian(A, B, i+1, right, toA, toB);
    else if(j<toB-1 && A[i] > B[j+1]) return findMedian(A, B, left, i-1, toA, toB);
    else {
        if((toA+toB)%2 == 1 ) return A[i];
        else if (i>0) return (A[i]+max(B[j], A[i-1]))/2.0;
        else return (A[i]+B[j])/2.0;
    }
}
int main()
{
    int i, j;
    cin>>n;
    for(i=0;i<n;i++) cin>>A[i];cin>>m;
    for(i=0;i<m;i++) cin>>B[i];
    if(m == 0 && n==0) printf("%.2lf\n", 0.0);
        else if(m == 0 && n%2) printf("%.2lf\n",(double)A[n/2]);
         else if(m==0 && n%2==0)printf("%.2lf\n",(A[n/2] + A[n/2-1])/2.0);
         else if(n == 0 && m%2) printf("%.2lf\n",(double)B[m/2]);
         else if(n==0 && m%2==0) printf("%.2lf\n",(B[m/2] + B[m/2-1])/2.0);
    else if(n<m) printf("%.2lf\n", findMedian(A , B, 0, n-1, n, m));
    else printf("%.2lf\n",findMedian(B, A, 0, m-1, m, n));
    return 0;
}
