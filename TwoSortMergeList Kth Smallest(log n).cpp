#include<iostream>
#include<vector>
#define INT_MIN -100000
using namespace std;
int a[100],b[100];

int findKthSmallest2(int A[], int m, int B[], int n, int k) {
    if(m > n){
        return findKthSmallest2(B, n, A, m, k);
    }

    m = min(k, m), n = min(k, n);
    int low = 0, high = m;
    while (low < high) {
        int mid = low + (high - low) / 2,  bIdx = k - 1 - mid;
        if (bIdx >= n || A[mid] < B[bIdx]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return max(low ? A[low - 1] : INT_MIN, k - 1 - low >= 0 ? B[k - 1 - low] : INT_MIN);
}

int select(int k, int v1[], int n, int v2[], int m) {
    return findKthSmallest2(v1, n, v2, m, k);
}

int main(){
  int K, i, n, m, bb, j;
  cin>>n>>m>>K;
  for(i = 0; i<n; i++){
     cin>>a[i];
  }
  for(i = 0; i<m; i++){
     cin>>b[i];
  }
  cout<<select(K,a,n,b,m)<<endl;
  return 0;
}
