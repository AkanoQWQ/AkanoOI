#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
pair<double,double> a,b,c,d;
double p,q,r,ans = 1145141919810;
double la = 0,ra = 1;
double sq(double inx){
	return inx*inx;
}
double dis(pair<double,double> aa,pair<double,double> bb){
	return sqrt(sq(aa.first-bb.first) + sq(aa.second-bb.second));
}
double calc2(pair<double,double> inp,double rat){
	double nx = c.first + (d.first-c.first)*rat;
	double ny = c.second + (d.second-c.second)*rat;
	pair<double,double> op = make_pair(nx,ny);
	double t1 = dis(inp,op) / r;
	double t2 = dis(op,d) / q;
	return t1 + t2;
}
double calc(double rat){
	double ret = 1145141919810;
	double nx = a.first + (b.first-a.first)*rat;
	double ny = a.second + (b.second-a.second)*rat;
	pair<double,double> np = make_pair(nx,ny);
	const double d1 = dis(a,np) / p;
	double ll = 0,rr = 1;
	while(ll + EPS < rr){
		double m1 = ll + (rr - ll) / 3;
		double m2 = rr - (rr - ll) / 3;
		double re1 = calc2(np,m1);
		double re2 = calc2(np,m2);
		if(re1 < re2){
			rr = m2;
			ret = min(ret,re1+d1);
		}else{
			ll = m1;
			ret = min(ret,re2+d1);
		}
	}
	return ret;
}
int main(){
	freopen("tran.in","r",stdin);
	freopen("tran.out","w",stdout);
	cin>>a.first>>a.second>>b.first>>b.second;
	cin>>c.first>>c.second>>d.first>>d.second;
	cin>>p>>q>>r;
	double ll = 0,rr = 1;
	while(ll + EPS < rr){
		double m1 = ll + (rr - ll) / 3;
		double m2 = rr - (rr - ll) / 3;
		double re1 = calc(m1);
		double re2 = calc(m2);
		if(re1 < re2){
			rr = m2;
			ans = min(ans,re1);
		}else{
			ll = m1;
			ans = min(ans,re2);
		}
	}
	printf("%.2lf",ans);
	return 0;
}
