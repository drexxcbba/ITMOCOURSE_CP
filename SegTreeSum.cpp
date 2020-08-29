#include <bits/stdc++.h>

using namespace std;

// Segment Tree structure
struct segtree{

  int size;
  vector<long long> sums;

  void init(int n){
    
    //Initializing this Segment Tree empty
    size = 1;
    while(size < n) size *= 2;
    sums.assign(2 * size, 0LL);
  }

  void build(vector<long long> &a, int curr, int lx, int rx){
    if(rx - lx == 1){
      if(lx < (int) a.size()){
        sums[curr] = a[lx]; 
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * curr + 1, lx, m);
    build(a, 2 * curr + 2, m, rx);
    sums[curr] = sums[2 * curr + 1] + sums[2 * curr + 2];
  }

  void build(vector<long long> &a){
    build(a, 0, 0, size);
  }

  //Checking the current node
  void set(int i, int v, int curr, int lx, int rx){
    
    //We are in one leaf..
    if(rx - lx == 1){
      sums[curr] = v;
      return;
    }

    int m = (lx + rx) / 2;
    
    if(i < m){
      //Go to the left part
      set(i, v, 2 * curr + 1, lx, m);
    }else{
      //Go to the right part
      set(i, v, 2 * curr + 2, m, rx);
    }

    //Reconstructing the sum
    sums[curr] = sums[2 * curr + 1] + sums[2 * curr + 2];
  }

  void set(int i, int v){

    //Search the node begining in the root
    set(i, v, 0, 0, size);
  }

  long long getSum(int l, int r, int curr, int lx, int rx){

    //Out of the border
    if(lx >= r || l >= rx) return 0;
    //Inside
    if(lx >= l && rx <= r) return sums[curr];

    int m = (lx + rx) / 2;
    long long left = getSum(l, r, 2 * curr + 1, lx, m);
    long long right = getSum(l, r, 2 * curr + 2, m, rx);
    return left + right;
  }

  long long getSum(int l, int r){
    return getSum(l, r, 0, 0, size);
  }
};

int main() {
  
  ios::sync_with_stdio(false);
  
  int n, m;
  cin>>n>>m;

  segtree st;
  st.init(n);
  
  //Creating the Segment Tree in n log n time
  /* 
  for (int i = 0; i < n; i++){
    long long v;
    cin>>v;
    st.set(i, v);  
  }
  */

  //Creating the Segment Tree in a linear time
  vector<long long> a (n);
  for (int i = 0; i < n; i++) cin>>a[i];
  st.build(a);

  //Working on querys
  while (m--){
    int q;
    cin>>q;
    if(q == 1){
      int i, v;
      cin>>i>>v;
      st.set(i, v);
    } else{
      int l, r;
      cin>>l>>r;
      cout<<st.getSum(l ,r)<< "\n";
    }
  }
  return 0;
}