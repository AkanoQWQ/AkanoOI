#include<bits/stdc++.h>
using namespace std;
int cache,i,n,m,p,de,kou;
string st;
bool ac[100006];
int you[100006];
int main(){
	freopen("judge.in","r",stdin);
	freopen("judge.out","w",stdout);
	cin>>n>>m;
	for(i = 0;i < m;i++){
		cin>>p;
		cin>>st;
		if(st == "AC"){
			if(!ac[p]){
				ac[p] = 1;
				de++;
			}
		}
		if(st == "WA"){
			if(!ac[p]){
				kou++;
			}
		}
		you[p]++;
	}
	for(i = 0;i < 100006;i++){
		if(you[i] && !ac[i]){
			kou -= you[i];
		}
	}
	cout<<de<<" "<<kou;
	return 0;
}
