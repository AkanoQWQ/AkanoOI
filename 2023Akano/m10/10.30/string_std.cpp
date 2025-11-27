#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> pi;

typedef unsigned long long ull;
void read_int(int &x){
	x=0;
	char ch=' ';
	while(!isdigit(ch)){
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
}
void read_string(string &s){
	char ch=' ';
	while(ch!='0' && ch!='1'){
		ch=getchar();
	}
	while(ch=='0' || ch=='1'){
		s+=ch;
		ch=getchar();
	}
}

const int N=1e6+5,M=2e6+5;
int n;
string s,t0;
int sz;
vector<vi>p;
vector<string>d;
void Input(){
	read_int(n);
	read_string(s);
	read_string(t0);
	sz=s.size();
	p.resize(n+1);
	d.resize(n+1);
	rep(i,1,n){
		int k;read_int(k);
		p[i].resize(k);
		for(int &x:p[i]){
			read_int(x);
		}
		read_string(d[i]);
	}
}
vi kmp,fkmp;
void Get_kmp(){
	kmp.resize(sz);
	fkmp.resize(sz);
	kmp[0]=-1;
	rep(i,1,sz-1){
		kmp[i]=kmp[i-1];
		while(kmp[i]!=-1 && s[i]!=s[kmp[i]+1]){
			kmp[i]=kmp[kmp[i]];
		}
		if(s[i]==s[kmp[i]+1]){
			kmp[i]++;
		}
	}
	fkmp[sz-1]=sz;
	per(i,sz-2,0){
		fkmp[i]=fkmp[i+1];
		while(fkmp[i]!=sz && s[i]!=s[fkmp[i]-1]){
			fkmp[i]=fkmp[fkmp[i]];
		}
		if(s[i]==s[fkmp[i]-1]){
			fkmp[i]--;
		}
	}
}
vi sum;
void Get_sum(){
	sum.resize(sz+1);
	int p=sz;
	per(i,(int)t0.size()-1,0){
		char c=t0[i];
		while(p==0 || (p!=sz && s[p-1]!=c)){
			p=fkmp[p];
		}
		if(s[p-1]==c){
			p--;
		}
	}
	if(s==t0){
		p=fkmp[p];
	}
	while(p!=sz){
		sum[p]++;
		p=fkmp[p];
	}
	rep(i,0,sz-1){
		if(kmp[i]!=-1){
			sum[i+1]+=sum[kmp[i]+1];
		}
	}
}
ull ans[N];
int pos[N];
void solve(){
	Get_kmp();
	Get_sum();
	pos[0]=-1;
	for(char c:t0){
		while(pos[0]==sz-1 || (pos[0]!=-1 && s[pos[0]+1]!=c)){
			pos[0]=kmp[pos[0]];
		}
		if(s[pos[0]+1]==c){
			pos[0]++;
		}
		if(pos[0]==sz-1){
			ans[0]++;
		}
	}
	rep(i,1,n){
		rep(j,0,(int)p[i].size()-1){
			int x=p[i][j];
			int px=pos[x];
			ans[i]+=ans[x]+(j==(int)p[i].size()-1 ?0:sum[px+1]);
		}
		pos[i]=pos[p[i].back()];
		for(char c:d[i]){
			while(pos[i]==sz-1 || (pos[i]!=-1 && s[pos[i]+1]!=c)){
				pos[i]=kmp[pos[i]];
			}
			if(s[pos[i]+1]==c){
				pos[i]++;
			}
			if(pos[i]==sz-1){
				ans[i]++;
			}
		}
		cout<<ans[i]<<'\n';
	}
}
signed main(){
	freopen("string/string0.in","r",stdin);
	freopen("string/string0.ans","w",stdout);
	Input();
	solve();
	return 0;
}
