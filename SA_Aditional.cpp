#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int> &p, vector<int> &c){
	int n = p.size();
    vector<int> count (n);
  	for (auto x: c){
		count[x]++;
	}
   	vector<int> new_p (n);
   	vector<int> pos (n);
   	pos[0] = 0;
   	for(int i = 1; i < n; i++) pos[i] = pos[i - 1] + count[i - 1];
   	for(auto x: p){
     	int i = c[x];
      	new_p[pos[i]] = x;
      	pos[i]++;
    }
    p = new_p;
}

int main(){
	
	string s;
	cin>>s;
	s += '$';
	int n = s.size();
	//This array will contain the ordering of the strings
	vector<int> p (n);
	//This array will contain their equivalences of the class string
	vector<int> c (n);
	{
		//k = 0;
		vector< pair<char, int> > a (n);
		for (int i = 0; i < n; i++) a[i] = { s[i], i };
		sort(a.begin(), a.end());
		for(int i = 0; i < n; i++) p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i = 1; i < n; i++){
			if(a[i].first == a[i - 1].first){
				c[p[i]] = c[p[i - 1]];
			}else{
				c[p[i]] = c[p[i - 1]] + 1;
			}
		} 
	}
	int k = 0;
	while((1 << k) < n){
		//k -> k + 1
		for(int i = 0; i < n; i++){
      		p[i] = (p[i] - (1 << k)+ n) % n;
    	}
		
		//Radix
		countSort(p , c);
		vector<int> new_c (n);
		new_c[p[0]] = 0;
		for(int i = 1; i < n; i++){
      		pair<int, int> now = { c[p[i]], c[(p[i] + (1 << k)) % n] };
      		pair<int, int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
			if(now == prev){
				new_c[p[i]] = new_c[p[i - 1]];
			}else{
				new_c[p[i]] = new_c[p[i - 1]] + 1;
			}
		}
    	c = new_c;
		k++; 
  	}
	for(int i = 0; i < n ; i++) cout<<p[i]<<" ";
	cout<<endl;
	return 0;
}
