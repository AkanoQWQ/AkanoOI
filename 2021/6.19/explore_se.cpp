#include<bits/stdc++.h>
using namespace std;
int n,k,e[30006],ne,su/*Ä¿±ê*/,kk,i,mmax = -1;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(i = 0;i < n;i++){
		scanf("%d",&e[i]);
		mmax = max(mmax,e[i]);
	}
	int ne = mmax * 10;
	while(ne > 0){
		i = 0;
		kk = 0;
		su = ne;
		while(i < n){
			su -= e[i];
			i++;
			if(su <= 0){	
				su = ne;
				kk++;
			}
		}
		if(kk >= k){
			cout<<ne;
			return 0;
		}
		ne--;
	}
	return 0;
}
//20 5
//12 11 30 22 55 33 22 29 11 23 43 23 67 11 9 1 89 1 64 20

