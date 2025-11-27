#include<bits/stdc++.h>
using namespace std;
long long m,a,r,c,h,n,i,ans;
string s;
int main(){
	freopen("choice.in","r",stdin);
	freopen("choice.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>s;
		if(s[0] == 'M')m++;
		if(s[0] == 'A')a++;
		if(s[0] == 'R')r++;
		if(s[0] == 'C')c++;//60 / 6 = 10
		if(s[0] == 'H')h++;//123 132 213 231 312 321
	}//30
	ans += m*a*r;
	ans += m*a*c;
	ans += m*a*h;
	ans += m*r*c;
	ans += m*r*h;
	ans += m*c*h;
	ans += a*r*c;
	ans += a*r*h;
	ans += a*c*h;
	ans += r*c*h;
	cout<<ans;
	return 0;
}

