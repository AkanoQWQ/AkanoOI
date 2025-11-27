#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int N = 207, L = 33;
int n, m, k, a[L], b[L][2], v[N<<1];
char s[N];
vi e[N<<1];

bool dfs(int x) {
	if (v[x>n?x-n:x+n]) return 0;
	v[x] = 1;
	for (unsigned int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (!v[y] && !dfs(y)) return 0;
	}
	return 1;
}

inline bool pd(int o) {
	for (int i = 1; i <= n << 1; i++) v[i] = 0;
	for (int i = 1; i <= o; i++)
		if (!dfs(i + a[s[i]-'a'+1] * n)) return 0;
	for (int i = o + 1; i <= n; i++) {
		if (v[i]) s[i] = b[1][0] + 'a' - 1;
		else if (v[i+n]) s[i] = b[1][1] + 'a' - 1;
		else {
			int x = min(b[1][0], b[1][1]), y = max(b[1][0], b[1][1]);
			if (dfs(i + a[x] * n)) s[i] = x + 'a' - 1;
			else if (dfs(i + a[y] * n)) s[i] = y + 'a' - 1;
			else return 0;
		}
	} 
	return 1;
}
char ch;
int main() {
	cin>>s;
	k = strlen(s);
	map< char, int > p;
	p['V'] = 0, p['C'] = 1;
	b[k+1][0] = b[k+1][1] = k + 1;
	for (int i = k, t[2] = {k + 1, k + 1}; i; i--)
		t[a[i]=p[s[i]]] = i, b[i][0] = t[0], b[i][1] = t[1];
	cin>>n>>m;
	for (int i = 1, x, y, s1, t1, s2, t2; i <= m; i++) {
		cin>>x, cin>>ch, s1 = x + p[ch] * n, s2 = s1 > n ? s1 - n : s1 + n;
		cin>>x, cin>>ch, t1 = x + p[ch] * n, t2 = t1 > n ? t1 - n : t1 + n;
		e[s1].push_back(t1), e[t2].push_back(s2);
	}
	cin>>s;
	n = strlen(s);
	if (pd(n)){
		cout<<s<<endl;
		return 0;
	}
//	else if (b[1][0] == k + 1 || b[1][1] == k + 1) return print(-1), 0;
//	for (int i = n; i; i--) {
//		int c = s[i] - 'a' + 2, x = min(b[c][0], b[c][1]), y = max(b[c][0], b[c][1]);
//		if (x != k + 1) {
//			s[i] = x + 'a' - 1;
//			if (pd(i)) return prints(s, n), 0;
//		}
//		if (y != k + 1) {
//			s[i] = y + 'a' - 1;
//			if (pd(i)) return prints(s, n), 0;
//		}
//	}
//	print(-1);
	return 0;
}
