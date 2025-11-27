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
const int MAXN = 2006;
int n,k,bas[MAXN];
bool bit[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= k+1;i++){
		cout<<"? ";
		for(int j = 1;j <= k+1;j++){
			if(j == i)continue;
			cout<<j<<" ";			
		}
		cout<<endl<<flush;
		cin>>bas[i];
		if(bas[i] != bas[i-1]){
			bit[i] = !bit[i-1];
		}else{
			bit[i] = bit[i-1];
		}
	}
	for(int i = k+2;i <= n;i++){
		cout<<"? ";
		for(int j = 0;j < k;j++){
			cout<<i-j<<" ";
		}
		cout<<endl<<flush;
		int lst = 0,lstn = 0;
		if(i == k+2){
			lst = bas[1];
			lstn = 2;
		}else{
			lst = bas[i-1];
			lstn = i-k;
		}
		cin>>bas[i];
		if(bas[i] == lst){
			bit[i] = bit[lstn];
		}else{
			bit[i] = !bit[lstn];
		}
	}
	int sum = 0;
	for(int i = 2;i <= k+1;i++){
		sum += bit[i];
	}
	if(sum % 2 != bas[1]){
		for(int i = 1;i <= n;i++){
			bit[i] = !bit[i];
		}
	}
	cout<<"! ";
	for(int i = 1;i <= n;i++){
		cout<<bit[i]<<" ";
	}
	cout<<endl<<flush;
	return 0;
}
