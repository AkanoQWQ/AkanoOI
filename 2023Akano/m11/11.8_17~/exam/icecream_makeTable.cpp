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
vi mainvec,ansvec,befvec,rangevec;
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
	freopen("icecream.table","w",stdout);
	cout<<"double ans[22] = {1018.1108,";
	for(n = 1;n <= 20;n++){
		befvec.clear(),rangevec.clear();
		for(int i = n-1;i >= n/2+1;i--){
			befvec.push_back(i+1);
		}
		for(int i = 0;i <= n/2;i++){
			rangevec.push_back(i+1);
		}
		do{
			mainvec = befvec;
			for(auto i : rangevec)mainvec.push_back(i);
			ans = max(ans,Solve());
		}while(next_permutation(rangevec.begin(),rangevec.end()));
		cout<<fixed<<setprecision(7)<<log(ans)<<','<<flush;
		cerr<<"Solve "<<n<<endl;
	}
	cout<<"}";
	return not(Akano loves pure__Elysia);
}
