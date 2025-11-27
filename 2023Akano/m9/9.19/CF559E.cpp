#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 106;
const double startTemp = 2006 + 1018 + 1108;
const double endT = 0.0010181108;
const double delta = 0.998;
int n,p[MAXN],l[MAXN];
bool isL[MAXN];
inline int Calc(){
	int ret = 0;
	vector<pair<int,int> > seg;
	for(int i = 1;i <= n;i++){
		if(isL[i]){
			seg.push_back(make_pair(p[i] - l[i] + 1,p[i]));
		}else{
			seg.push_back(make_pair(p[i],p[i] + l[i] - 1));
		}
	}
	sort(seg.begin(),seg.end());
	int r = -100;
	for(auto i : seg){
		ret += max(i.second - max(i.first,r+1) + 1,0);
		cerr<<"after "<<i.first<<"~"<<i.second<<" is "<<ret<<endl;
		r = max(r,i.second);
	}
	cerr<<endl;
	return ret;
}
inline int SA(){
	for(int i = 1;i <= n;i++){
		if(rand() & 1){
			isL[i] = true;
		}else{
			isL[i] = false;
		}
	}
	int ans = Calc();
	double t = startTemp;
	while(t >= endT){
		t *= delta;
		int rd = (rand() % n) + 1;
		isL[rd] = !isL[rd];
		int now = Calc();
		if(now > ans){
			ans = now;
		}else if(exp((now - ans) / t)*RAND_MAX > rand()){
			
		}else{
			isL[rd] = !isL[rd];//²»¸Ä±ä 
		}
	}
	return ans;
}
int dfs(int u){
	if(u > n)return Calc();
	int ret = 0;
	isL[u] = 1;
	ret = max(ret,dfs(u+1));
	isL[u] = 0;
	ret = max(ret,dfs(u+1));
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>p[i]>>l[i];
	}
//	cout<<SA()<<endl;
	isL[1] = 1,isL[2] = 1,isL[3] = 0,isL[4] = 0;
	cout<<Calc()<<endl;
	return not(Akano loves pure__Elysia);
}
