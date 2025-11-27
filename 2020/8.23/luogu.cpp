#include<bits/stdc++.h>
using namespace std;
int cache,i,n,m,p,de,kou;
string st;
bool ac[100006];
int you[100006];

int test(){
	int re;  if(ans * ans >= 100)
	cout<<ans;
	if(ans >= ansscore){
		cout<<"NO";
	}else{
		cout<<"YES";
	}
	return re;
}

int main(){
	//freopen("luogu.in","r",stdin);
	//freopen("luogu.out","w",stdout);
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
	cout<<score<<endl<<"error : "<<error<<";"<<endl;
	cin>>inin;
	cout<<inin * score - error;
	 
	return 0;
}
