#include<bits/stdc++.h>
using namespace std;
const int maxn = 14210;
struct tree{
	int children[maxn],num;
}t[maxn];
int f[maxn][2],i,j,a,b,c,n,root,k,r[maxn],l;
bool isroot[maxn];
int dp(int x){
	int ii,kk,y,l;
	l = t[x].num;
	f[x][0] = 0;
	f[x][1] = r[x];
	for(ii = 0;ii < l;ii++){
		y = t[x].children[ii];
		dp(y);
		f[x][0] += max(f[y][0],f[y][1]);
		f[x][1] += f[y][0];
	}
	//cout<<x<<"的最佳方案为"<<max(f[x][0],f[x][1])<<endl;
	return 0;
}
int main(){
	freopen("party.in","r",stdin);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>r[i];
		isroot[i] = 1;
	}
	for(i = 1;i < n;i++){
		cin>>l>>k;
		t[k].children[t[k].num] = l;
		t[k].num++;
		isroot[l] = 0;
	}
	cin>>l>>k;
	/*
	for(i = 0;i < n;i++){
		cout<<i<<"有"<<t[i].num<<"个孩子"; 
		for(int j = 0;j < t[i].num;j++){
				cout<<","<<t[i].children[j];
		}
		cout<<endl;
	} */
	for(i = 1;i <= n;i++){
		if(isroot[i] == 1){
			root = i;
			//cout<<"root is:"<<root<<endl;
			break;
		}
	}
	
	dp(root);
	cout<<max(f[root][0],f[root][1]);
	return 0;
}

