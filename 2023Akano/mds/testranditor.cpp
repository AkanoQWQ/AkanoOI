#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
template<typename Itor>
inline Itor RandItor(Itor begin,Itor end){//左闭右开，适配STL
	vector<Itor> vec;
	for(Itor it = begin;it != end;it++){
		vec.push_back(it);
	}
	mt19937 rng(time(0));
	return vec[rng() % vec.size()];
}
vector<int> vec;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= 6;i++)vec.push_back(i);
	auto it = RandItor(vec.begin(),vec.end());
	cout<<(*it)<<endl;
	return not(Akano loves pure__Elysia);
}
