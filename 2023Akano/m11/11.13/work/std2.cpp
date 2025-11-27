#include<bits/stdc++.h>
using namespace std;
#define open(x) freopen(x ".in", "r", stdin);freopen(x ".out", "w", stdout);
#define pb push_back
#define L(i,a,b) for(int i = (a) ; i <= (b) ; ++i)
#define int long long
inline int read(){int f=1;int x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-'){f=-f;}c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
inline void wr(int x){if(x<0){putchar('-');x=-x;}if(x>9){wr(x/10);}putchar(x%10+'0');}

const int MAXN = 1e5 + 5;
int n,m;
int a[MAXN];
vector<int> pre;
vector<string> op; 
vector<string> v;
stack<string> stk;
vector<int> addin;
vector<int> s;

struct node{
	int x,y;
	bool operator <(const node& b) const{
		return b.x < x;
	}
}t[MAXN];

int msk[MAXN];

signed main(){
	freopen("std2.in","r",stdin);
	freopen("std2.out","w",stdout);
	n = read() , m = read();
	L(i,1,n) {
		char c;
		cin >> c;
		a[i] = (c - '0');
	}
	L(i,1,n) {
		t[i].x = read();
		t[i].y = i;
	}
	if(n == m){
		int sum = 0;
		int res = 0;
		L(i,1,n) {
			if(a[i]) sum += t[i].x; 
		}
		L(i,1,n){
			if(a[i] == 0) res += t[i].x; 
		}
		if(sum < res){
			cout << res << ' ' << 1 << "\n";
			L(i,1,n) cout << 1;
			return 0; 
		}
		else{
			cout << sum << ' ' << 0 << "\n";
			return 0; 
		}
		return 0;
	} 
	else
	{
		int ans = 0;
		L(i,1,n){
			if(t[i].x < 0) {
				ans += t[i].x;
				if(a[i]) a[i] = 0;
				else a[i] = 1;
				t[i].x = -t[i].x;
			}
		}
		sort(t + 1 , t + n + 1);
		int rem = 0 , lst = 0 , remk = 0;
		int cnt = 0 , vcnt = 0;	
		L(i,1,n){
			if(a[i] == 0) ++cnt;
		} 
		sort(t + 1 , t + n + 1);
		if(cnt & 1){
			L(i,1,n) {
				if(a[t[i].y] == 0 && vcnt < m) vcnt++;
			}
			if(vcnt >= m){
				vcnt = 0;
				L(i,1,n){
					if(a[t[i].y] == 0 && vcnt < m){
						msk[t[i].y] = 1;
						a[t[i].y] = 1;
						vcnt++;
					}
					if(vcnt == m) break;
				}
			} 
			else{
				int addcnt = 0;
				for(int i = n ; i >= 1 ; --i){
					if(a[t[i].y] == 1) {
						addcnt++ , addin.pb(t[i].y);
					}
					if(addcnt + vcnt == m) break;
				}
				L(i,1,n) if(a[t[i].y] == 0) msk[t[i].y] = 1 , a[t[i].y] = 1;
				for(auto v:addin){
					a[v] = 0;
					msk[v] = 1; 
				}
			}
			string ssub = "";
			L(i,1,n){
				if(msk[i]) ssub += '1';
				else ssub += '0';	
			}
			op.pb(ssub);
		}
		memset(msk , 0 , sizeof msk);
		pre.clear();
		L(i,1,n) {
			if(a[t[i].y] == 1){
				if((int)pre.size() < m - 1) pre.pb(t[i].y);
				else break;
			}
		}
		if((int)pre.size() == m - 1){
			for(auto i:pre){
				msk[i] = 1;
			}
			L(K,1,n){
				if(a[t[K].y] == 0){
					rem++;
					if(rem == 2){
						rem = 0;
						string s1 = "" , s2 = "";
						L(i,1,n){
							if(msk[i] || i == t[K].y) s1 += '1';
							else s1 += '0';
							
							if(msk[i] || i == lst) s2 += '1';
							else s2 += '0';
						}
						op.pb(s1);
						op.pb(s2);
						a[lst] = a[t[K].y] = 1;
						ans += remk + t[K].x;
					}
					else lst = t[K].y , remk = t[K].x;
				}
				else ans += t[K].x;
			}
			if(lst != t[n].y && rem == 1){
				string s1 = "" , s2 = "";
				int P1 = 0 , P2 = 0;
				L(i,1,n){
					if(msk[i] || i == lst) s1 += '1' , ++P1;
					else s1 += '0';
					if(msk[i] || i == t[n].y) s2 += '1' , ++P2;
					else s2 += '0';
				}
				if(P1 == m && P2 == m && remk > t[n].x){
					ans += (remk - t[n].x);
					op.pb(s1);
					op.pb(s2);
				}
			}
			int anscnt = op.size();
			sort(op.begin() , op.end()); 
			for(auto s:op){
				if(stk.empty()) stk.push(s);
				else if(stk.top() == s){
					stk.pop();
				}
				else{
					stk.push(s);
				}
			}
			cout << ans <<  ' ' << stk.size() << "\n";
			while(!stk.empty()){
				string out = stk.top();
				cout << out << "\n";
				stk.pop();
			}
			return 0;
		}
		else{
			s.clear();set<int> ck;
			for(int i = n ; i >= 1 ; --i){
				if(a[t[i].y] == 1) continue;
				else pre.pb(t[i].y) , ck.insert(t[i].y) , s.pb(t[i].y);
				if((int)pre.size() == m - 1) break;
			}
			reverse(s.begin() , s.end());
			for(auto i:pre) {
				msk[i] = 1;
			}
			L(K,1,n){
				if(a[t[K].y] == 0){
					rem++;
					if(rem == 2){
						rem = 0;
						string s1 = "" , s2 = "";
						L(i,1,n){
							if(msk[i] && i != lst || i == t[K].y) s1 += '1';
							else s1 += '0';
							if(msk[i] && i != t[K].y || i == lst) s2 += '1';
							else s2 += '0';
						}
						op.pb(s1);
						op.pb(s2);
						a[lst] = a[t[K].y] = 1;
						if(s.size()){
							int tp = *s.begin();
							ck.erase(tp);
							s.erase(s.begin());
							msk[tp] = 0 , msk[lst] = 1;
						}
						if(s.size()){
							int tp = *s.begin();
							ck.erase(tp);
							s.erase(s.begin());
							msk[tp] = 0 , msk[t[K].y] = 1;
						}
						ans += remk + t[K].x;
					}
					else lst = t[K].y , remk = t[K].x;
				}
				else ans += t[K].x;
			}
			if(lst != t[n].y && rem == 1){
				string s1 = "" , s2 = "";
				int P1 = 0 , P2 = 0;
				L(i,1,n){
					if(msk[i] || i == lst) s1 += '1' , ++P1;
					else s1 += '0';
					if(msk[i] || i == t[n].y) s2 += '1' , ++P2;
					else s2 += '0';
				}
				if(P1 == m && P2 == m && remk > t[n].x){
					ans += (remk - t[n].x);
					op.pb(s1);
					op.pb(s2);
				}
			}
			int anscnt = op.size();
			sort(op.begin() , op.end()); 
			for(auto s:op){
				if(stk.empty()) stk.push(s);
				else if(stk.top() == s){
					stk.pop();
				}
				else{
					stk.push(s);
				}
			}
			cout << ans <<  ' ' << stk.size() << "\n";
			while(!stk.empty()){
				string out = stk.top();
				cout << out << "\n";
				stk.pop();
			}
			return 0;
		}
	}
	return 0;
}
