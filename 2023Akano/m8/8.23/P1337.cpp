#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1018;
const double startTemp = 2006 + 1018 + 1108;
const double deltaT = 0.996010181108;
const double endT = 1e-12;
const double alpha = 50000;
const int MAXVAL = 1e9;
struct OBJ{
	int x,y,w;
}obj[MAXN];
int n;
double nowx,nowy,ansx,ansy,ans;
mt19937 rng(time(0));
inline int MyRand(){
	return rng() % MAXVAL;
}
inline double Rand1(){
	return 1.0f * (MyRand()*2-MAXVAL) / MAXVAL;
}
inline double Rand1f(){
	return 1.0f * MyRand() / MAXVAL;
}
inline double P(double inx){
	return inx * inx;
} 
inline double Cost(double x,double y){
	double ret = 0;
	for(int i = 1;i <= n;i++){
		ret += sqrt(P(x - obj[i].x) + P(y - obj[i].y)) * obj[i].w;
	}
	return ret;
}
inline void SA(){
	double temp = startTemp;
	while(temp > endT){
		const double newx = nowx + Rand1f() * alpha * temp;
		const double newy = nowy + Rand1f() * alpha * temp;
		const double newans = Cost(newx,newy);
		if(newans < ans){
			nowx = newx,nowy = newy,ansx = nowx,ansy = nowy,ans = newans;
		}else if(Rand1() < exp(-(newans - ans) / temp)){
			nowx = newx,nowy = newy;
		}
		temp *= deltaT;
	}
	return ;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>obj[i].x>>obj[i].y>>obj[i].w;
		nowx += obj[i].x,nowy += obj[i].y;
	}
	nowx /= n,nowy /= n,ansx = nowx,ansy = nowy;
	ans = Cost(nowx,nowy);
	for(int i = 1;i <= 3;i++)SA();
	cout<<fixed<<setprecision(3)<<ansx<<" "<<ansy<<endl; 
	return 0;
}
