#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
const int MAXSZ = 1e6 + 6;
const int MAXC = 29;
const int MAXN = 156;
int Trans(char ch){//Size 26
	if('a' <= ch && ch <= 'z')return (ch - 'a');
	return 0;
}
pair<int,string> strs[MAXN];
class ACAutomaton{
	private:
		int fail[MAXSZ],tr[MAXSZ][MAXC],cnt;
		vi dir[MAXSZ];
	public:
		inline void Insert(const string& str,const int& no){
			int u = 0;
			for(auto i : str){
				const int nxtch = Trans(i);
				if(tr[u][nxtch] == 0)tr[u][nxtch] = ++cnt;
				u = tr[u][nxtch];
			}
			dir[u].push_back(no);
			return ;
		}
		inline void Build(){
			queue<int> q;
			for(int i = 0;i < 26;i++){
				if(tr[0][i]){
					q.push(tr[0][i]);
				}
			}
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				for(int i = 0;i < 26;i++){
					if(tr[u][i]){
						fail[tr[u][i]] = tr[fail[u]][i];
						q.push(tr[u][i]);
					}else{
						tr[u][i] = tr[fail[u]][i];
					}
				}
			}
			return ;
		}
		inline int Find(const string& str){
			int u = 0,ret = 0;
			for(auto i : str){
				u = tr[u][Trans(i)];
				int p = u;
				while(p){
					for(auto j : dir[p])strs[j].first++;
					p = fail[p];
				}
			}
			return ret;
		}
		inline void Clear(){
			for(int i = 0;i <= cnt;i++){
				memset(tr[i],0,sizeof(tr[i]));
				fail[i] = 0;
				dir[i].clear();
			}
			return ;
		}
}ACA;
string ins,passage;
int n;
bool cmp(pair<int,string> _a,pair<int,string> _b){
	return _a.first > _b.first;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(1){
		ACA.Clear();
		cin>>n;
		if(n == 0)break;
		for(int i = 1;i <= n;i++){
			cin>>strs[i].second;
			strs[i].first = 0;
			ACA.Insert(strs[i].second,i);
		}
		ACA.Build();
		cin>>passage;
		ACA.Find(passage);
		stable_sort(strs+1,strs+n+1,cmp);
		cout<<strs[1].first<<endl;
		for(int i = 1;i <= n;i++){
			if(strs[i].first < strs[i-1].first)break;
			cout<<strs[i].second<<endl;
		}
	}
	return 0;
}
