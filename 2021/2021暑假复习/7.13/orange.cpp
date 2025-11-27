#include<bits/stdc++.h>
using namespace std;
int a,b,w,i,mmax,mmin,l,r;
int main(){
	freopen("orange.in","r",stdin);
	freopen("orange.out","w",stdout);
	cin>>a>>b>>w;
	w *= 1000;
	mmax = (w/a)+2;
	while(1){
		mmax--;
		l = mmax * a;
		r = mmax * b;
		if(l <= w && w <= r){
			break;
		}
		if(mmax <= 0){
			cout<<"UNSATISFIABLE";
			return 0; 
		}
	}
	while(1){
		mmin++;
		l = mmin * a;
		r = mmin * b;
		if(l <= w && w <= r){
			break;
		}
	}
	cout<<mmin<<" "<<mmax;
	return 0;
}

