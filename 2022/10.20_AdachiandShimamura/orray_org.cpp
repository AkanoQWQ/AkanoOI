#include<bits/stdc++.h>
using namespace std;
int t,n;
struct lb{
	int v,lst,nxt,orgv;
	bool used;
}l[200006];
int main(){
	std::ios::sync_with_stdio(false);
	//freopen("G.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		//memset();
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>l[i].v;
			l[i].orgv = l[i].v;
			l[i].lst = i-1;
			l[i].nxt = i+1;
			l[i].used = 0;
		}
		l[0].nxt = 1;
		for(int i = 1;i <= n;i++){
			int pos = 0,maxv = 0,maxpos = 0;
			while(pos != n+1){
				//cout<<pos<<endl;
				if(l[pos].v > maxv){
					maxv = l[pos].v;
					maxpos = pos;
				}
				pos = l[pos].nxt;
				if(pos == 0)break;
			}
			pos = 0;
			while(pos != n+1){
				l[pos].v -= (l[pos].v & maxv);
				pos = l[pos].nxt;
				if(pos == 0)break;
			}
			if(maxv == 0){
				break;
			}
			//cout<<"   USE "<<maxpos<<endl;
			l[maxpos].used = 1;
			cout<<l[maxpos].orgv<<" ";
			l[l[maxpos].lst].nxt = l[maxpos].nxt;
			l[l[maxpos].nxt].lst = l[maxpos].lst;
		}
		for(int i = 1;i <= n;i++){
			if(l[i].used == 0){
				cout<<l[i].orgv<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
