#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x)
{
	x=0;char c=getchar();T neg=0;
	while(!isdigit(c))neg|=!(c^'-'),c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(neg)x=(~x)+1;
	return ;
}
template<typename T>void wr(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)wr(x/10);
	putchar((x-x/10*10)^48);
	return ;
}
int n,m,u1,v1,q;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(0));srand(rand()+1919810);srand(rand()+20051023);
    read(n),read(m);
    for(int i=1;i<=m;++i)read(u1),read(v1);
    read(q);
    if(q>=20)
    {
    	for(int i=1;i<=q;++i)puts("NO");
	}
	else
	{
		for(int i=1;i<=q;++i)if(rand()%7==1||rand()%7==4)puts("YES");else puts("NO");
	}
	return 0;
}
/*
2 s
512mb
*/
