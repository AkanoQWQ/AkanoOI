#include<bits/stdc++.h>
#define MAXN 510
#define eps 1e-7
using namespace std;
int n,m,c[MAXN],cnt,ans,sw;
struct rin
{
    int c;
    long double a[MAXN];
}rr[MAXN];
bool cmp(rin a,rin b)
{
    return a.c<b.c;
}
void display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%.3LF ",rr[i].a[j]);
        cout<<endl;
    }
    cout<<endl;
}
bool flag=0;
long double pr,di;
int main()
{
    freopen("1.in","r",stdin);
    //freopen("buyy.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%LF",&rr[i].a[j]);
    for(int i=1;i<=n;i++)
        scanf("%d",&rr[i].c);
    sort(rr+1,rr+n+1,cmp);
    for(int i=1;i<=min(m,n);i++)
    {
        sw=i;
        while(sw<=n&&abs(rr[sw].a[i])<=eps)sw++;
        if(abs(rr[i].a[i])<=eps){
        	cout<<i<<" no "<<endl;
		}
        if(sw != i){
        	cout<<"swap "<<sw<<" and "<<i<<endl;
		}
        swap(rr[sw],rr[i]);
        if(abs(rr[i].a[i])<=eps)continue;
        di=rr[i].a[i];
        for(int j=i;j<=m;j++)
            rr[i].a[j]/=di;
        for(int j=i+1;j<=n;++j)
        {
            pr=rr[j].a[i];
            for(int k=i;k<=m;++k)
                rr[j].a[k]-=(rr[i].a[k]*pr);
        }
    }
    for(int i=1;i<=m;i++)
    {
        flag=0;
        for(int j=1;j<=m;j++)
            flag|=(abs(rr[i].a[j])>=eps);
        if(flag)cnt++,ans+=rr[i].c;
    }
    printf("%d %d",cnt,ans);
    return 0;
}
