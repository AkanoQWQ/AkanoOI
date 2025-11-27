#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXSIZE = 82;
const int MAXC = 28;
const ll INF = 1e9 * MAXN;
int tid,T,n,m,firstAppear[MAXC],lastAppear[MAXC],w[MAXN];
ll f[MAXSIZE][MAXN];
vector<int> wall;
string s,t;
bool del[28];
struct Status{
	char ch;
	int pos;
	ll val;
	Status() = default;
	Status(char _ch,int _pos,ll _val){
		ch = _ch,pos = _pos,val = _val;
		return ;
	}
};
inline ll Solve(){
	ll ret = 0;
	for(int i = 1;i <= n;i++)ret += w[i];
	int siz = int(wall.size()) - 1;
	for(int i = 0;i <= siz;i++){
		for(int j = 0;j <= n;j++){
			f[i][j] = -INF;
		}
	}
	for(int i = 0;i <= n;i++)f[1][i] = 0;
	for(int nowt = 1;nowt < siz;nowt++){//siz是m+1
		const int l = wall[nowt],r = wall[nowt+1] - 1;
		for(int i = 0;i < 26; ++i){
			if(firstAppear[i] != 0 && firstAppear[i] <= l && r <= lastAppear[i]){
				del[i] = false;
			}else{
				del[i] = true;
			}
		}
		vector<Status> notdel;
		notdel.emplace_back(Status('a',0,0));
		string delstr,objstr;
		for(int i = l;i <= r;i++){
			objstr += t[i];
		}
		for(int i = 1;i <= n;i++){
			if(del[s[i] - 'a'] == false){
				notdel.push_back(notdel.back());
				delstr += s[i];
				notdel.back().ch = s[i];
				notdel.back().pos = i;
				notdel.back().val += w[i];
			}
		}
		//KMP部分
		string str = objstr + "#" + delstr;
		int len = int(str.length()) - 1;
		vector<int> pi(len + 2);
		for(int i = 1;i <= len;i++){
			int j = pi[i-1];
			while(j && str[i] != str[j])j = pi[j-1];
			if(str[i] == str[j])j++;
			pi[i] = j;
			if(j == int(objstr.length())){
				const int pos = i - objstr.length() - 1 + 1;
				f[nowt+1][notdel[pos].pos] = max(f[nowt+1][notdel[pos].pos],
					f[nowt][notdel[pos - objstr.length() + 1].pos - 1]
					+ notdel[pos].val - notdel[pos - objstr.length()].val);
			}
		}
		for(int i = 1;i <= n;i++){
			if(firstAppear[s[i] - 'a'] == 0 || 
				r < firstAppear[s[i] - 'a'] || 
				l >= lastAppear[s[i] - 'a']){
				f[nowt+1][i] = max(f[nowt+1][i],f[nowt+1][i-1]);
			}
		}
	}
	if(f[siz][n] <= 0)return -1;
	ret -= f[siz][n];
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	cin>>tid>>T;
	while(T--){
		cin>>n>>m>>s>>t;
		for(int i = 1;i <= n;i++){
			cin>>w[i];
		}
		s = "." + s,t = "." + t;
		for(int i = 0;i < 26;i++){
			firstAppear[i] = m+2,lastAppear[i] = 0;
		}
		for(int i = 1;i <= m;i++){
			if(firstAppear[t[i] - 'a'] == m+2){
				firstAppear[t[i] - 'a'] = i;
			}
			lastAppear[t[i] - 'a'] = i;
		}
		set<int> st;
		for(int i = 0;i < 26;i++){
			st.insert(firstAppear[i]);
			st.insert(lastAppear[i]);
			st.insert(lastAppear[i]+1);
		}
		st.insert(1),st.insert(m+1);
		st.erase(0);
		wall.clear();
		wall.push_back(0);//0 + 1 就是1,刚好从1开始
		
		for(auto i : st)if(i <= m+1)wall.push_back(i);
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
