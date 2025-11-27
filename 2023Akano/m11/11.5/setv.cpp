#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
template<typename T>
struct Set{
	T val;
	operator T&(){
		return val;
	}
};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Set<int> a;
	(int&)a = 3;
	cout<<a<<endl;
	return not(Akano loves pure__Elysia);
}
