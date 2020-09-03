#include <bits/stdc++.h>

using namespace std;

int binarySearch(int lx, int rx, int target, vector<int> &arr){
  while(rx > lx + 1){
    int mid = (lx + rx) / 2;
    if(arr[mid] <= target) lx = mid;
    else rx = mid;
  }
  return lx + 1;
}

int main() {
  
  int n, m;
  cin>>n>>m;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin>>arr[i];
  for(int i = 0; i < m; i++) {
    int target;
    cin>>target;
    cout<<binarySearch(- 1, n , target, arr)<<endl;
  }
  return 0;
}