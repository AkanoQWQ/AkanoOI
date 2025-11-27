#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 20;
const int MAXANS = 10181108;
int n,lim,r[MAXN];
bool OK;
inline int GetVal(int val){
	for(int i = 1;i <= n;i++){
		val += abs(r[i] - r[i+1]) != 1; 
	}
	return val;
}
void IDAS(int step,int val){
	if(OK)return ; 
	if(step == val){
		OK = true;
		return ;
	}
	for(int i = 2;i <= n;i++){
		int nxtStep = step+1;
		reverse(r + 1,r + i + 1);
		int nxtVal = GetVal(nxtStep);
		if(nxtVal <= lim)IDAS(nxtStep,nxtVal);
		reverse(r + 1,r + i + 1);
		if(OK)return ;
	}
	return ;
}
vector<int> vec;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>r[i];
		vec.push_back(r[i]);
	}
	r[n+1] = n+1;
	sort(vec.begin(),vec.end());
	for(int i = 1;i <= n;i++){
		r[i] = lower_bound(vec.begin(),vec.end(),r[i]) - vec.begin() + 1;
	}
	int stVal = GetVal(0);
	for(lim = 0;lim <= MAXANS;lim++){
		IDAS(0,stVal);
		if(OK)break;
	}
	cout<<lim<<endl;
	return not(Akano loves pure__Elysia);
}
