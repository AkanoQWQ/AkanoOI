#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d;
int gcd(int x,int y){
	if(x%y == 0)return y;
	return gcd(y,x%y);
}
struct f{
	int upp,dwn;
};
f yue(f a){
	int yy = gcd(a.upp,a.dwn);
	a.upp /= yy,a.dwn /= yy;
	return a;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		bool out = 0;
		cin>>a>>b>>c>>d;
		int l = 0,r = 0;
		if(c >= 2*a && d >= 2*b){
			cout<<2*a<<" "<<2*b<<endl;
			continue;
		}
		for(l = a+1;l <= c;l++){
			f fy;
			fy.upp  = a*b,fy.dwn = l;
			//cout<<l<<" OK "<<fy.upp<<" / "<<fy.dwn<<endl;
			fy = yue(fy);
			r = fy.upp;
			//cout<<l<<" with "<<r<<" / "<<fy.dwn<<endl;
			int orgr = r;
			r = r * (b / r);
			if(r < b)r += orgr;
			if(r <= d){
				cout<<l<<" "<<r<<endl;
				out = 1;
				break;
			}
		}
		if(!out){
			cout<<"-1 -1"<<endl;
		}
	}
	//xy = k(ab)  x=ma,y=nb|x=mb,y=na
	return 0;
}

