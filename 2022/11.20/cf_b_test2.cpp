#include<bits/stdc++.h>
using namespace std;
const int MAXN = 106;
int t,n;
struct lb{
	int nxt,lst,v;
	bool del;
}a[MAXN];
void del(int pos){
	a[a[pos].nxt].lst = a[pos].lst;
	a[a[pos].lst].nxt = a[pos].nxt;
	a[pos].del = 1;
	return ;
}
bool vis[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i].v;
			a[i].lst = i-1;
			a[i].nxt = i+1;
			a[i].del = 0;
		}
		a[1].lst = n;
		a[n].nxt = 1;
		if(n == 1){
			cout<<1<<endl;
			continue;
		}
		int cp = 1;
		memset(vis,0,sizeof(vis));
		do{
			if(a[cp].v == a[a[cp].nxt].v){
				del(cp);
			}
			vis[cp] = 1;
			cp = a[cp].nxt;
		}while(vis[cp] == 0);
		while(1){
			int pos = 1;
			while(a[pos].del == 1 && pos <= n){
				pos++;
			}
			if(pos > n)break;
			int fd_not_del = pos;
			memset(vis,0,sizeof(vis));
			do{
				vis[pos] = 1;
				if(a[a[pos].lst].v != a[a[pos].nxt].v){
					fd_not_del = pos;
				}
				pos = a[pos].nxt;
			}while(vis[pos] == 0);
			del(fd_not_del);
			ans++;
			pos = 1;
			while(a[pos].del == 1 && pos <= n){
				pos++;
			}
			if(pos > n)break;
			if(a[pos].lst == pos){
				ans++;
				break;
			}
			memset(vis,0,sizeof(vis));
			do{
				if(a[pos].v == a[a[pos].nxt].v){
					del(pos);
				}
				vis[pos] = 1;
				pos = a[pos].nxt;
			}while(vis[pos] == 0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
