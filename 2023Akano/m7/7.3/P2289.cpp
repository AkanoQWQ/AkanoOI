#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using lll = __int128;
ostream& operator<<(ostream& cout,const vi& vec){
	for(auto i : vec)cout<<i<<" ";
	return cout;
}
void Write(lll _x){
	if(_x > 9)Write(_x / 10);
	putchar((_x % 10) + '0');
	return ;
}
ostream& operator<<(ostream& cout,const lll& _lll){
	Write(_lll);
	return cout;
}
const int MAXN = 14;
const int offset = 3;//2^3 = 8,m/2 = 6
const int ADDNUM = 12;
int n,m;
int EdgeTo[MAXN];
ll Encode(const vi& vec){
	ll ret = 0;
	for(int i = 1;i <= m;i++)EdgeTo[i] = -1;
	EdgeTo[0] = 0;int cnt = 0;
	for(auto i : vec){
		if(EdgeTo[i] == -1)EdgeTo[i] = ++cnt;
		ret <<= offset;
		ret += EdgeTo[i];
	}
	if(cnt >= m)cout<<"ERR";
	return ret;
}
vector<int> Decode(ll s){
	vi ret;
	for(int i = 1;i <= m+1;i++){
		ret.push_back(s % (1<<offset));
		s >>= offset;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
unordered_map<ll,lll> now,nxt;
bool FD;
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>m>>n;
	if(n == 1 || m == 1){
		cout<<1<<flush;return 0;
	}
	now[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(auto stat_val : now){
				const ll stat = stat_val.first;
				lll val = stat_val.second;
				vi vstat = Decode(stat);
				if(vstat[j-1] == 0 && vstat[m] == 0){
					vstat[j-1] = vstat[m] = m;//OK ? 
					const ll newstat = Encode(vstat);
					nxt[newstat] += val;
				}else if(vstat[j-1] != 0 && vstat[m] != 0){
					if(vstat[j-1] == vstat[m]){
						vstat[j-1] = vstat[m] = 0;
						if(i == n && j == m){
							nxt[Encode(vstat)] += val; 
						}
					}else{
						const int val1 = vstat[j-1],val2 = vstat[m];
						for(auto& i : vstat){
							if(i == val1 || i == val2)i = m;//OK ?
						}
						vstat[j-1] = vstat[m] = 0;
						nxt[Encode(vstat)] += val; 
					}
				}else{
					const int no = vstat[j-1] + vstat[m];
					vstat[j-1] = no,vstat[m] = 0;//加入下插头
					nxt[Encode(vstat)] += val;
					vstat[j-1] = 0,vstat[m] = no;
					nxt[Encode(vstat)] += val; 
				}
			}
			now = nxt;nxt.clear();
		}
		for(auto stat_val : now){
			const ll stat = stat_val.first;
			lll val = stat_val.second;
			const vi vstat = Decode(stat);
			if(vstat[m] == 0){
				nxt[stat] = val;
			} 
		}
		now = nxt;nxt.clear();
	}
	cout<<now[0]*2<<flush;
	return 0;
}
