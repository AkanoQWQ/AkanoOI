#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int totsiz;
struct Query{
	bool type;//0 = Add  1 = Free
	int t,m,p;
	Query(){type = 0,t = m = p = 0;}
	Query(bool _type,int _t,int _m,int _p){
		type = _type,t = _t,m = _m,p = _p;
		return ;
	}
	//Add : t,m,p 按照题意
	//Free : t 恢复的时间,p起始位置,m大小 
};
bool operator<(Query q1,Query q2){
	if(q1.t != q2.t)return q1.t < q2.t;
	if(q1.type != q2.type)return q1.type > q2.type;
	return q1.p < q2.p;
}
struct Memory{
	int st,siz;
	Memory(){}
	Memory(int _st,int _siz){
		st = _st,siz = _siz;
		return ;
	}
};
set<Memory> memory;
set<Query> st;
queue<Query> q;
inline void Execute(Query cmd){
	if(cmd.type == false){
		
	}else{
		auto it = memory.insert(Memory(cmd.))
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>totsiz;
	while(true){
		int t,m,p;
		cin>>t>>m>>p;
		if(t == 0 && m == 0 && p == 0)break;
		st.insert(Query(false,t,m,p));
	}
	while(!(st.empty() || q.empty())){
		while(!q.empty()){
			const auto tp = q.front();
			bool suc = AllocateMemory(tp);
			if(suc){
				q.pop();
			}else{
				break;
			}
		}
		auto tp = *st.begin();
		st.erase(st.begin());
		Execute(tp);
	}
	return not(Akano loves pure__Elysia);
}
