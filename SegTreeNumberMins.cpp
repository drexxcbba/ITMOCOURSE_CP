#include <bits/stdc++.h>

using namespace std;

struct item{
  int mn, cont;
};

// Segment Tree structure
struct segtree{

  int size;
  vector<item> values;
  item NEUTRAL = {INT_MAX, 0};

  void init(int n){
    
    //Initializing this Segment Tree empty
    size = 1;
    while(size < n) size *= 2;
    values.resize(2 * size);
  }

  item merge(item l, item r){
    if(l.mn < r.mn) return l;
    if(r.mn < l.mn) return r;
    if(l.mn == r.mn) return {l.mn, l.cont + r.cont};
  }

  item single(int v){
    return {v , 1};
  }

  void build(vector<int> &a, int curr, int lx, int rx){
    if(rx - lx == 1){
      if(lx < (int) a.size()){
        values[curr] = single(a[lx]); 
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * curr + 1, lx, m);
    build(a, 2 * curr + 2, m, rx);
    values[curr] = merge(values[2 * curr + 1], values[2 * curr + 2]);
  }

  void build(vector<int> &a){
    build(a, 0, 0, size);
  }

  //Checking the current node
  void set(int i, int v, int curr, int lx, int rx){
    
    //We are in one leaf..
    if(rx - lx == 1){
      values[curr] = single(v);
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
    values[curr] = merge(values[2 * curr + 1], values[2 * curr + 2]);
  }

  void set(int i, int v){

    //Search the node begining in the root
    set(i, v, 0, 0, size);
  }

  item calc(int l, int r, int curr, int lx, int rx){

    //Out of the border
    if(lx >= r || l >= rx) return NEUTRAL;
    //Inside
    if(lx >= l && rx <= r) return values[curr];

    int m = (lx + rx) / 2;
    item left = calc(l, r, 2 * curr + 1, lx, m);
    item right = calc(l, r, 2 * curr + 2, m, rx);
    return merge(left, right);
  }

  item calc(int l, int r){
    return calc(l, r, 0, 0, size);
  }
};

int main() {
  
  ios::sync_with_stdio(false);
  
  int n, m;
  cin>>n>>m;

  segtree st;
  st.init(n);
  
  vector<int> a (n);
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
      item res = st.calc(l, r);
      cout<<res.mn<<" "<<res.cont<< "\n";
    }
  }
  return 0;
}