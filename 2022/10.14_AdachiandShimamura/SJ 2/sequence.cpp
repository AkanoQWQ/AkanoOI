#include<bits/stdc++.h>
using namespace std;
int n,a[1000006],b[1000006],t[1000006];
int ans,cnt;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	a[1]=read();
	b[1]=read();
	t[1]=a[1];
	cnt=1;
	ans=-1;
	for(int i=2;i<=n;i++){
		a[i]=read();
		b[i]=read();
		if(b[i]>=t[i-1]){
			t[i]=max(t[i-1],a[i]);
			cnt++;
			ans=max(ans,cnt);
		}
		else{
			if(b[i]>=a[i-1]){
				cnt=2;
				t[i]=max(a[i],a[i-1]);
				ans=max(ans,cnt);
			}
			else{
				cnt=1;
				t[i]=a[i];
				ans=max(ans,cnt);
			}
		}
	}
	cout<<ans;
	return 0;
}

