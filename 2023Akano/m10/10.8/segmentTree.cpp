#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;


SegmentTree<1024> tr(true);
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	tr(1,199) += 2;
	cout<<tr(1,4)<<endl;
	return not(Akano loves pure__Elysia);
}
