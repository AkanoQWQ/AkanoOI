#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1018 + 1108;
const int MOD = 998244353;
int n;
string s;
ll ans,cnt0,tail,stm;
bool now0;
struct Node{
	ll cnt1,x;
}node[MAXN];
inline bool ALL1(){
	for(auto i : s){
		if(i != '1')return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("E.in","r",stdin);
	cin>>n>>s;
	if(n == 1){
		cout<<0<<endl;
		return 0;
	}
	int st = 0;
	if(s[0] != '1'){//?
		ans++;
		st = 1;
		if(s[1] != '1'){
			cout<<-1<<endl;
			return 0;
		}
	}
	if(ALL1()){
		cout<<n-1<<endl;
		return 0;
	}
	now0 = true,cnt0 = 0;
	for(int i = st;i < n;i++){
		if(s[i] == '1'){
			if(!now0){
				now0 = true;
			}
			cnt0++;
		}else{
			if(!now0){
				cout<<-1<<endl;
				return 0;
			}
			++tail;
			node[tail].cnt1 = cnt0;
			node[tail].x = s[i] - '0';
			now0 = false,cnt0 = 0;
		}
	}
	if(now0){
		stm += cnt0;
	}
	for(int i = tail;i >= 1;i--){
		++stm;
		node[i].cnt1 = (node[i].cnt1 + (node[i].x-1) * (stm)) % MOD;
		stm = (stm + node[i].cnt1) % MOD;
	}
	ll finans = stm + ans - 1;
	finans = ((finans % MOD) + MOD) % MOD;
	cout<<finans<<endl;
	return 0;
}
