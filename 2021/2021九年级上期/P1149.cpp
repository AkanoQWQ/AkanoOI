#include<bits/stdc++.h>
using namespace std;
const int MN = 100006;
const int INF = 1<<30;
int n,i;
long long c[MN],leftist,rightist,mc = INF,ans,ch,cache,m,p1,s1,s2;
int main(){
	//freopen("P1149.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>c[i];
	}
	cin>>m>>p1>>s1>>s2;
	c[p1] += s1;
	for(i = 1;i < m;i++){
		leftist += c[i] * (m-i);
	}
	for(i = m+1;i <= n;i++){
		rightist += c[i] * (i-m);
	}
	ch = leftist - rightist;
	for(i = 1;i < m;i++){
		cache = (m-i) * s2;
		if(abs(ch + cache) < mc){
			//cout<<ch<<"+"<<cache<<"<"<<mc<<endl;
			mc = abs(ch + cache);
			ans = i;
		}
	}
	for(i = m+1;i <= n;i++){
		cache = (i-m) * s2;
		if(abs(ch - cache) < mc){
			//cout<<ch<<"-"<<cache<<"<"<<mc<<endl;
			mc = abs(ch - cache);
			ans = i;
		}
	}
	if(ch == 0)ans = m;
	cout<<ans;
	return 0;
}

