#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
const int N=1e5+200,INF=2e9;
struct City
{
	int id,al;//identifier,altitude
	friend bool operator < (City a,City b)
    {
        return a.al<b.al; 
    }
};
int n,m,x0,la,lb,ansid;
int h[N],s[N],x[N];
int f[20][N][5],da[20][N][5],db[20][N][5];
double ans=INF*1.0;
multiset<City> q;
void calc(int S,int X)
{
	int p=S;
	la=0,lb=0;
	for(int i=18;i>=0;i--)
		if(f[i][p][0] && la+lb+da[i][p][0]+db[i][p][0]<=X)
		{
			la+=da[i][p][0];
			lb+=db[i][p][0];
			p=f[i][p][0];
		}
}
void pre()
{
	h[0]=INF,h[n+1]=-INF;
	City st;//start
	st.id=0,st.al=INF;
	q.insert(st),q.insert(st);
	st.id=n+1,st.al=-INF;
	q.insert(st),q.insert(st);
	for(int i=n;i;i--)
	{
		int ga,gb;
		City now;
		now.id=i,now.al=h[i];
		q.insert(now);
		set<City>::iterator p=q.lower_bound(now);
		p--;
		int lt=(*p).id,lh=(*p).al;//last
		p++,p++;
		int ne=(*p).id,nh=(*p).al;//next
		p--;
		if(abs(nh-h[i])>=abs(h[i]-lh))
		{
			gb=lt;
			p--,p--;
			if(abs(nh-h[i])>=abs(h[i]-(*p).al))
				ga=(*p).id;
			else
				ga=ne;
		}
		else
		{
			gb=ne;
			p++,p++;
			if(abs((*p).al-h[i])>=abs(h[i]-lh))
				ga=lt;
			else
				ga=(*p).id;
		}//2、预处理
		f[0][i][0]=ga,f[0][i][1]=gb;
		da[0][i][0]=abs(h[i]-h[ga]);
		db[0][i][1]=abs(h[i]-h[gb]);//3、DP初值
	}
	for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<2;k++)
				if(i==1)
				{
					f[1][j][k]=f[0][f[0][j][k]][1-k];
					da[1][j][k]=da[0][j][k]+da[0][f[0][j][k]][1-k];
					db[1][j][k]=db[0][j][k]+db[0][f[0][j][k]][1-k];	
				}
				else
				{
					f[i][j][k]=f[i-1][f[i-1][j][k]][k];
					da[i][j][k]=da[i-1][j][k]+da[i-1][f[i-1][j][k]][k];
					db[i][j][k]=db[i-1][j][k]+db[i-1][f[i-1][j][k]][k];
				}//3、倍增优化DP
}
int main()
{
	freopen("city.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	cin>>x0>>m;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&s[i],&x[i]);//1、输入
	pre();
	
	for(int i = 1;i <= n;i++){
		cout<<i<<":";
		for(int j = 1;j <= 5;j++){
			for(int k = 0;k < 2;k++){
				cout<<f[j][i][k]<<" "<<da[j][i][k]<<" "<<db[j][i][k]<<endl;
			}
		}
	}
	
	return 0;
	for(int i=1;i<=n;i++)
	{
		calc(i,x0);
		double nowans=(double)la/(double)lb;
		if(nowans<ans)
		{
			ans=nowans;
			ansid=i;
		}
		else
			if(nowans==ans && h[ansid]<h[i])
				ansid=i;
	}
	cout<<ansid<<endl;//4、求解问题1
	for(int i=1;i<=m;i++)
	{
		calc(s[i],x[i]);
		printf("%d %d\n",la,lb);
	}//5、求解问题2
	return 0;
}
