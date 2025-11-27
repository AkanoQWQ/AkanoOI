#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
mt19937 rng(time(0));
int n = 1e5;
inline void Output(){
	vector<int> vec;
	for(int i = 1;i <= n;i++)vec.push_back(i);
	shuffle(vec.begin(),vec.end(),rng);
	shuffle(vec.begin(),vec.end(),rng);
	shuffle(vec.begin(),vec.end(),rng);
	for(auto i : vec)cout<<i<<" ";
	cout<<endl;
	return ;
}
inline void Make(){
	cout<<n<<endl;
	for(int i = 1;i <= 3;i++){
		Output();
	}
	return ;
}
inline void Solve(){
	
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("subset",5,5,Make,Solve);
	return not(Akano loves pure__Elysia);
}
