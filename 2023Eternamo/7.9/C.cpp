#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll fir,sec;
	inline void SWP(){
		swap(fir,sec);
		return ;
	}
	Node(){fir = sec = 0;}
	Node(ll _a,ll _b){fir = _a,sec = _b;}
};
bool operator<(Node a,Node b){
	if(a.fir - a.sec == b.fir - b.sec)return a.fir < b.fir;
	return (a.fir - a.sec) > (b.fir - b.sec);
}
set<Node> st;
ll n,a,b,ans; 
inline void Print(){
	for(auto i : st){
		cout<<i.fir<<","<<i.sec<<" VAL "<<i.fir-i.sec<<endl;
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		st.insert(Node(a,b));
	}
	while(!st.empty()){
		auto imp = st.begin();
		auto node = *imp;node.SWP();
		st.erase(imp),st.insert(node);
		auto imp2 = st.begin();
		ans += (*imp2).fir;
		st.erase(imp2);
	}
	cout<<ans<<endl;
	return 0;
}
