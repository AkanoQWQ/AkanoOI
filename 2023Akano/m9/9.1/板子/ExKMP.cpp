#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using vi = vector<int>;
string a,b;
inline int BF(int pos,int now,const string& str){
	while(pos+(now+1)-1 < str.length() && str[now+1-1] == str[pos+now+1-1])now++;
	return now;
}
inline vi ExKMP(const string& str){
	const int len = str.length();
	vi z(len);
	int l = 0,r = 0;
	for(int i = 1;i < len;i++){
		if(i <= r && z[i-l] < r-i+1){
			z[i] = z[i-l];
		}else{
			z[i] = max(0,r-i+1);
			z[i] = BF(i,z[i],str);
		}
		if(r < i + z[i] - 1){
			l = i,r = i + z[i] - 1;
		}
	}
	return z;
}
long long ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b;
	vi z = ExKMP(b + "#" + a);
	int blen = b.length();
	z[0] = blen;
	for(int i = 0;i < blen;i++){
		ans ^= 1ll * (i+1) * (z[i]+1);
	}
	cout<<ans<<endl;
	ans = 0;
	for(int i = blen+1;i < int(z.size());i++){//blenÉÏÊÇ·Ö¸ô·û 
		ans ^= 1ll * (i-blen) * (z[i]+1);
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}

