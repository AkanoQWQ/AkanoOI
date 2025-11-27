#include<bits/stdc++.h>
using namespace std;
int a,b,c;
bool vis[20000006];
queue<int> q;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	q.push(0);
	while(1){
		memset(vis,false,sizeof(vis));
		//for(int i = 0;i < 20000004;i++){
		//	if(vis[i])cout<<"test"<<endl;
		//}
		while(!q.empty())q.pop();
		q.push(0);
		cin>>a>>b;
		while(!q.empty()){
			//cout<<"vis"<<c<<endl;
			c = q.front();
			q.pop();
			if(!vis[c+a] && c+a <= 20000000){
				vis[c+a] = 1;
				q.push(c+a);
			}
			if(!vis[c+b] && c+b <= 20000000){
				vis[c+b] = 1;
				q.push(c+b);
			}
		}
		for(int i = 19999999;i >= 0;i--){
			if(vis[i] == 0){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}

