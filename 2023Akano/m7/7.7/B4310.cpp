#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
int k,ans;
string ins;
inline vi KMP(const string& str,const int& ST){
	const int len = str.length() - ST;
	vi pi(len);
	for(int i = 1;i < len;i++){
		int j = pi[i-1];
		while(j && str[i + ST] != str[j + ST])j = pi[j-1];
		if(str[i + ST] == str[j + ST])++j;
		pi[i] = j;
	}
	return pi;
}
vi pi;
int main(){
	freopen("B4310.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>ins>>k;
	for(int ST = 0;ST < ins.length();ST++){
		pi = KMP(ins,ST);
		for(int i = 0;i < pi.size();i++){
			int j = pi[i];
			while(j){
				if(j < k)break;
				if(2*j+1 <= i+1){
					++ans;
					break;
				}
				j = pi[j-1];
			}
		}
	}
	cout<<ans;
	return 0;
}
