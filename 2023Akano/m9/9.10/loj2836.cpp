#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e5 + 1018 + 1108;
int n,q,d[MAXN],stp[MAXN],clk[MAXN];//第i个人每隔 clk 时刻移动 stp 步 
inline int Query(int t,int pos){//t时刻第一个位置大于等于 pos 的人 
	int l = 1,r = n + 1;
	while(l < r){
		const int mid = (l + r) >> 1;
		int now = (t / clk[mid]) * stp[mid] - mid + 1;//编号偏移了1 
//		cerr<<mid<<" move "<<t<<" to "<<now<<endl;
		if(now >= pos){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	return l-1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	stp[1] = clk[1] = 1;
	n++;//算上旗手 
	for(int i = 2;i <= n;i++){
		cin>>d[i];
		int times = ceil(d[i] / double(stp[i-1]));
		clk[i] = clk[i-1] * times,stp[i] = stp[i-1] * times;
//		cerr<<i<<" 隔着 "<<clk[i]<<" 时刻,移动 "<<stp[i]<<" 步"<<endl;
	}
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		r = Query(t,r+1),l = Query(t,l);
		cout<<l - r<<endl;
//		cerr<<"l "<<l<<" r "<<r<<endl;
	}
	return not(Akano loves pure__Elysia);
}
