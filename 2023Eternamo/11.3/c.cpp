#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n;
long long ans = 0;
string str;
map<int,int> f[7][7];
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>str;
		ans++;
		int len = str.length();
		for(int j = 1;j <= 5;j++){
			if((j + len) % 2 != 0)continue;
			const int mid = (j + len) / 2;
//			cerr<<" in len "<<mid<<endl;
			if(len == mid){
				int sum = 0;
				for(auto ch : str)sum += ch - '0';
				ans += f[len][j][sum] * 2;
				f[j][len][sum]++;
			}else if(len < mid){
				int sum = 0;
				for(auto ch : str)sum += ch - '0';
				ans += f[len][j][sum];
//				cerr<<str<<" sum "<<sum<<" got "<<f[len][j][sum]<<endl;
				f[j][len][sum]++;
			}else if(len > mid){
				int sum = 0,res = 0,delta = len - mid;
				for(int now = 0;now < delta;now++){
					res += str[now] - '0';
				}
				for(int now = delta;now < len;now++){
					sum += str[now] - '0';
				}
				ans += f[len][j][sum - res];
				f[j][len][sum - res]++;
//				cerr<<str<<" in "<<mid<<" sum "<<sum<<" res "<<res<<" got "<<f[len][j][sum - res]<<endl;
				
				sum = 0,res = 0,delta = len - mid;
				for(int now = len-1-delta;now >= 0;now--){
					sum += str[now] - '0';
				}
				for(int now = len-1;now > len-1-delta;now--){
					res += str[now] - '0';
				}
				ans += f[len][j][sum - res];
				f[j][len][sum - res]++;
//				cerr<<str<<" in "<<mid<<" sum "<<sum<<" res "<<res<<" got "<<f[len][j][sum - res]<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
