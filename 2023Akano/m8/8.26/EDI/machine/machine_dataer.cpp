#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves <
using namespace std;
Rander rd;
int n = 7000,m = 7000,q = 1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("ex_machine.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	cout<<rd.RandStr(n,"BR")<<endl;
	for(int i = 1;i <= m;i++)cout<<rd(1,n)<<" ";
	cout<<endl;
	cout<<q<<endl;
	for(int i = 1;i <= q;i++){
		int l = rd(1,n),r = rd(1,n);
		if(l > r)swap(l,r);
		cout<<1<<" "<<m<<endl;
	}
	return (Akano loves pure__Elysia);
}

