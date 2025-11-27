#include<bits/stdc++.h>
using namespace std;
const int n = 8;
const int m = 10;
int no(int x,int y){
	return (x-1)*m + y;
}
pair<int,int> deno(int num){
	pair<int,int> a;
	a.second = num;
	while(a.second > m)a.second -= m;
	a.first = (num-a.second)/m + 1;
	return a;
}
bool u[200006];
int main(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int ns = no(i,j);
			pair<int,int> np = deno(ns);
			if(u[no(i,j)] == 1)cout<<"NONONNONONONOO"<<endl;
			cout<<i<<","<<j<<":"<<np.first<<","<<np.second<<endl;
			u[no(i,j)] = 1;
		}
	}
    return 0;
}


