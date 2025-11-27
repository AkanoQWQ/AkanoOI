#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
const int BASES[5] = {67,71,73,79,83};
const int MODS[5] = {100057,197597,319733,519391,817379};
const int SZ = 4;
const int MAXM = 817383;
int Trans(char ch){//Size 62
	if(isdigit(ch))return ch - '0';
	if('a' <= ch && ch <= 'z')return (ch - 'a') + 10;
	if('A' <= ch && ch <= 'Z')return (ch - 'A') + 36;
}
int Hash(string str,int base,int mod){
	int ret = 0;
	for(auto i : str){
		ret = (1ll * ret * base + Trans(i)) % mod;
	}
	return ret;
}
int n,cnt;
string ins;
bitset<MAXM> vis[SZ]; 
bool ISP(int val){
	for(int i = 2;i <= sqrt(val);i++){
		if(val % i == 0)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		cin>>ins;
		bool NOT_FOUND = false;
		for(int i = 0;i < SZ;i++){
			const int MOD = Hash(ins,BASES[i],MODS[i]);
			if(!vis[i][MOD])NOT_FOUND = true;
			vis[i][MOD] = true;
		}
		cnt += NOT_FOUND;
	}
	cout<<cnt<<endl;
	return 0;
}

