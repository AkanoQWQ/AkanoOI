#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
inline void Make(){
	int n = 4;
	vector<int> vec;
	for(int i = 1;i <= n;i++){
		vec.push_back(i);
		vec.push_back(i);
		vec.push_back(i);
	}
	for(int i = 1;i <= n / 4;i++){
		int k = rd(1,vec.size()),j = rd(1,vec.size());
		swap(vec[k-1],vec[j-1]);
	}
	cout<<n<<endl;
	for(auto i : vec){
		cout<<i<<" ";
	}
	cout<<endl;
	return ;
}
inline void Solve(){
	system("circle_std.exe");
	return ;
}
int main(){
	MakeData("circle",1,100,Make,Solve);
	return not(Akano loves pure__Elysia);
}
