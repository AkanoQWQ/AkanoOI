#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
int T,n,m,q,pos[MAXN],dir[MAXN],cnt,delta;
bool imp[MAXN];
string str;
set<int> st,ask,give,askOK,giveOK;
inline void Update(){
	bool changed = true;
	while(changed){
		changed = false;
		while(!give.empty() && !ask.empty() && (*give.rbegin()) > (*ask.begin())){//ask Merge give
			giveOK.insert(*give.rbegin()),askOK.insert(*ask.begin());
			auto del_give = give.find(*give.rbegin());
			auto del_ask = ask.begin();
			give.erase(del_give),ask.erase(del_ask);
			changed = true;
		}
		while(!giveOK.empty() && !askOK.empty() && (*askOK.rbegin()) > (*giveOK.begin())){//Demerge ask give
			give.insert(*giveOK.begin()),ask.insert(*askOK.rbegin());
			auto del_giveOK = giveOK.begin();
			auto del_askOK = askOK.find(*askOK.rbegin());
			giveOK.erase(del_giveOK),askOK.erase(del_askOK);
			changed = true;
		}
	}
	return ;
}
inline void Change(int x){
	if(imp[x]){
		x = dir[x];
	}else{
		x = x + delta;
	}
	if(give.find(x) != give.end()){
		auto del_give = give.find(x);
		if(x < delta)ask.insert(*del_give);
		give.erase(del_give);
	}else if(ask.find(x) != ask.end()){
		auto del_ask = ask.find(x);
		give.insert(*del_ask);
		ask.erase(del_ask);
	}else if(askOK.find(x) != askOK.end()){
		auto del_askOK = askOK.find(x);
		auto del_giveOK = giveOK.begin();
		give.insert(*del_askOK),give.insert(*del_giveOK);
		askOK.erase(del_askOK),giveOK.erase(del_giveOK);
	}else if(giveOK.find(x) != giveOK.end()){
		auto del_giveOK = giveOK.find(x);
		auto del_askOK = askOK.find(*askOK.rbegin());
		ask.insert(*del_giveOK),ask.insert(*del_askOK);
		giveOK.erase(del_giveOK),askOK.erase(del_askOK);
	}else{
		give.insert(x);
	}
	return ;
}
int main(){
	freopen("D.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>q;
	delta = 2 * n; 
	for(int i = 1;i <= n;i++){
		pos[i] = 0;
		st.insert(i);
	}
	cin>>str;
	str = "." + str;
	while(m--){
		int l,r;
		cin>>l>>r;
		while(!st.empty()){
			auto it = st.lower_bound(l);
			if(it == st.end() || (*it) > r)break;
			imp[*it] = true;
			pos[++cnt] = (*it);
			dir[*it] = cnt;
			st.erase(it);
		}
	}
	for(int i = 1;i <= cnt;i++){
		if(str[pos[i]] == '0'){
			ask.insert(i);
		}else{
			give.insert(i);
		}
	}
	for(int i = 1;i <= n;i++){
		if(!imp[i] && str[i] == '1'){
			give.insert(i+delta);//unimportant : i -> i+n
		}
	}
	Update();
	while(q--){
		int inx;
		cin>>inx;
		Change(inx);
		Update();
		cout<<askOK.size()<<endl;
	}
	return 0;
}

