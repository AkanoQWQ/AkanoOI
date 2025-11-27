#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e7 + 7;
string a,b,str;
int z[MAXN],l,r,lena,lenbs;
int Z(){
	cin>>a>>b;
	const int lena = a.length(),lenb = b.length();
	str = "." + a + "." + b,a = "." + a,b = "." + b;
	l = r = 0;
	for(int i = 1;i <= lenb;i++){
		if(z[i - l] < r - i + 1 && i <= r){
			z[i] = z[i - l];
		}else{
			z[i] = max(0,r - i);
			while(z[i] + i + 1 <= lenb && b[z[i]+1] == b[z[i]+i])++z[i];
		}
		if(i + z[i] > r){
			l = i,r = i + z[i];
		}
		cout<<z[i]<<" \n";
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	return Z();
}

