#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 106;
const int MAXVAL = 1e6 + 1018 + 1108;

const float startT = 1018;
const float deltaT = 0.99993;
const float endT = 0.00000000010181108;

int T,n,a[MAXN],tot,f[5],bel[MAXN];
mt19937 rng(20061018 + 20061108 + time(0));
inline int Calc(){
	if(f[0] == 0 || f[2] == 0)return 1e8;
	return (abs(f[0] - f[1]) + abs(f[2] - f[3]));
}
inline void SwapGroup(int pos1,int pos2){
	f[bel[pos1]] -= a[pos1],f[bel[pos2]] += a[pos1];
	f[bel[pos2]] -= a[pos2],f[bel[pos1]] += a[pos2];
	swap(bel[pos1],bel[pos2]);
	return ;
}
inline void ChangeGroup(int pos,int to){
	f[bel[pos]] -= a[pos],f[to] += a[pos];
	bel[pos] = to;
	return ;
}
inline bool SA(){
	float temp = startT;
	int totans = Calc();
	if(totans == 0)return true;
	while(temp > endT){
		if(rng() % 100 > (temp / startT) * 100 * 1.5){//交换
			int pos1 = (rng() % n) + 1,pos2 = (rng() % n) + 1;
			SwapGroup(pos1,pos2);
			int nowans = Calc();
			if(nowans == 0){
				return true;
			}
			if(nowans < totans){
				totans = nowans;
			}else if(exp(-(nowans - totans) / temp) * UINT_MAX > rng()){
				
			}else{//还原
				SwapGroup(pos1,pos2);
			}
		}else{//两个一起变
			int pos1 = (rng() % n) + 1,pos2 = (rng() % n) + 1;
			while(bel[pos1] != bel[pos2]){
				pos1 = (rng() % n) + 1,pos2 = (rng() % n) + 1;
			}
			int nxt = rng() % 4,now = bel[pos1];
			ChangeGroup(pos1,nxt),ChangeGroup(pos2,nxt);
			int nowans = Calc();
			if(nowans == 0){
				return true;
			}
			if(nowans < totans){
				totans = nowans;
			}else if(exp(-(nowans - totans) / temp) * UINT_MAX > rng()){
				
			}else{//还原
				ChangeGroup(pos1,now),ChangeGroup(pos2,now);
			}
		}
		temp *= deltaT;
	}
	return false;
}
inline bool Solve(){
	int totTimes = 80;
	for(int toti = 1;toti <= min(totTimes / T,10);toti++){
		f[0] = f[1] = f[2] = f[3] = 0;
		for(int i = 1;i <= n;i++){
			if(i & 1){
				if(i & 2){
					bel[i] = 0;
				}else{
					bel[i] = 1;
				}
			}else{
				if(i & 2){
					bel[i] = 2;
				}else{
					bel[i] = 3;
				}
			}
			f[bel[i]] += a[i];
		}
		for(int i = 1;i <= 4;i++){
			if(SA())return true;
		}
	}
	return false;
}
inline bool Package(){
	bitset<MAXVAL / 2> dp;
	dp[0] = true;
	for(int i = 1;i <= n;i++){
		dp |= (dp << a[i]);
		if(dp[tot / 2])return true;
	}
	return dp[tot / 2];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("track/track8.in","r",stdin);
//	freopen("track.out","w",stdout);
	cin>>T;
	for(int nowt = 1;nowt <= T;nowt++){
		cin>>n;
		tot = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			tot += a[i];
		}
		bool ALLSAME = true;
		for(int i = 2;i <= n;i++){
			if(a[i] != a[i-1])ALLSAME = false;
		}
		if(ALLSAME){
			if(n % 4 == 0){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
			continue;
		}
		if(tot % 2 != 0 || n % 2 != 0){
			cout<<"No"<<endl;
			continue;
		}
		if(Package() == false){
			cout<<"No"<<endl;
			continue;
		}
		if(Solve()){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
