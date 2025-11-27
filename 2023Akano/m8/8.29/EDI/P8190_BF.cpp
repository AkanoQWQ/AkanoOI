#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXT = 1e3 + 1018 + 1108;
const double EPS = 1e-7;
int t,k,tail = 0,now = 0,pre = 1;
double f[5],poss[MAXT],temp[MAXT],sum[MAXT],sumposs;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t>>k;
	t--;
	poss[0] = 1;
	for(int i = 0;i < t;i++){
		for(int j = 0;j <= t;j++){
			poss[j] /= 2;
			temp[j] = 0;
		}
		for(int j = 0;j <= t;j++){
			temp[j] += poss[j],temp[j+1] += poss[j];
			poss[j] = temp[j];
		}
	}
	for(int i = 1;i <= t;i++){
		sum[i] = sum[i-1] + i * poss[i];
	}
	f[now] = sum[t];
	for(int i = 1;i < k;i++){
		swap(now,pre);
		while(tail <= t && tail - f[pre] <= EPS){
			sumposs += poss[tail];
			tail++;
		}
		if(tail == 0){
			f[now] = sum[t] + (tail) * f[pre];
		}else{
			f[now] = sum[t] - sum[tail-1] + sumposs * f[pre];
		} 
	}
	cout<<fixed<<setprecision(7)<<f[now]+1<<endl;
	return not(Akano loves pure__Elysia);
}
