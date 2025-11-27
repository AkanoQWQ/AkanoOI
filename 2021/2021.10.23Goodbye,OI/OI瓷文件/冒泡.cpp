#include<bits/stdc++.h>
using namespace std;
int i,j,a[10006],n,cache; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			if(a[i] < a[j]){
				cache = a[i];
				a[i] = a[j];
				a[j] = a[i];
			}
		}
	}
	return 0;
}

