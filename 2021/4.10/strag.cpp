#include<bits/stdc++.h>
using namespace std;
const int maxn = 2006;
struct tree{
	int children[maxn],num;
}t[maxn];
int f[maxn][2],i,j,a,b,c,n,root,k;
bool isroot[maxn];
int dp(int x){
	int ii,kk,y,l;
	l = t[x].num;
	f[x][0] = 0;
	f[x][1] = 1;
	//cout<<"正在遍历"<<x<<","<<x<<"有"<<l<<"个孩子";
	for(kk = 0;kk < l;kk++){
	//cout<<","<<t[x].children[kk];
	}
	//cout<<endl;
	for(ii = 0;ii < l;ii++){
		y = t[x].children[ii];
		dp(y);
		f[x][0] += f[y][1];
		f[x][1] += min(f[y][0],f[y][1]);
	}
	return 0;
}
int main(){
	freopen("strag.in","r",stdin);
	cin>>n;
	for(i = 0;i < n;i++){
		isroot[i] = 1;
	}
	for(i = 0;i < n;i++){
		cin>>a;
		//cout<<"输入a:"<<a<<",";
		cin>>t[a].num;
		//cout<<"num:"<<t[a].num;
		for(j = 0;j < t[a].num;j++){
				cin>>t[a].children[j];
				//cout<<"第"<<j<<"个child:"<<t[a].children[j];
				isroot[t[a].children[j]] = 0;
		}
		//cout<<endl;
	}
	/*cout<<"root is:"<<root<<endl;
	for(i = 0;i < n;i++){
		cout<<i<<"有"<<t[i].num<<"个孩子"; 
		for(int j = 0;j < t[i].num;j++){
				cout<<","<<t[i].children[j];
		}
		cout<<endl;
	} */
	for(i = 0;i < n;i++){
		if(isroot[i] == 1){
			root = i;
			break;
		}
	}
	dp(root);
	cout<<min(f[root][0],f[root][1]);
	return 0;
}

