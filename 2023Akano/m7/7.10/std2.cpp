#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
const int MAXSZ = 122;
int fir[MAXN],sec[MAXN],sa[MAXN],c[MAXN];
string s;
inline void GetSA(int len){
	const int n = len - 1;
	for(int i = 1;i <= n;i++){
		fir[i] = s[i];
		++c[fir[i]];
	}
	for(int i = 1;i <= MAXSZ;i++)c[i] += c[i-1];
	for(int i = n;i >= 1;i--)sa[c[fir[i]]--] = i;
	for(int k = 1;k <= n;k *= 2){
		int tail = 0;
		for(int i = n - k + 1;i <= n;i++){
			sec[++tail] = i;
		}
		for(int i = 1;i <= n;i++)if(sa[i] > k)sec[++tail] = sa[i] - k;
		for(int i = 1;i <= MAXSZ;i++)c[i] = 0;
		for(int i = 1;i <= n;i++)c[fir[i]]++;
		for(int i = 1;i <= MAXSZ;i++)c[i] += c[i-1];
		for(int i = n;i >= 1;i--){
			sa[c[fir[sec[i]]]--] = sec[i];//?WHY?
			sec[i] = 0;
		}
		swap(fir,sec);
		fir[sa[1]] = 1,tail = 1;
		for(int i = 2;i <= n;i++){//?WHY?
			fir[sa[i]] = ((sec[sa[i]] == sec[sa[i-1]]) && (sec[sa[i]+k] == sec[sa[i-1]+k])) ? tail : ++tail;
		}
		if(tail == n)break;
	}
	return ;
}
inline void Output(int len){
	for(int i = 1;i < len;i++){
		cout<<sa[i]<<" ";
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;s = "." + s;
	GetSA(s.length());
	Output(s.length());
	return 0;
}
