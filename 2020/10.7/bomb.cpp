#include<bits/stdc++.h>
using namespace std;//remember long long  
long long n,d,a,x,h,c[200006],i,ans,temp,act,l,r,mid;
struct m{
	int h;
	int w;
}m[200006];
bool comp(m a,m b){
	return a.w<b.w;
}
int main(){
	//freopen("bomb.in","r",stdin);
	//freopen("bomb.out","w",stdout);
	cin>>n>>d>>a;
	for(i = 1;i <= n;i++){
		cin>>m[i].w>>m[i].h;
	}
	sort(m+1,m+n+1,comp);
	i = 1;
	d *= 2;
	while(i <= n){
		temp -= c[i];
		m[i].h -= temp;
		if(m[i].h > 0){
			act = (m[i].h-1+a)/a;
			ans += act;
			temp += a * act;
			l = 0;
			r = n + 1;
			while(l<r){
				mid = l+r>>1;
				if(m[mid].x > m[i].x+d){
					r = mid;
				}else{
					l = mid++;
				}
			}
			if(l != n+1)c[l] += a * act;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
