#include<bits/stdc++.h>
using namespace std;
int t,n;
struct lb{
	int v,orgv;
	bool used;
}l[200006];
int main(){
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>l[i].v;
			l[i].orgv = l[i].v;
			l[i].used = 0;
		}
		for(int i = 1;i <= n;i++){
			int maxv = 0,maxpos = 0;
			for(int pos = 1;pos <= n;pos++){
				if(l[pos].v > maxv){
					maxv = l[pos].v;
					maxpos = pos;
				}
			}
			for(int pos = 1;pos <= n;pos++){
				l[pos].v -= (l[pos].v & maxv);
			}
			if(maxv == 0){
				break;
			}
			l[maxpos].used = 1;
			cout<<l[maxpos].orgv<<" ";
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
