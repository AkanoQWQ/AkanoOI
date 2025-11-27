#include<bits/stdc++.h>
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

vector<pair<ld,int> > pop;
ld a,b;
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a>>b;
		pop.push_back(make_pair(-a / (a+b),i));
	}
	sort(pop.begin(),pop.end());
	for(auto i : pop){
		cout<<i.second<<" ";
	}
	return 0;
}
