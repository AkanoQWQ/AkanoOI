#include<bits/stdc++.h>
#define ll long long
#define mod 999911658
#define N 40005
using namespace std;
ll n,g,m[5],a[5],b[5]={0ll,2ll,3ll,4679ll,35617ll},ans=0ll;
ll jie[40005];
void init(ll x){
    jie[0]=jie[1]=1ll;
    for(ll i=2;i<=x;i++) jie[i]=(jie[i-1]*i)%x;
    return;
}
ll ksm(ll x,ll y,ll p){
    ll res=1ll;x%=p;
    for(;y;y>>=1){
        if(y&1) res=(res*x)%p;
        x=(x*x)%p;
    }
    return res;
}
ll C(ll x,ll y,ll p){
    if(x<y) return 0;
    ll up=jie[x],down=jie[y]*jie[x-y]%p;
    return up*ksm(down,p-2,p)%p;
}
ll lucas(ll x,ll y,ll p){
    if(x<y) return 0ll;
    if(!x) return 1ll;
    return lucas(x/p,y/p,p)*C(x%p,y%p,p)%p;
}
void crt()
{
    for(int i=1;i<=4;i++)
    {
        m[i]=mod/b[i];
        ans+=(a[i]*m[i]%mod)*ksm(m[i],b[i]-2,b[i])%mod;
    }
    return;
}
int main()
{
	freopen("ancient.in", "r", stdin);
	freopen("ancient.out", "w", stdout);
    scanf("%lld%lld",&n,&g);
    if(!(g%(mod+1))) {printf("0");return 0;}
    for(int i=1;i<=4;i++)
    {
        init(b[i]);
        for(ll j=1;j*j<=n;j++)
        {
            if(!(n%j))
            {
                a[i]=(a[i]+lucas(n,j,b[i]))%b[i];
                if(j*j!=n) a[i]=(a[i]+lucas(n,n/j,b[i]))%b[i];
            }
        } 
    }
    crt();
    printf("%lld",ksm(g,ans,mod+1));
    return 0;
}
