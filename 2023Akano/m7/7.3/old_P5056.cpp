#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
ostream& operator<<(ostream& cout,const vi& vec){
	for(auto i : vec)cout<<i<<" ";
	return cout;
}
const int MAXN = 14;
const int offset = 3;//2^3 = 8,m/2 = 6
const int ADDNUM = 12;
int n,m;
char bar[MAXN][MAXN];
int EdgeTo[MAXN];
int Encode(const vi& vec){
	int ret = 0;
	for(int i = 1;i <= m;i++)EdgeTo[i] = -1;
	EdgeTo[0] = 0;int cnt = 0;
	for(auto i : vec){
		if(EdgeTo[i] == -1)EdgeTo[i] = ++cnt;
		ret <<= offset;
		ret += EdgeTo[i];
	}
	return ret;
}
vector<int> Decode(int s){
	vi ret;
	for(int i = 1;i <= m+1;i++){
		ret.push_back(s % (1<<offset));
		s >>= offset;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
unordered_map<int,int> now,nxt;
int main(){
	freopen("P5056.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>bar[i][j];
		}
	}
	now[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<i<<","<<j<<" is "<<endl;
			for(auto stat_val : now){
				const int stat = stat_val.first,val = stat_val.second;
				cout<<Decode(stat)<<" : "<<val<<endl;
				vi vstat = Decode(stat);
				if(bar[i][j] == '*'){
					if(vstat[j-1] == 0 && vstat[m] == 0){
						nxt[stat] += val;
					}
					continue;
				}//now bar is .
				if(vstat[j-1] == 0 && vstat[m] == 0){
					vstat[j-1] = vstat[m] = m;//OK ? 
					const int newstat = Encode(vstat);
					nxt[newstat] += val;
				}else if(vstat[j-1] != 0 && vstat[m] != 0){
					if(vstat[j-1] == vstat[m]){
						vstat[j-1] = vstat[m] = 0;
						if(i == n && j == m)nxt[Encode(vstat)] += val; 
					}else{
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
			const int stat = stat_val.first,val = stat_val.second;
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
