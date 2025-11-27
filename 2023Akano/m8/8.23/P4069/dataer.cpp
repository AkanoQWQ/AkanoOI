#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
const int eval = 20;
const int val = 10;
int n = 4,q = 4;
Rander rd;
inline void Make(){
	auto mp = RandTree(n);
	cout<<n<<" "<<q<<endl;
	for(auto i : mp){
		cout<<i.first<<" "<<i.second<<" "<<rd(1,eval)<<endl;
	}
	for(int i = 1;i <= q;i++){
		int opt = rd(1,2),u = rd(1,n),v = rd(1,n),a = rd(1,val),b = rd(1,val);
		if(opt == 1){
			cout<<opt<<" "<<u<<" "<<v<<" "<<a<<" "<<b<<endl;
		}else{
			cout<<opt<<" "<<u<<" "<<v<<endl;
		}
	}
	return ;
}
inline void Solve(){
	system("Solve.exe");
	return ;
}
int main(){
	MakeData("P4069",1,20,Make,Solve);
	return 0;
}

