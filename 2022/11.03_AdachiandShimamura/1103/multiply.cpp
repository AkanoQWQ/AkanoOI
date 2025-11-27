#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	char c=getchar();
	T ret=0;
	while(!isdigit(c))ret|=!(c^'-'),c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(ret)x=(~x)+1;
	return;
}
template<typename T>inline void print(T x){
	if(x<0)putchar('-'),x=(~x)+1;
	if(x>9)print(x/10);
	putchar((x-x/10*10)^48);
	return;
}
template<typename T>inline void wr1(T x){
	print(x);
	putchar(' ');
	return;
}
template<typename T>inline void wr2(T x){
	print(x);
	putchar('\n');
	return;
}
int t,n,a[1145],ans,prime[1145],cnt,siz[1145],num,mi;
bool pri[1145],vis[1145];
unordered_map<int,int>jh[1100];
vector<int>zys[1145];
void fjzys(int x){
	int n=x;
	for(int i=1;i<=cnt;++i){
		if(n%prime[i]==0){
			zys[x].push_back(i);
			jh[i][x]=1;
			while(n%prime[i]==0){
				n/=prime[i];
			}
		}
	}
	return;
}
int main(){
	freopen("multiply.in","r",stdin);
	freopen("multiply.out","w",stdout);
    pri[1]=1;
    for(int i=2;i<=1100;++i){
    	if(vis[i])continue;
    	pri[i]=vis[i]=1;
    	prime[++cnt]=i;
    	for(int j=2;j*i<=1100;++j){
    		vis[i*j]=1;
		}
	}
	read(t);
    while(t--){
    	memset(vis,0,sizeof vis);
    	for(int i=1;i<=cnt;++i)jh[i].clear();
    	ans=0;
    	read(n);
    	for(int i=1;i<=n;++i){
		    read(a[i]);
		    if(a[i]==1){
			    ans++;
				continue;
			}
			if(!vis[a[i]])zys[a[i]].clear(),fjzys(a[i]),vis[a[i]]=1;
		}
		memset(vis,0,sizeof vis);
		memset(siz,0,sizeof siz);
		while(1){
			mi=1e9;
			num=0;
			for(int i=1;i<=n;++i){
				if(!vis[a[i]]){
					if(a[i]==1){
						vis[a[i]]=1;
						continue;
					}
					siz[a[i]]=0;
					for(int j=0;j<(int)zys[a[i]].size();++j){
						siz[a[i]]+=jh[zys[a[i]][j]].size();
					}
					siz[a[i]]-=zys[a[i]].size()-1;
					if(siz[a[i]]<mi){
						mi=siz[a[i]];
						num=a[i];
					}
				}
			}
			if(mi==1000000000||num==0)break;
			ans++;
			vis[num]=1;
			for(int i=0;i<(int)zys[num].size();++i){
				int f=zys[num][i];
				for(auto j:jh[f]){
					int nn=j.first;
					vis[nn]=1;
					for(auto k:zys[nn]){
						if(k==f)continue;
						if(jh[k].find(nn)!=jh[k].end())jh[k].erase(nn);
					}
			    }
			    jh[f].clear();
			}
		}
		wr2(ans);
	}
	return 0;
}
/*
3
5
6 7 8 9 10
4
699 932 233 466
5
74 52 8 39 37
*/
