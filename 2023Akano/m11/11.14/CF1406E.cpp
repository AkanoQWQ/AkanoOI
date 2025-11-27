#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int n,spr;
vector<int> pr,ans;
inline void GetPrime(){
	for(int i = 2;i <= n;i++){
		bool ISP = true;
		for(int j = 2;j * j <= i;j++){
			if(i % j == 0)ISP = false;
		}
		if(ISP)pr.push_back(i);
	}
	return ;
}
inline pair<bool,int> Del(const vector<pii>& del,int preSize){
	int delnum = 0;
	for(auto i : del){
		delnum += i.second;
	}
	int nowSize = 0;
	cout<<"A 1"<<endl;
	cin>>nowSize;
	return make_pair(preSize-nowSize != delnum,nowSize);
}
inline void Solve(const vector<pii>& vec,bool NEED_DEL){
	for(auto i : vec){
		if(NEED_DEL){
			int useless;
			cout<<"B "<<i.first<<endl;
			cin>>useless;
		}
		cout<<"A "<<i.first<<endl;
		int res = 0;
		cin>>res;
		if(res >= 1){
			ans.push_back(i.first);
		}
	}
	return ;
}
inline void Calc(int l,int r,int lasta){
	vector<pii> now;
	int blk = 0;
	for(auto p : pr){
		if(p < l)continue;
		if(p > r)break;
		++blk;
	}
	blk = sqrt(blk);
	now.reserve(blk);
	for(auto p : pr){
		if(p < l)continue;
		if(p > r)break;
		//lasta known
		cout<<"B "<<p<<endl;
		pii getin = make_pair(p,0);
		cin>>getin.second;
		now.push_back(getin);
		if(int(now.size()) == blk){
			auto res = Del(now,lasta);
			lasta = res.second;
			if(res.first){
				Solve(now,false);
			}
			now.clear();
		}
	}
	if(now.size() != 0){
		auto res = Del(now,lasta);
		lasta = res.second;
		if(res.first){
			Solve(now,false);
		}
		now.clear();
		if(res.first)return ;//?OK?
	}
	return ;
}
inline ll SolvePow(){
	int ret = 1;
	for(auto p : ans){
		ll now = p,getin = 0;
		while(now <= n){
			now = now * p;
			if(now > n){
				ret *= now / p;
				break;
			}
			cout<<"A "<<now<<endl;
			cin>>getin;
			if(getin == 0){
				ret *= now / p;
				break;
			}
		}
	}
	return ret;
}
int main(){
	cin>>n;
	spr = sqrt(n);
	GetPrime();
	Calc(spr,n,n);
	vector<pii> pre;
	for(auto p : pr){
		if(p >= spr)break;
		pre.push_back(make_pair(p,0));
	}
	Solve(pre,true);
	int mans = SolvePow();
	cout<<"C "<<mans<<endl;
	return 0;
}
