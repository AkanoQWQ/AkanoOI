#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
inline int BF(const int& pos,int now,const string& str){
	while(pos + now < str.length() && str[pos+now] == str[now])++now;
	return now;//now include pos itself so we dont "-1"
}
inline vi ExKMP(const string& str){
	int ret = 0,len = str.length(),l = 0,r = 0;
	vi d(len);
	for(int i = 1;i < len;i++){
		int k = 0;
		if(i <= r && d[i-l] < r - i + 1){
			k = d[i-l];
		}else{			
			k = max(r-i+1,0);
			k = BF(i,k,str);
		}
		if(i + k - 1 > r){
			l = i,r = i + k - 1;
		}
		d[i] = k;
	}
	d[0] = str.length();
	return d;
}
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
string a,b;
long long otp1,otp2;
int main(){
	freopen("P5410_2.in","r",stdin);
	cin>>a>>b;
	vi ans1 = ExKMP(b);
	vi ans2 = ExKMP(b + "." + a);
	for(int i = 0;i < ans1.size();i++){
		otp1 ^= 1ll * (i+1) * (ans1[i]+1);
	}
	cout<<otp1<<endl;
	for(int i = 0;i < a.length();i++){
		const int u = b.length()+i+1;
		otp2 ^= 1ll * (i+1) * (ans2[u]+1);
	}
	cout<<otp2<<endl;
	return 0;
}
