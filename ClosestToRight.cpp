#include <bits/stdc++.h>

using namespace std;

int binarySearch(int lx, int rx, int target, vector<int> &arr){
  while(rx > lx + 1){
    int mid = (lx + rx) / 2;
    if(arr[mid] < target) lx = mid;
    else rx = mid;
  }
  return rx;
  //Closest to the right should be rx + 1, now we are searching if the target is in the array.
}

int main() {
  
  int n, m;
  cin>>n>>m;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin>>arr[i];
  for(int i = 0; i < m; i++) {
    int target;
    cin>>target;
    if(binarySearch(- 1, n , target, arr) < n && arr[binarySearch(- 1, n , target, arr)] == target) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}