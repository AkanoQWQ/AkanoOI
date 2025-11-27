#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
ll n,m,t,tot,mn;
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		ll nowtot = 0,nowmn = 0;
		cin>>str>>t;
		for(auto ch : str){
			if(ch == 'M'){
				nowtot++;
			}else{
				nowtot--;
			}
			nowmn = min(nowmn,nowtot);
		}
		if(nowtot >= 0){
			mn = min(mn,tot + nowmn);
		}else{
			mn = min(mn,tot + (t-1) * nowtot + nowmn);
		}
		tot += t * nowtot;
	}
	if(tot-1 >= 0){
		cout<<-1<<endl;
	}else{
		cout<<max(0ll,tot-1-mn)<<endl;
	}
	return not(Akano loves pure__Elysia);
}
