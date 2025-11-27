#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using LL = long long;
using ull = unsigned long long;
using ld = long double;

#define dbg(x) cout<<"---"<<#x<<"---\n";for(auto i:x)cout<<i<<' ';cout<<'\n';

const int maxn = 10010;

int n,m,slen,tlen,mid;
std::string S[maxn],T[maxn];

std::unordered_map<std::string,int> buck;
char fix[maxn];

void solve1() {
	int fixlen = slen-mid;
	for(int i=1; i<=n; i++) {
		std::string s = S[i];
		std::string cut = s.substr(0,mid) + s.substr(0,mid);
		for(int j=mid; j<slen; j++) fix[j%mid]=s[j];

		// 枚举起始点--匹配
		for(int j=0; j<mid; j++) {
			bool AC=1;
			for(int k=0; k<fixlen; k++) {
				if(cut[j+k]!=fix[k]) {
					AC=0;
					break;
				}
			}
			if(AC) { // 匹配上
				buck[cut.substr(j+fixlen,tlen)]++;
			}
		}
	}
	int ans=0;
	for(int i=1; i<=m; i++) {
		ans+=buck[T[i]];
	}
	cout << ans;
}

void solve2() {
	// md u->v == v->u
	int fixlen = tlen-mid;
	for(int i=1; i<=m; i++) {
		std::string t = T[i];
		std::string cut = t.substr(fixlen) + t.substr(fixlen);
		for(int j=0; j<fixlen; j++) fix[j]=t[j];

		// 枚举起始点--匹配后缀
		for(int j=0; j<mid; j++) {
			bool AC=1;
//			cout << "comparing::" << cut.substr(j,mid) << '\n';
			int jj=j+mid-fixlen;
			for(int k=0; k<fixlen; k++) {
//				cout << cut[jj+k];
				if(cut[jj+k]!=fix[k]) {
					AC=0;
					break;
				}
			}
//			cout << AC << '\n';
			// ---
			if(AC) { // 匹配上了后缀。。。
				buck[cut.substr(j,slen)]++;
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		ans+=buck[S[i]];
	}
	cout << ans;
}

int main() {
	cin >> n >> m >> slen >> tlen;
	mid = slen+tlen>>1;
	for(int i=1; i<=n; i++) cin >> S[i];
	for(int i=1; i<=m; i++) cin >> T[i];

	if(slen >= tlen) solve1();
	else solve2();

	return 0;
}

