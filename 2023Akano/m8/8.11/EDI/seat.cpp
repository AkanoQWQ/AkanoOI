#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
int n,k,arr[MAXN],ans;
multiset<int,greater<int> > st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		if(i <= (n/2))st.insert(arr[i]);
	}
	for(int i = n;i > n/2;i--){
		auto it = st.lower_bound(arr[i]-k);
		if(it != st.end()){
			++ans;
			st.erase(it);
		}
	}
	cout<<ans;
	return 0;
}
