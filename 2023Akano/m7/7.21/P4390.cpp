#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
struct Node{
	int id,x,y,val;
	inline void ReadIn(int _id){
		cin>>x>>y>>val;
		id = _id;
		return ;
	}
}nodes[MAXN];
int n = 0,cnt = 0,opt;
using pivn = pair<int,vector<Node> >;
struct Query{
	int _x1,_y1,_x2,_y2;
	inline void ReadIn(){
		cin>>_x1>>_y1>>_x2>>_y2;
		return ;
	}
};
queue<Query> q; 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(true){
		++cnt;
		cin>>opt;
		if(opt == 0){
			cin>>opt;
		}else if(opt == 1){
			nodes[++n].ReadIn(cnt);
		}else if(opt == 2){
			Query inq;
			inq.ReadIn();
			q.push(inq);
		}else{
			break;
		}
	}
	while(!q.empty()){
		const Query nowq = q.front();
		q.pop();
		cout<<CWQ(1,n).first<<endl;//CWQ ·ÖÖÎqwq 
	}
	return 0;
}

