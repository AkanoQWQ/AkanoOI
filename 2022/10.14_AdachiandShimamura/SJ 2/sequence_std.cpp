#include <iostream>
#include <cstdio>
using namespace std;
const int N=1000001;
int n,ans; int a[N],b[N],q[N];
int readin()
{
    int x=0,f=1; char ch=getchar();
    while(ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int mymax(int a,int b)
{return a>b?a:b;}
void read()
{
    int i;
    n=readin();
    for (i=1;i<=n;i++)
        a[i]=readin(),b[i]=readin();
    q[1]=1;
    return;
}
void work()
{
    int i,p=2,head=1,tail=1;
    //  i==l p==r
    for (i=1;i<=n&&p<=n;i++)
    {
        //大于i的最大值
        while(head<=tail&&q[head]<i) head++;
        if (p<=i) p=i+1,q[++tail]=i;
        //维护单调区间
        while(p<=n&&b[p]>=a[q[head]])
        {
            while(head<=tail&&a[q[tail]]<a[p]) tail--;
            q[++tail]=p++;
        }
        ans=mymax(ans,p-i);
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    freopen("sequence.in","r",stdin);
    freopen("sequence2.out","w",stdout);
    read();
    work();
    return 0;
}

