#include <bits/stdc++.h>

using namespace std;

int rightX(int lx, int rx, long long target, vector<long long> &arr){
  while(rx > lx + 1){
    int mid = (lx + rx) / 2;
    if(arr[mid] < target) lx = mid;
    else rx = mid;
  }
  return rx + 1;
}

int leftX(int lx, int rx, long long target, vector<long long> &arr){
  while(rx > lx + 1){
    int mid = (lx + rx) / 2;
    if(arr[mid] <= target) lx = mid;
    else rx = mid;
  }
  return lx;
}

int main() {
  
  int n, m;
  cin>>n;
  vector<long long> arr(n);
  for(int i = 0; i < n; i++) cin>>arr[i];
  sort(arr.begin(), arr.end());
  cin>>m;
  for(int i = 0; i < m; i++) {
    int left, right;
    cin>>left>>right;
    int lx = leftX(-1, n + 1, left, arr);
    int rx = rightX(-1, n + 1, right, arr);
    cout<<lx<<" "<<rx<<endl;
  }
  return 0;
}