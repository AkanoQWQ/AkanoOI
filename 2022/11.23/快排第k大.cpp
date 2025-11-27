#include<bits/stdc++.h>
using namespace std;
const int MAXN = 12006;
int n,k,a[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int len = unique(a+1,a+n+1) - a - 1;
	if(k > len){
		puts("NO RESULT");
	}else{
		cout<<a[k];
	}
	return 0;
}

