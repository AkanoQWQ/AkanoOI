#include<bits/stdc++.h>
#include<AL/DB.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	GUID guid1,guid2;
	ll res = InlineIsEqualGUID(guid1,guid2);
	cout<<res<<endl;
	guid1 = guid2;
	res = InlineIsEqualGUID(guid1,guid2);
	cout<<res<<endl;
	return not(Akano loves pure__Elysia);
}
