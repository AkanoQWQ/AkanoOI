#include <bits/stdc++.h>

using namespace std;

using ull=unsigned long long;

constexpr int MAXN = 100000;

mt19937 rng(random_device{}());

int hash_solve(string s,int n,int l,ull base) {
	vector<ull> rand_v(128);
	for(auto &i:rand_v) i=rng();
	
	ull pl=1;
	for(int i=1;i<=l;++i) pl*=base;
	vector<ull> val; ull cur=0;
	for(int i=1;i<=l;++i) cur=cur*base+rand_v[s[i]-'a'];
	val.emplace_back(cur);
	for(int i=l+1;i<=n;++i) {
		cur=cur*base+rand_v[s[i]-'a'];
		cur-=rand_v[s[i]-'a']*pl;
		val.emplace_back(cur);
	}
	sort(val.begin(),val.end());
	val.erase(unique(val.begin(),val.end()),val.end());
	return val.size();
}

int hash_solve2(string s,int n,int l,ull base1,ull base2) {
	vector<ull> rand_v(128);
	for(auto &i:rand_v) i=rng();
	
	ull pl1=1,pl2=1;
	for(int i=1;i<=l;++i) pl1*=base1,pl2*=base2;
	vector<pair<ull,ull>> val; ull cur1=0,cur2=0;
	for(int i=1;i<=l;++i) {
		cur1=cur1*base1+rand_v[s[i]-'a'];
		cur2=cur2*base2+rand_v[s[i]-'a'];
	}
	val.emplace_back(cur1,cur2);
	for(int i=l+1;i<=n;++i) {
		cur1=cur1*base1+rand_v[s[i]-'a'];
		cur2=cur2*base2+rand_v[s[i]-'a'];
		cur1-=rand_v[s[i]-'a']*pl1;
		cur2-=rand_v[s[i]-'a']*pl2;
		val.emplace_back(cur1,cur2);
	}
	sort(val.begin(),val.end());
	val.erase(unique(val.begin(),val.end()),val.end());
	cout<<val.size()<<endl;
	return val.size();
}

struct SA {
	void get(string str,int n) {
		sa.clear(); rk.clear(); h.clear();
		vector<int> rk2,key(n+1),id(n+1),buc;
		sa.resize(n+1);rk.resize(n+1);
		int m=*max_element(str.begin()+1,str.end());
		buc.resize(m+1);
		for(int i=1;i<=n;++i) ++buc[rk[i]=str[i]];
		for(int i=1;i<=m;++i) buc[i]+=buc[i-1];
		for(int i=n;i>=1;--i) sa[buc[rk[i]]--]=i;
		for(int p=0,len=1;;len<<=1,m=p) {
			buc.clear();buc.resize(m+1);p=0;
			for(int i=n;i>n-len;--i) id[++p]=i;
			for(int i=1;i<=n;++i) if(sa[i]>len) id[++p]=sa[i]-len;
			for(int i=1;i<=n;++i) ++buc[key[i]=rk[id[i]]];
			for(int i=1;i<=m;++i) buc[i]+=buc[i-1];
			for(int i=n;i>=1;--i) sa[buc[key[i]]--]=id[i];
			rk2=rk;rk2.resize(n+len+1);rk[sa[1]]=p=1;
			for(int i=2;i<=n;++i) {
				if(rk2[sa[i-1]]==rk2[sa[i]]&&rk2[sa[i-1]+len]==rk2[sa[i]+len]) rk[sa[i]]=p;
				else rk[sa[i]]=++p;
			}
			if(p==n) break;
		}
		h.resize(n+1);
		for(int i=1,k=0;i<=n;++i) {
			if(!rk[i]) continue;
			if(k) --k;
			while(str[i+k]==str[sa[rk[i]-1]+k]) ++k;
			h[rk[i]]=k;
		}
	}
	vector<int> sa,rk,h;
}sa;

inline int sa_solve(string s, const int &n, const int &l) {
	sa.get(s,n);
	int ans=0;
	for(int i=1;i<=n;++i) ans+=sa.h[i]<l;
	return ans+1-l;
}

int main() {
	ifstream is("hack.in");
	
	string s; is>>s;
	int n=s.length();  s=" "+s;
	int l; is>>l;
	mt19937 rng(random_device{}());
	uniform_int_distribution<ull> genb(27,1e9);
	
	int ans=sa_solve(s,n,l),cnt=0;
	
	int iter=1e5;
	while(iter--) {
		if(hash_solve2(s,n,l,genb(rng),genb(rng))==ans) ++cnt;
	}
	
	cout<<cnt<<endl;
	cout<<ans<<endl;
	
	return 0;
}
