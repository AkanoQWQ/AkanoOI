#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int Read(){
	int ret;
	cin>>ret;
	return ret;
}
inline pair<int,int> MP(int x,int y){
	return {x,y};
}
int a[3];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	pair<int,int> pr = {Read(),Read()};
	cout<<pr.first<<","<<pr.second<<endl;
	cout<<pr.first<<","<<pr.second<<endl;
//	pr = MP(Read(),Read());
	cout<<pr.first<<","<<pr.second<<endl;
	return not(Akano loves pure__Elysia);
}
