#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
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
#define endl '\n'

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
			cnt++;
			op1[i-1]='1';
			op2[i-1]='1';
		}
	}
	
	op1[x-1]='1';
	op2[y-1]='1';
	ans.push_back(op1);
	ans.push_back(op2);
}

void bh1(int x) {
	int cnt = 0;
	vector<int> tmp;
	string op = p;
	for(int i=1; i<=n; i++) {
		if(cnt<m-1 && i!=x) {
			cnt++;
			tmp.push_back(i);
			op[i-1] = '1';
		}
	}
	op[x-1]='1';
	ans.push_back(op);
	
	for(int i=0;i<m-2;i+=2) {
		bh2(tmp[i],tmp[i+1]);
	}
	
}


void solve()
{
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
			cout << res <<" 0\n"; 
		}
		else {
			cout << tot - res <<" 1\n";
			for(int i = 1; i <= n; i++) {
				cout <<"1";
			}
		}
	}
	else {
		sort(a.begin(), a.end(), cmp);
		
		for(int i = 0; i <= n - 2; i += 2) {
			//cout<<a[i].w<<" "<<a[i+1].w<<endl;
			if(a[i].w + a[i+1].w > 0) {
				if(a[i+1].w >= 0) {
					bh2(a[i].id, a[i+1].id);
					res+=a[i].w + a[i+1].w;
				}
				else {
					if(m&1) {
						bh1(a[i].id);
						res += a[i].w;
					}
					else {
						bh2(a[i].id, a[i+1].id);
						res+=a[i].w + a[i+1].w;     
					}
					break;
				}
			}
			else {
				if(a[i].w>0 && (m&1)) {
					bh1(a[i].id);
					res += a[i].w;
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
	
	open("std1");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;t=1;
	//cin>>t;
	for(int i=1;i<=t;i++){
		//printf("Case %d: ",i);
		solve();
	}
}
