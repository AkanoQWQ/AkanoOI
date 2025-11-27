#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=505;
const int M=5;
const int mod=998244353;
int m,n;
char in[N];
struct node{
	ll a[M][M];
	node(){
		memset(a,0,sizeof(a));
	}
	void init(){
		for (int i=0;i<m;i++) a[i][m-1]=1;
		for (int i=1;i<m;i++) a[i][i-1]=1;
	}
	void init1(){
		for (int i=0;i<m;i++) a[i][i]=1;
	}
}P[N],F[N][N],g[N];
node operator *(const node&x,const node&y){
	node z;
	for (int k=0;k<m;k++)
		for (int i=0;i<m;i++)
			for (int j=0;j<m;j++)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return z;
}
node operator +(const node&x,const node&y){
	node z;
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			z.a[i][j]=(x.a[i][j]+y.a[i][j])%mod;
	return z;
}
ll read(){
	ll w=0,f=1;
	char c=getchar();
	while (c>'9'||c<'0'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}
node ksm(node S,ll y){
	node P1;
	P1.init1();
	while (y){
		if (y&1) P1=P1*S;
		S=S*S;
		y>>=1;
	}
	return P1;
}

inline void DEBUG(){
	freopen("CON","r",stdin);
	while(1){
		int l,r;
		cin>>l>>r;
		if(l == -1 && r == -1)break;
		int num = 0;
		for(int i = l;i <= r;i++){
			num = num * 10 + in[i] - '0';
		}
		node ansm = ksm(P[0],num);
		cout<<"EXPECTED "<<endl;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++){
				cout<<ansm.a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"Read "<<endl;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++){
				cout<<F[l][r].a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return ;
}

int main(){
	freopen("P3176.in","r",stdin);
	scanf("%s",in+1);
	n=strlen(in+1),m=read();
	P[0].init();
	for (int i=1;i<n;i++) P[i]=ksm(P[i-1],10);
	for (int j=1;j<=n;j++){
		for (int i=j;i>=1;i--){
			if (i!=j) F[i][j]=F[i+1][j]*ksm(P[j-i],in[i]-'0');	
			else F[i][j]=ksm(P[0],in[i]-'0');
		}		
	}
	node test = P[0] * P[0] * P[0] * P[0] * P[0];
	for(int i = 0;i < m;i++){
		for(int j = 0;j < m;j++){
			cout<<test.a[i][j]<<" ";
		}
		cout<<endl;
	}
	g[0].init1();
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			g[i]=g[i]+(g[j]*F[j+1][i]);
		}
		for(int jj = 0;jj < m;jj++){
			for(int kk = 0;kk < m;kk++){
				cout<<g[i].a[jj][kk]<<" ";
			} 
			cout<<endl;
		}
	}
	ll ans=0;
	for (int i=0;i<m;i++) ans=(ans+g[n].a[0][i])%mod;
	cout<<ans<<'\n';
	return 0;
}
