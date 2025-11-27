#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
struct PTR{
public:
	char strs[4];
	int val = 3;
	operator int*(){
		return &val;
	}
};
using PTRp = PTR*;
operator int*(PTRp obj){
	return new int();
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	PTR* ptrp = new PTR;
	PTR ptr;
	cout<<*((int*)(ptrp))<<" and "<<*((int*)(ptr));
	return not(Akano loves pure__Elysia);
}
