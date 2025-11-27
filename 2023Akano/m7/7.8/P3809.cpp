#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using pii = pair<int,int>;
const int base = 29;
const int MAXN = 1e6 + 6;
string str;
vector<pii> vec;
ull hs[MAXN],_b[MAXN];
inline ull HashVal(int l,int r){
	return hs[r] - hs[l-1] * _b[r-l+1];
}
bool cmp(pii a,pii b){
	const int len = min(a.second-a.first,b.second-b.first) + 1;
	int l = 0,r = len;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(HashVal(a.first,a.first+mid) != HashVal(b.first,b.first+mid)){
			r = mid-1;
		}else{
			l = mid;
		}
	}
	return str[a.first+l] < str[b.first+l];
}
int sa[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>str;
	_b[0] = base;
	for(int i = 1;i < str.length();i++)_b[i] = _b[i-1] * base;
	hs[0] = str[0] - 'a';
	for(int i = 1;i < str.length();i++){
		hs[i] = (hs[i-1] * base) + (str[i] - 'a');
	}
	for(int i = 0;i < str.length();i++){
		vec.push_back(make_pair(i,str.length()-1));
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i = 0;i < vec.size();i++){
		sa[vec[i].first] = i + 1; 
	}
	for(int i = 0;i < str.length();i++){
		cout<<sa[i]<<" ";
	}
	return 0;
}

