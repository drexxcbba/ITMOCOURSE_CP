#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int lx, int rx, int target, vector<int> &arr){
  bool res = false;
  while(rx >= lx){
    int mid = (lx + rx) / 2;
    if(arr[mid] == target){
      res = true;
      break;
    }else if(arr[mid] < target) lx = mid + 1;
    else rx = mid - 1;      
  }
  return res;
}

int main() {
  
  int n, m;
  cin>>n>>m;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin>>arr[i];
  for(int i = 0; i < m; i++) {
    int target;
    cin>>target;
    if(binarySearch(0, n - 1, target, arr)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}