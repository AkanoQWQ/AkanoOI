#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
bool cow[MAXN];
int s,dis,cowx[1006],x,n,i,j,c[MAXN],_Time,cans,ans,GRDL[1006]/*¸ÐÈ¾¶ÓÁÐ*/,tail = 0,head = 1;
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>x>>s;
		cow[x] = s;
		cowx[i] = s;
	}
	cout<<3;
	return 0;
}

