#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
int n,m;
string str,ans;
bool arr[MAXN];
inline string Solve(){
	string ret;
	int now = 0;
	for(int i = 1;i <= n;i++){
		if(str[i] == '?'){
			arr[i] = 0;
		}else{
			arr[i] = str[i] - '0';
		}
		if(i != 1)now += (arr[i] != arr[i-1]);
	}
	if(abs(m - now) % 2 != 0){
		for(int i = 1;i <= n;i++)ret += "2";
		return ret;
	}
	if(now < m){
		for(int i = n-1;i >= 2 && now < m;i--){
			if(arr[i+1] == 0 && arr[i-1] == 0 && str[i] == '?'){
				arr[i] = 1;
				now += 2;
			}
		}
	}
	if(now > m){
		for(int i = n,lst = -1;i >= 1 && now > m;i--){
			if(str[i] != '?'){
				if(lst != -1 && str[i] == '1' && str[lst] == '1' && lst != i+1){
					for(int j = i+1;j < lst;j++)arr[j] = 1;
					now -= 2;
				}
				lst = i;
			}
		}
	}
	if(now != m){
		for(int i = 1;i <= n;i++)ret += "2";
	}else{
		for(int i = 1;i <= n;i++)ret += char(arr[i] + '0');
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	str = "." + str;
	for(int i = 1;i <= n;i++)ans += "2";
	if(str[1] == '?' && str[n] == '?'){
		str[1] = '0',str[n] = '0';
		ans = min(ans,Solve());
		str[1] = '0',str[n] = '1';
		ans = min(ans,Solve());
		str[1] = '1',str[n] = '0';
		ans = min(ans,Solve());
		str[1] = '1',str[n] = '1';
		ans = min(ans,Solve());
	}else if(str[1] == '?'){
		str[1] = '0';
		ans = min(ans,Solve());
		str[1] = '1';
		ans = min(ans,Solve());
	}else if(str[n] == '?'){
		str[n] = '0';
		ans = min(ans,Solve());
		str[n] = '1';
		ans = min(ans,Solve());
	}else{
		ans = min(ans,Solve());
	}
	if(ans[0] == '2'){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
	return not(Akano loves pure__Elysia);
}
