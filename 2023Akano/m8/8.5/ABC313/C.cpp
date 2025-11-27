#include<bits/stdc++.h>
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int MAXN = 2e5 + 6;
ll sum,n,a[MAXN],upp,tail,ans,avg;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		sum += a[i];
	}
	avg = sum / n;
	upp = sum - (avg * n);
	sort(a+1,a+n+1);
//	cout<<"SUM "<<sum<<" UPP "<<upp<<endl;
	for(int i = n;i >= 1;i--){
		if(tail < upp){
			++tail;
			ans += abs(a[i] - (avg+1));
		}else{
			ans += abs(a[i] - avg);
		}
	} 
	cout<<ans/2<<endl;
	return 0;
}
