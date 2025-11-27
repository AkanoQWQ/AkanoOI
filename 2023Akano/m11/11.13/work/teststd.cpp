#include<bits/stdc++.h>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long
#define open(x) freopen(x ".in", "r", stdin);freopen(x ".out", "w", stdout);
//vector<vector<int>>edg(N);

string s;
int n,m;
string p;
vector<string>ans;

struct node
{
	int w, id;
	node(){}
	node(int x,int id):w(x),id(id){}
};
vector<node>a;

bool cmp(node a, node b) {
	return a.w > b.w;
}

void bh2(int x, int y) {
	int cnt = 0;
	string op1 = p;
	string op2 = p;
	
	for(int i = 1; i <= n; i++) {
		if(cnt<m-1 && i!=x && i!=y) {
			assert(i-1 < signed(op1.size()));
			assert(i-1 < signed(op2.size()));
			cnt++;
			op1[i-1]='1';
			op2[i-1]='1';
		}
	}
	
	op1[x-1]='1';
	op2[y-1]='1';
	ans.push_back(op1);
	ans.push_back(op2);
	assert(x-1 < signed(op1.size()));
	assert(y-1 < signed(op2.size()));
}

void bh1(int x) {
	int cnt = 0;
	vector<int> tmp;
	string op = p;
	for(int i=1; i<=n; i++) {
		if(cnt<m-1 && i!=x) {
			cnt++;
			tmp.push_back(i);
			assert(i-1 < signed(op.size()));
			op[i-1] = '1';
		}
	}
	assert(x-1 < signed(op.size()));
	op[x-1]='1';
	ans.push_back(op);
	
	for(int i=0;i<m-2;i+=2) {
		assert(i+1 < signed(tmp.size()));
		bh2(tmp.at(i),tmp.at(i+1));
	}
	
}
void solve(){
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	int res = 0, tot = 0;
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		tot += x;
		if(s[i] == '1'){
			a.push_back(node(-x,i));
			res += x;
		}
		else {
			a.push_back(node{x,i});
		}
		p+='0';
	}
	if(n == m) {
		//cout << res <<" "<< tot << endl;
		if(res >= tot - res) {
			cout << res;
		}
		else {
			cout << tot - res;
			return;
			for(int i = 1; i <= n; i++) {
				cout <<"1";
			}
		}
	}
	else {
		sort(a.begin(), a.end(), cmp);
		
		for(int i = 0; i <= n - 2; i += 2) {
			assert(i+1 < signed(a.size()));
			if(i >= n / 2)break;
			if(a.at(i).w + a.at(i+1).w > 0) {
				if(a.at(i+1).w >= 0) {
					bh2(a.at(i).id, a.at(i+1).id);
					res+=a.at(i).w + a.at(i+1).w;
				}
				else {
					if(m&1) {
						bh1(a.at(i).id);
						res += a.at(i).w;
					}
					else {
						bh2(a.at(i).id, a.at(i+1).id);
						res+=a.at(i).w + a.at(i+1).w;     
					}
					break;
				}
			}
			else {
				if(a[i].w>0 && (m&1)) {
					bh1(a.at(i).id);
					res += a.at(i).w;
				}
				break;
			}
		}
		cout << res <<' '<<ans.size()<<endl;
		for(auto t:ans) {
			cout<<t<<endl;
		}
	}
	
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("std1.in","r",stdin);
//	freopen("std1.out","w",stdout);
	solve();
	return 0;
}
