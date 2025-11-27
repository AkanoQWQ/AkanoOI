#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
int t,n,a[MAXN];
string s;
inline void Insert(int x){
	for(int i = n;i >= x;i--){
		a[i+2] = a[i];
	}
	a[x] = 0,a[x+1] = 1;
	n += 2;
	return ;
}
inline int Check(){
	for(int i = 1;i <= n;i++){
		int mirror = (n - i + 1);
		if(a[i] == a[mirror]){
			if(a[i] == 1){
				Insert(i);
				return i;
			}else{
				Insert(mirror+1);
				return mirror+1;
			}
		}
	}
	return -1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			char ch;
			cin>>ch;
			a[i] = ch - '0';
		}
		vector<int> opt;
		for(int i = 1;i <= 303;i++){
			int newOPT = Check();
			opt.push_back(newOPT);
		}
		while(!opt.empty() && opt.back() == -1)opt.pop_back();
		if(opt.size() > 300){
			cout<<"-1"<<endl;
		}else{
			cout<<opt.size()<<endl;
			for(auto i : opt)cout<<i-1<<" ";
			cout<<endl;
		}
	}
	return 0;
}
