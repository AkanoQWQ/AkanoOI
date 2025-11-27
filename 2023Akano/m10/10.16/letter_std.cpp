#include<bits/stdc++.h>
using namespace std;

namespace Solve{
	typedef long long ll;
	const int N=200010;
	const ll INF=0x3f3f3f3f3f3f3f3f;
	int T;
	char s[N],t[N];
	int n,m;
	
	ll f[N],g[N];int w[N];
	inline void Min(ll&x,ll y){
		x=(x<y?x:y);
	}
	
	vector<bool>kmp(vector<int>a,vector<int>b){
		if(b.size()==0){
			return vector<bool>(a.size(),1);
		}
		vector<int>ne(b.size());
		ne[0]=-1;
		for(int i=1,j=-1;i<(int)b.size();i++){
			while(j!=-1&&t[b[i]]!=t[b[j+1]])j=ne[j];
			if(t[b[i]]==t[b[j+1]])j++;
			ne[i]=j;
		}
		vector<bool>res(a.size());
		for(int i=0,j=-1;i<(int)a.size();i++){
			while(j!=-1&&s[a[i]]!=t[b[j+1]])j=ne[j];
			if(s[a[i]]==t[b[j+1]])j++;
			if(j==(int)b.size()-1)res[i]=1,j=ne[j];
		}
		return res;
	}
	ll sum[N];
	bool vvv[N];
	void main(){
		int o;cin>>o>>T;
		while(T--){
			cin>>n>>m;
			cin>>(s+1)>>(t+1);
			for(int i=1;i<=n;i++)cin>>w[i];
			
			memset(vvv,0,sizeof vvv);
			vector<int>pos;
			int st=0;
			for(int i=1;i<=m;i++){
				int c=t[i]-'a';
				if(!(st>>c&1)){
					st^=(1<<c);
					pos.push_back(i);
					vvv[i]^=1;
				}
			}
			for(int i=m;i;i--){
				int c=t[i]-'a';
				if(st>>c&1){
					st^=(1<<c);
					pos.push_back(i);
					vvv[i]^=1;
				}
			}
			sort(pos.begin(),pos.end());
			pos.erase(unique(pos.begin(),pos.end()),pos.end());
			
			st=0;
			memset(f,0x3f,sizeof f);//f 数组 为 滚动表示当前在 t 字符串的第几段,f_i 表示当前是 s 字符串的 i
			ll ss=0;//w的前缀和
			for(int i=1;i<=n;i++){//对第 0 段(就是第一段)特判,只使用删除(如果能匹配呢?)
				if(s[i]==t[1]){//尝试对于第一位 t 使用
					f[i]=ss;
				}
				ss+=w[i];
			}
			if(vvv[1])st^=(1<<(t[pos[0]]-'a'));
			for(int i=1;i<(int)pos.size();i++){
				vector<int>a,b;// a 存 可以删除的位置,b存 t 字符串
				for(int j=1;j<=n;j++){
					if(st>>(s[j]-'a')&1){//如果可以删除
						a.push_back(j);
					}
				}
				for(int j=pos[i-1]+1;j<pos[i];j++){
					b.push_back(j);
				}
				auto res=kmp(a,b);
				for(int j=1;j<=n;j++){
					sum[j]=sum[j-1]+(1-(st>>(s[j]-'a')&1))*w[j];//是否需要删除
				}
				memset(g,0x3f,sizeof g);
				//g 为 temp 数组,滚动转移 f
				if(b.size()==0){//pos 为 2,3 贴在一起(没有包含串)
					ll v1=INF;
					for(int j=1;j<=n;j++){
						if(s[j]==t[pos[i]]){
							Min(g[j],sum[j-1]+v1);
						}
						if(st>>(s[j]-'a')&1)v1=INF;
						Min(v1,f[j]-sum[j]);
					}
				}
				else{
					for(int j=b.size();j<(int)a.size();j++){
						if(res[j]){
							ll v1=INF;
							int z=j-(int)b.size()+1;
							for(int k=a[z]-1;k>=(z==0?1:a[z-1]);k--){
								Min(v1,f[k]-sum[k]);
							}
							for(int k=a[j]+1;k<=(j==(int)a.size()-1?n:a[j+1]);k++){
								if(s[k]==t[pos[i]]){
									Min(g[k],sum[k-1]+v1);
								}
							}
						}
					}
				}
				memcpy(f,g,sizeof f);
				if(vvv[pos[i]])st^=(1<<(t[pos[i]]-'a'));
			}
			ll ans=f[n],s=0;
			for(int i=n-1;i;i--)Min(ans,f[i]+(s+=w[i+1]));
			if(ans==INF)cout<<-1<<'\n';
			else cout<<ans<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	
	Solve::main();
	return 0;
}


