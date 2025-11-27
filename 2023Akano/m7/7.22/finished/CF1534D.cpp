#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1018 + 1108;
bool e[MAXN][MAXN];
int n,dep[MAXN],cnt0,cnt1,c;
inline void Query(){
	cin>>n;
	cout<<"? 1"<<endl;//include flush
	for(int i = 1;i <= n;i++){
		cin>>dep[i];
		if(dep[i] == 1)e[1][i] = e[i][1] = true;
		cnt0 += !(dep[i] & 1),cnt1 += (dep[i] & 1);
	}
	int cont = (cnt0 > cnt1) ? 0 : 1;
	for(int u = 2;u <= n;u++){
		if((dep[u] & 1) == cont)continue;
		cout<<"? "<<u<<endl;
		for(int v = 1;v <= n;v++){
			cin>>c;
			if(c == 1)e[u][v] = e[v][u] = true;
		}
	}
	return ;
}
inline void Output(){
	cout<<"!"<<endl;
	for(int u = 1;u <= n;u++){
		for(int v = u + 1;v <= n;v++){
			if(e[u][v])cout<<u<<" "<<v<<endl;
		}
	}
	cout<<flush;
	return ;
}
int main(){
	Query();
	Output();
	return 0;
}
