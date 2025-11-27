#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
int n,a[MAXN],mx,now = -10000;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++){
		mx = max(mx,a[i]);
	}
	const int OBJ = mx / 2;
	for(int i = 1;i <= n;i++){
		if(a[i] != mx && abs(a[i] - OBJ) < abs(OBJ - now))now = a[i];
	}
	cout<<mx<<" "<<now<<endl;
	return 0;
}
