#include<bits/stdc++.h>
using namespace std;
int n = 3000,fa[3006];
int getfa(int p){
	if(fa[p] == p)return p;
	fa[p] = getfa(fa[p]);
	return fa[p];
}
int main(){
	freopen("count.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		fa[i] = i;
		cout<<rand()%1000<<" "; 
	}
	cout<<endl;
	for(int i = 1;i < n;i++){
		int l = 1,r = 1;
		while(getfa(l) == getfa(r)){
			l = rand()%n+1,r = rand()%n+1; 
		}
		fa[getfa(l)] = getfa(r);
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}

