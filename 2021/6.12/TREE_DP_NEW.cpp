#include<bits/stdc++.h>
using namespace std;
int l;
string s1,s2;

void dfs(int l1,int l2,int l3,int l4){
	if(l1 > l2 || l3 > l4){
		return ;
	}
	for(int i = l1;i <= l2;i++){
		if(s1[i] == s2[l3]){
			dfs(l1,i-1,l3+1,l3+i+l1);
			dfs(i+1,l2,l3+i-l1+1,l4);
			cout<<s1[i];
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>s1>>s2;
	l = s1.length();
	dfs(0,l-1,0,l-1);
	return 0;
}
