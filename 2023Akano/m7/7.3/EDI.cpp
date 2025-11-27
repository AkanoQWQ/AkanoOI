#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define IT unordered_map::iterator
ostream& operator<<(ostream& cout,const vi& vec){
	for(int ii = 0;ii < vec.size();ii++){
		int i = vec[ii];
		cout<<i<<" ";
	}
	return cout;
}
const int MAXN = 14;
const int offset = 3;//2^3 = 8,m/2 = 6
const int ADDNUM = 12;
int n,m,endx,endy;
char bar[MAXN][MAXN];
int EdgeTo[MAXN];
ll Encode(const vi& vec){
	ll ret = 0;
	for(int i = 1;i <= m;i++)EdgeTo[i] = -1;
	EdgeTo[0] = 0;int cnt = 0;
	for(int ii = 0;ii < vec.size();ii++){
		const int i = vec[ii];
		if(EdgeTo[i] == -1)EdgeTo[i] = ++cnt;
		ret <<= offset;
		ret += EdgeTo[i];
	}
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
unordered_map<ll,ll> now,nxt;
bool FD;
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>bar[i][j];
			if(bar[i][j] != '*'){
				endx = i,endy = j;
			}
		}
	}
	now[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(IT it = now.begin();it != now.end();it++){
				
			}
			for(auto stat_val : now){
				const ll stat = stat_val.first,val = stat_val.second;
				vi vstat = Decode(stat);
				if(bar[i][j] == '*'){
					if(vstat[j-1] == 0 && vstat[m] == 0){
						nxt[stat] += val;
					}
					continue;
				}//now bar is .
				if(vstat[j-1] == 0 && vstat[m] == 0){
					vstat[j-1] = vstat[m] = m;//OK ? 
					const ll newstat = Encode(vstat);
					nxt[newstat] += val;
				}else if(vstat[j-1] != 0 && vstat[m] != 0){
					if(vstat[j-1] == vstat[m]){
						vstat[j-1] = vstat[m] = 0;
						if(i == endx && j == endy){
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
			if(i == endx && j == endy)FD = 1;
			if(FD)break;
		}
		if(FD)break;
		for(auto stat_val : now){
			const ll stat = stat_val.first,val = stat_val.second;
			const vi vstat = Decode(stat);
			if(vstat[m] == 0){
				nxt[stat] = val;
			} 
		}
		now = nxt;nxt.clear();
	}
	cout<<now[0]<<flush;
	return 0;
}
