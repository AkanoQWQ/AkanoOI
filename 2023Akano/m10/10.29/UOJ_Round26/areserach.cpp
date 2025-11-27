#include<bits/stdc++.h>
#include<AL/colorout.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using vi = vector<int>;
inline void Merge(vi v1,vi v2){
	auto it1 = v1.begin(),it2 = v2.begin();
	while(it1 != v1.end() && it2 != v2.end()){
		if((*it1) <= (*it2)){
			kout<<"[red]"<<*(it1++)<<"[/red] ";
		}else{
			kout<<"[blue]"<<*(it2++)<<"[/blue] ";
		}
	}
	while(it1 != v1.end()){
		kout<<"[red]"<<*(it1++)<<"[/red] ";
	}
	while(it2 != v2.end()){
		kout<<"[blue]"<<*(it2++)<<"[/blue] ";
	}
	return ;
}
vi vec1 = {7,2,6,3,8,4};
vi vec2 = {1,7,2,7,3,4};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Merge(vec1,vec2);
	return not(Akano loves pure__Elysia);
}
