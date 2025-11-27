#include<bits/stdc++.h>
#include<AL/rander.h>
using namespace std;
const int MAXN = 200000;
const int MAXV = 1<<28;
Rander rd(1,MAXV);
int n = 200000;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("AT092.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd()<<" ";
	}
	cout<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd()<<" ";
	}
	cout<<endl;
	return 0;
}

