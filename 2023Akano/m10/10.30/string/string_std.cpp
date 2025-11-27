#include<bits/stdc++.h>
using namespace std;

namespace Solve{
	typedef long long ll;
	typedef unsigned long long ull;
	ll exgcd(ll a,ll b,ll&x,ll&y){
		if(!b){
			x=1,y=0;
			return a;
		}
		ll g=exgcd(b,a%b,y,x);
		y-=(a/b)*x;
		return g;
	}
	ll calc(ll a,ll b,ll c,ll d,ll all,ll lx,ll ly){
		//ax+b+cy+d==all
		//x in [1,lx]   y in [1,ly]
		
		if(a+b+c+d>all||lx*a+b+ly*c+d<all)return 0;
		ll x=0,y=0,g=exgcd(a,c,x,y);
		if((all-b-d)%g)return 0;
		ll rt=(all-b-d)/g;
		x*=rt,y*=rt;
		ll tx=c/g,ty=a/g;
		
		//min
		if(x<1){
			ll t=(1-x+tx-1)/tx;
			x+=t*tx,y-=t*ty;
		}
		if(x-1>=tx){
			ll t=(x-1)/tx;
			x-=t*tx,y+=t*ty;
		}
		if(x<1)return 0;
		if(y>ly){
			ll t=(y-ly+ty-1)/ty;
			x+=t*tx,y-=t*ty;
		}
		if(y<1)return 0;
		if(x>lx)return 0;
		ll mx=x;
		if(x+tx<=lx){
			ll t=(lx-x)/tx;
			x+=t*tx,y-=t*ty;
		}
		if(y<1){
			ll t=(1-y+ty-1)/ty;
			x-=t*tx,y+=t*ty;
		}
		return x-mx+1;
	}
	const int N=2000010;
	int n;char s[N],t[N],d[N];int ls,lt,ld;
	ull self[N>>1],mt[N>>1];int ed[N>>1],hd;
	int pre[N];
	
	int ne1[N],ne2[N],To1[N][2],To2[N][2],tpf1[N],tpf2[N];
	void kmp(int*ne,int To[N][2],int*tpf){
		tpf[1]=1;
		for(int i=2,j=0;i<=ls;i++){
			while(j&&s[j+1]!=s[i])j=ne[j];
			if(s[j+1]==s[i])j++;
			ne[i]=j;
			if(!ne[i]){
				tpf[i]=i;
			}
			else{
				if(i-ne[i]==ne[i]-ne[ne[i]]){
					tpf[i]=tpf[ne[i]];
				}
				else{
					tpf[i]=i;
				}
			}
		}
		for(int i=0;i<ls;i++){
			int j=ne[i];
			To[i][s[i+1]-'0']=i+1;
			To[i][(s[i+1]-'0')^1]=To[j][(s[i+1]-'0')^1];
		}
	}
	
	struct Item{
		int s,d,len;
	};
	vector<Item>Get(int p,int*tpf,int*ne){
		vector<Item>res;
		while(p){
			int pp=tpf[p],d=p-ne[p];
			res.push_back({pp-d,d,1+(p-pp)/d});
			p=ne[pp];
		}
		return res;
	}
	void main(){
		cin>>n;
		cin>>(s+1)>>(t+1);
		ls=strlen(s+1),lt=strlen(t+1);
		
		kmp(ne1,To1,tpf1);
		reverse(s+1,s+1+ls);
		kmp(ne2,To2,tpf2);
		reverse(s+1,s+1+ls);
		
		int p=0;
		for(int i=1;i<=lt;i++){
			p=To1[p][t[i]-'0'];
//			while(p&&s[p+1]!=t[i])p=ne1[p];
//			if(s[p+1]==t[i])p++;
//			cerr<<"I "<<i<<' '<<p<<' '<<t[i]<<' '<<s[p+1]<<'\n';
			if(p==ls){
				self[0]++;
				p=ne1[p];
			}
		}
		ed[0]=p;
		
		p=0;
		for(int i=lt;i;i--){
			p=To2[p][t[i]-'0'];
			if(p==ls)p=ne2[p];
		}
		hd=p;
		for(int i=lt;i;i--){
			p=To2[p][t[i]-'0'];
			if(p==ls){
				if(lt-i+1<ls){
					mt[0]++;
				}
				p=ne2[p];
			}
		}
		for(int z=1;z<=n;z++){
			int k,x;cin>>k;
			for(int i=1;i<=k;i++){
				cin>>x;
				self[z]+=self[x];
				if(i<k){
					self[z]+=mt[x];
				}
			}
			cin>>(d+1);ld=strlen(d+1);
			int p=ed[x];assert(p<ls);
			for(int i=1;i<=ld;i++){
				p=To1[p][d[i]-'0'];
				if(p==ls){
					self[z]++;
					p=ne1[p];
				}
				pre[i]=p;
			}
			ed[z]=p;
			
			if(ls>1){
				p=hd;
				for(int i=ld;i>=ld;i--){
					p=To2[p][d[i]-'0'];
					if(p==ls){
						mt[z]++;
						p=ne2[p];
					}
					
//				cerr<<"I "<<pre[i]<<' '<<p<<'\n';
					ull res=0;
					auto L=Get(pre[i],tpf1,ne1),R=Get(p,tpf2,ne2);
					for(auto pr:R){
						if(pr.s+pr.len*pr.d<=ld-i+1)continue;
						if(pr.s+pr.d<ld-i+1){
							int t=(ld-i+1-(pr.s+pr.d)+pr.d-1)/pr.d;
							assert(t<pr.len);
							pr.s+=t*pr.len,pr.len-=t;
						}
//					cerr<<"R "<<pr.s<<' '<<pr.d<<' '<<pr.len<<'\n';
						for(auto pl:L){
							res+=calc(pr.d,pr.s,pl.d,pl.s,ls+1,pr.len,pl.len);
						}
					}
					
					mt[z]+=res;
				}
				
			}
//			cerr<<"Match"<<mt[z]<<'\n';
			cout<<self[z]<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Solve::main();
	
	return 0;
}
