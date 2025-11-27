#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
const int MAXN = 1e5 + 6;
inline int BF(const int& pos,int now,const string& str){
	while(pos + now < str.length() && str[pos+now] == str[now])++now;
	return now;//now include pos itself so we dont "-1"
}
inline vi ExKMP(const string& str){
	int ret = 0,len = str.length(),l = 0,r = 0;
	vi d(len);
	for(int i = 1;i < len;i++){
		int k = 0;
		if(i <= r && d[i-l] < r - i + 1){
			k = d[i-l];
		}else{			
			k = max(r-i+1,0);
			k = BF(i,k,str);
		}
		if(i + k - 1 > r){
			l = i,r = i + k - 1;
		}
		d[i] = k;
	}
	d[0] = str.length();
	return d;
}
int n,q,len,l[MAXN];
string a,b;
int main(){
	freopen("B1644.in","r",stdin);
	cin>>n>>a>>q;
	len = a.length();
	a += ".";
	for(int i = 1;i <= q;i++){
		cin>>b;
		a += b;
		l[i] = b.length();
		for(int j = b.length();j < len;j++)a += "#";
	} 
	cout<<a<<endl;
	vi z = ExKMP(a);
	for(int i = 1;i <= q;i++){
		const int ST = 1 + len * i;
		const int ED = len * (i+1);
		int ans = 0;
		cout<<i<<" ST "<<ST<<" TO "<<ED<<endl;
		for(int j = ST;j <= ED;j++){
			cout<<z[j]<<",";
			ans += z[j]+1;
			if(z[j] == l[i]){
				--ans;
				break;
			}
		}
		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
