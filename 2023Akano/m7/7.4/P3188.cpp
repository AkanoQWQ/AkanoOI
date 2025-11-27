#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXN = 106;
int n,w,cost,v;
unordered_map<int,int> dp[2];
int now = 0,nxt = 1;
vector<pair<int,int> > vec;
bool cmp(pair<int,int> pa,pair<int,int> pb){
	if(pa.first == pb.first)return pa.second < pb.second;
	return pa.first > pb.first;
}
int main(){
	freopen("P3188.in","r",stdin);
	freopen("P3188.out","w",stdout);
	while(1){
		n = Read(),w = Read();
		if(n == -1 && w == -1)break;
		dp[0].clear(),dp[1].clear();
		vec.reserve(n);
		dp[nxt][w] = 0;
		for(int i = 1;i <= n;i++){
			swap(now,nxt);
			dp[nxt].clear();
			cost = Read(),v = Read();
			vec.clear();
			for(auto j : dp[now]){
				const int nowv = j.first,val = j.second;
				if(nowv - cost > 0)vec.push_back(make_pair(nowv-cost,val+v));
				vec.push_back(make_pair(nowv,val));
			}
			sort(vec.begin(),vec.end(),cmp);
			int mxval = 0;
			for(auto j : vec){
				mxval = max(mxval,j.second);
				if(j.second < mxval)continue;
				dp[nxt][j.first] = max(dp[nxt][j.first],j.second);
			}
		}
		int ans = 0;
		for(auto i : dp[nxt]){
			ans = max(ans,i.second);
		}
		Write(ans),edl;
	}
	return 0;
}

