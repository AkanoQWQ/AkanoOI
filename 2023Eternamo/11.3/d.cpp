#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int n,a[MAXN],b[MAXN],res;
vector<int> vec,cache,no;
mt19937 rng(time(0));
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i < n;i++)cin>>a[i];
	for(int i = 2;i <= n;i++){
		b[i] = b[i-1] ^ a[i-1];
	}
	vec.reserve(2*n + 5),cache.reserve(2*n + 5),no.reserve(n+5);
	for(int i = 1;i <= n;i++){
		no.push_back(i);
	}
	for(int i = 0;i <= 2*n;i++){
		vec.push_back(i);
	}
	shuffle(vec.begin(),vec.end(),rng);
	shuffle(no.begin(),no.end(),rng);
	for(auto u : no){
		if(clock() > 0.9 * CLOCKS_PER_SEC)break;
		const int val = b[u];
		cache.clear();
		for(auto v : vec){
			if((v ^ val) < n){
				cache.push_back(v);
			}
		}
		swap(vec,cache);
	}
	for(int i = 1;i <= n;i++){
		cout<<(b[i] ^ vec.back())<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
