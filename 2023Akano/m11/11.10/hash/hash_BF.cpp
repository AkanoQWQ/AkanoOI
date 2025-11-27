#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
constexpr int MAXN = 1e6;
constexpr int TOT_MOD = 1e5;
vector<int> valvec;
int chval[28];
inline ull HashOverflow(const string& str){
	constexpr static int base = 27;
	ull ret = 0;
	for(auto i : str){
		ret = ret * base + i - 'a';
	}
	return ret % TOT_MOD;
}
inline ull HashMod(const string& str){
	constexpr static int base = 27;
	constexpr static int MOD = 998244353;
	ull ret = 0;
	for(auto i : str){
		ret = (ret * base + i - 'a') % MOD;
	}
	return ret % TOT_MOD;
}
constexpr ull newbase = 101811082121;
inline ull HashNew(const string& str){
	constexpr static int base = newbase;
	ull ret = 0;
	for(auto i : str){
		ret = ret * base + chval[i - 'a'];
	}
	return ret;
}
mt19937 rng(time(0));
int t = 1e6,cnt1,cnt2,cnt3;
string str;
Rander rd;
int n,l;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hack.in","r",stdin);
	for(int i = 1;i < newbase;i++){
		valvec.push_back(i);
	}
	shuffle(valvec.begin(),valvec.end(),rng);
	for(int i = 0;i < 26;i++){
		chval[i] = valvec[i];
	}
	cin>>str>>l;
	n = str.length();
	str = "." + str;
	vector<ull> vec;
	for(int i = 1;i+l-1 <= n;i++){
		ull hashval = 0;
		for(int j = 0;j < l;j++){
			hashval = hashval * newbase + chval[i - 'a'];
		}
		vec.push_back(hashval);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	cout<<vec.size()<<endl;
	return not(Akano loves pure__Elysia);
}
