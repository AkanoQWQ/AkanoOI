#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-7;
const int MAXN = 14;
int n;
double a[MAXN];
double p(double x,int t){
	double ret = 1;
	while(t--){
		ret *= x;
	}
	return ret;
}
double f(double x){
	double ret = 0;
	for(int i = n;i >= 0;i--){
		ret += p(x,i) * a[i];
	}
	return ret;
}
double l,r; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>l>>r;
	for(int i = n;i >= 0;i--){
		cin>>a[i];
	}
	while(l + EPS < r){
		const double midl = l + (r - l) / 3;
		const double midr = r - (r - l) / 3;
		if(f(midl) > f(midr)){
			r = midr;
		}else{
			l = midl;
		}
	}
	printf("%.6lf",l);
	return 0;
}

