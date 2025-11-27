#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
struct BIGINT{
	istringstream iss;
	operator void*() const{
		return iss.fail() ? 0 : const_cast<BIGINT*>(this);
	}
	BIGINT& operator>>(auto& content){
		iss>>content;
		return *this;
	}
}s;
int a;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	s.iss.str("12341234 44444");
	while(s>>a){
		cout<<a<<endl;
	}
	return not(Akano loves pure__Elysia);
}

