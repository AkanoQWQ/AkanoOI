#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
int n,m;
int lowbit(int inx){
	return inx & -inx;
}
struct BIT{
	int val[MAXN];
	void push(int idx,int v){
		while(idx <= n){
			val[idx] += v;
			idx += lowbit(idx);
		}
	}
	int ask(int idx){
		int ret = 0;
		while(idx > 0){
			ret += val[idx];
			idx -= lowbit(idx);
		}
		return ret;
	}
}tr;
int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		int t;
		cin>>t;
		tr.push(i,t);
	}
	while(m--){
		int opt,a,b;
		cin>>opt>>a>>b;
		if(opt == 1){
			tr.push(a,b);
		}else{
			cout<<tr.ask(b) - tr.ask(a-1)<<endl;
		}
	}	
	return 0;
}
