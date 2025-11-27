#include<bits/stdc++.h>
using namespace std;
int i,j,ans,n,k,t[1000],DOSTH,cnn,a[1000],b[1000],c,atail,btail,asum,bsum;
int m[2006110],mtail,cha;
bool comp(int a,int b){
	return a > b;
}
int main(){
	freopen("cook.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>t[i];
	}
	sort(t,t+n);
	for(i = 0;i < n;i++){
		if(asum <= bsum){
			a[atail] = t[i];
			atail++;
			asum += t[i];
		}else{
			b[atail] = t[i];
			btail++;
			bsum += t[i];
		}
	}
	if(asum == bsum){
		cout<<asum;
		return 0;
	}
	if(asum > bsum){
		cha = asum - bsum;
		for(i = 0;i < atail;i++){
			
		}//1 3 5 
	}    //2 4 6
	return 0;
}
//3 3 4 5 6
//12
//4 5 6 6
//4
//5
//(6)
