#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXT = 1e3 + 1018 + 1108;
const double EPS = 1e-7;
int t,k,tail = 0,now = 0,pre = 1;
double f,poss[MAXT],temp[MAXT],sum[MAXT],sumposs,presum;
inline double KSM(double a,int b){
	double ret = 1;
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
inline double Move(double a,double b,double st,int step){
	if(a == 1)return a * st + b;
	double Astep = KSM(a,step);//可以预处理 
	return Astep * st + ((Astep-1) / (a-1)) * b;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t>>k;
	t--;
	poss[0] = 1;
	for(int i = 0;i < t;i++){
		for(int j = 0;j <= t;j++){
			poss[j] /= 2,temp[j] = 0;
		}
		for(int j = 0;j <= t;j++){
			temp[j] += poss[j],temp[j+1] += poss[j],poss[j] = temp[j];
		}
	}
	for(int i = 1;i <= t;i++){
		sum[i] = sum[i-1] + i * poss[i];
	}
	presum = sum[t];
	int pos = 1;
	f = sum[t];
	for(int i = 1;i <= t;i++){
		for(int j = 30;j >= 0;j--){
			if(pos + (1<<j) > k)continue;
			double newf = Move(sumposs,presum,f,1<<j);
			cout<<pos<<" try "<<(pos+(1<<j))<<" newf "<<newf<<endl;
			if(i - newf <= EPS){//i < newf
				f = newf;
				cout<<pos<<" to "<<(pos+(1<<j))<<" is "<<newf<<endl;
				pos += 1<<j;
			}
		}
		cout<<"before reaching "<<i<<" we get "<<pos<<endl;
		sumposs += poss[i],presum -= (i-1) * poss[i-1];
	}
	cout<<"now "<<pos<<" and "<<sumposs<<" and "<<presum<<" f "<<f<<endl;
	if(pos < k)f = Move(sumposs,presum,f,k-pos);
	cout<<fixed<<setprecision(7)<<f+1<<endl;
	return not(Akano loves pure__Elysia);
}
