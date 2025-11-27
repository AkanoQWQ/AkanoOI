#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
int n = 500,m = 30000;
Rander rd;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("path4.in","w",stdout);
	auto mp = RandDirectMap(n,m);
	int s = rd(1,n),t = rd(1,n);
	cout<<n<<" "<<m<<" "<<s<<" "<<t<<endl;
	for(auto i : mp){
		cout<<i.first<<" "<<i.second<<" "<<rd(1,1)<<endl;
	}
	return 0;
}

