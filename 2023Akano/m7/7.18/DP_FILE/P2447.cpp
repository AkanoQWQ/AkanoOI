#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1018;
using bsm = bitset<MAXN>;
int n,m,cnt = 0,q;
struct LinearBasis{
	bsm val[MAXN];
	inline bool Insert(bsm ins){
		for(int i = n;i >= 1;i--){
			if(ins == 0)return false;
			if(!ins[i])continue;
			if(val[i] == 0){
				val[i] = ins;
				return true;
			}else{
				ins ^= val[i];
			}
		}
		return false;
	}
}lb;
vector<bsm> line;
inline void Solve(){
	for(int i = 0;i < n;i++){
		int mx = i;
		for(int j = i;j < n;j++){
			if(line[j][i+1] == 1){
				mx = j;break;
			}
		}
		swap(line[i],line[mx]);
		for(int j = 0;j < n;j++){
			if(line[j][i+1] == 1 && i != j){
				line[j] ^= line[i];
			}
		}
	}
	for(int i = n-1;i >= 0;i--){
		if(line[i][0]){
			cout<<"?y7M#"<<endl;
		}else{
			cout<<"Earth"<<endl;
		}
	}
	return ;
}
bsm str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>str>>q;
		str <<= 1;
		str[0] = q;
		if(lb.Insert(str)){
			++cnt;
			line.push_back(str);
		}
		if(cnt == n){
			cout<<i<<endl;
			Solve();
			return 0;
		}
	}
	cout<<"Cannot Determine"<<endl;
	return 0;
}
