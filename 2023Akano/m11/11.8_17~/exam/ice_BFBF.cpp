#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using vi = vector<int>;
int n,ans;
vi mainvec,ansvec,befvec;
inline int Solve(){
	int ret = 0;
	vi vec;
	for(int i = 0;i < n;i++){
		vec.push_back(i+1);
	}
	set<vi> vis;
	vi newvec = vec;
	while(vis.find(vec) == vis.end()){
		vis.insert(vec);
		for(int i = 0;i < n;i++){
			newvec[i] = vec[mainvec[i]-1];
		}
		swap(vec,newvec);
		ret++;
	}
	if(ret >= ans){
		ansvec = mainvec;
	}
	return ret;
}
inline void DEBUG(){
	for(auto i : ansvec)cerr<<i<<" ";
	cerr<<endl;
	return ;
	mainvec.clear();
	int fac = 1;
	for(int i = 0;i < n;i++){
		fac *= (i+1);
		mainvec.push_back(i+1);
	}
	int cnt = 0;
	do{
		if(Solve() == ans){
			cnt++;
			
			for(auto i : mainvec){
				cerr<<i<<" ";
			}
			cerr<<endl;
			break;
		}
	}while(next_permutation(mainvec.begin(),mainvec.end()));
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 0;i < n;i++){
		mainvec.push_back(i+1);
	}
	do{
		ans = max(ans,Solve());
	}while(next_permutation(mainvec.begin(),mainvec.end()));
	cout<<setprecision(7)<<fixed<<logl(ans)<<endl;
	
	DEBUG();
	return not(Akano loves pure__Elysia);
}
