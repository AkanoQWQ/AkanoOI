#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 6;
int n,k,a[MAXN],g,l,r,lastr;
long long ans;
int gcd(int a,int b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(g == 0){
			g = a[i];
		}else{
			g = gcd(g,a[i]);
		}
	}
	
	for(int i = n;i >= 1;i--){
		if(g != a[i]){
			lastr = i;
		}else{
			break;
		}
	}
	if(a[n] == g){
		for(int i = n;i >= 1;i--){
			if(g == a[i]){
				lastr = i;
			}else{
				break;
			}
		}
	}else{
		ans += r - l + 1;
	} 
	l = 1,r = 1;
	for(int i = 1;i <= lastr;i++){
		r = i;
		if(a[i] == g){
			//处理前一段 
			int pos = i;
			while(a[pos+1] == g && pos < n){
				pos++;
			}
			if(pos == n){
				ans = r - l + 1;
			}
			if(pos - r > k){
				//断开
				ans += r - l + 1;
				i = pos + 1;
				l = pos + 1,r = pos + 1;
			}else{
				//不断 
				i = pos;
			}
		}
	}
	return 0;
}
