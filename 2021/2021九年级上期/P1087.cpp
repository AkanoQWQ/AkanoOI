#include<bits/stdc++.h>
using namespace std;
int m,n,w[200006],i,tail,tail2,head,ans,j,ts;
bool FIN[200006];
int main(){
	//freopen("P1087.in","r",stdin);
	//freopen(".out","w",stdout);
	while(cin>>n>>m){
		ts++;
		memset(FIN,0,sizeof(FIN));
		memset(w,0,sizeof(w));
		tail = 0,tail2 = 0,head = 0,ans = 0,j = 0,i = 0;
		for(i = 0;i < n;i++){
			cin>>w[i];
		}
		tail2 = m,head = 0;
		while(head < n){
			tail = tail2;
			for(j = head;j < tail;j++){
				if(FIN[j] == 1){
					if(j == head)head++;
					continue;
				}
				w[j]--;
				if(w[j] <= 0){
					//cout<<"µÚ"<<ans<<"Ãë,"<<j<<"Íê³É"<<endl;
					tail2++,FIN[j] = 1;
					if(j == head)head++;
				}
			}
			ans++;
		}
		if(ts == 1)cout<<ans;
		if(ts > 1)cout<<endl<<endl<<ans;
	}
	
	return 0;
}

