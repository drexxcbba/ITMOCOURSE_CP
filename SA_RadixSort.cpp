#include <bits/stdc++.h>

using namespace std;

void radixSort(vector< pair< pair<int, int>, int> > &a){
	int n = a.size();
	{
    	vector<int> count (n);
	  	for (auto x: a){
			count[x.first.second]++;
		}
    	vector< pair< pair<int, int>, int> > new_a (n);
    	vector<int> pos (n);
    	pos[0] = 0;
    	for(int i = 1; i < n; i++) pos[i] = pos[i - 1] + count[i - 1];
    	for(auto x: a){
      		int i = x.first.second;
      		new_a[pos[i]] = x;
      		pos[i]++;
    	}
    	a = new_a;
  	}
  	{
    	vector<int> count (n);
	 	for (auto x: a){
		  	count[x.first.first]++;
	  	}
    	vector< pair< pair<int, int>, int> > new_a (n);
   		vector<int> pos (n);
   		pos[0] = 0;
    	for(int i = 1; i < n; i++) pos[i] = pos[i - 1] + count[i - 1];
    	for(auto x: a){
    	  int i = x.first.first;
      	  new_a[pos[i]] = x;
      	  pos[i]++;
   	    }
      	a = new_a;
  	}
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
		vector< pair< pair<int, int>, int> > a (n);
		for (int i = 0; i < n; i++){
			a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
		}
		
		//Radix
		radixSort(a);
		
		for(int i = 0; i < n; i++) p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i = 1; i < n; i++){
			if(a[i].first == a[i - 1].first){
				c[p[i]] = c[p[i - 1]];
			}else{
				c[p[i]] = c[p[i - 1]] + 1;
			}
		}
		k++; 
	}
	
	for(int i = 0; i < n ; i++) cout<<p[i]<<" ";
	cout<<endl;
	return 0;
}
