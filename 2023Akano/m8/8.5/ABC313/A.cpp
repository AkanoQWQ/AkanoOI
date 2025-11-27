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
const int MAXN = 106;
int n,a[MAXN],obj;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(i != 1 && a[i] >= a[1] && a[i] > obj){
			obj = a[i]+1;
		}
	}
	cout<<max(0,obj - a[1]);
	return 0;
}
