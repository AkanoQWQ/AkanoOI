#include<bits/stdc++.h>
using namespace std;//131072
string s;
int nums[131076],m,n,cache,i,j,k,nnum,l;
int main(){
	freopen("strs.in","r",stdin);
	freopen("strs.out","w",stdout);
	cin>>m>>n;
	for(i = 0;i < n;i++){
		cin>>s;
	}
	cout<<n;
	return 0;
}






/*
#include<bits/stdc++.h>
using namespace std;//131072
string s;
int nums[131076],m,n,cache,i,j,k,nnum,l;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>m>>n;
	for(i = 0;i < n;i++){
		cin>>s;        //s  10        l:2
		l = s.length();//j = 0
		nnum = 0;
		for(j = l-1;j >= 0;j--){
			cache = int(s[j])-48;
			for(k = l-1;k > j;k--){
				cache *= 2;
			}
			nnum += cache;
		}
		cout<<nnum<<" ";
	}
	return 0;
}

*/
