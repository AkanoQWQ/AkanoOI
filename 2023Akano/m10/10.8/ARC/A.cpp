#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int t,n;
string x,y;
stack<int> query;
queue<int> nowc;
inline bool Check(){
	queue<int> nowq;
	vector<int> vec;
	while(!query.empty()){
		vec.push_back(query.top());
		query.pop();
	}
	while(!vec.empty()){
		nowq.push(vec.back());
		vec.pop_back();
	}
	while(!nowq.empty()){
		while(!nowc.empty() && nowc.front() < nowq.front()){
			nowc.pop();
		}
		if(nowc.empty())return false;
		nowc.pop(),nowq.pop();
	}
	while(!nowc.empty())nowc.pop();
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		while(!query.empty())query.pop();
		while(!nowc.empty())nowc.pop();
		cin>>n>>x>>y;
		bool OK = true;
		for(int i = 0;i < n;i++){
			if(y[i] == 'B'){
				query.push(i);
			}
			if(x[i] == 'B'){
				if(query.empty()){
					OK = false;
				}else{
					query.pop();
				}
			}
			if(x[i] == 'C'){
				nowc.push(i);
			}
			if(y[i] == 'C'){
				if(x[i] != 'C'){
					OK = false;
				}
				OK &= Check();
			}
		}
		OK &= Check();
		if(OK){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
