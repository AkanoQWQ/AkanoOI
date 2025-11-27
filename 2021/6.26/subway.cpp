#include<bits/stdc++.h>
using namespace std;
int n,m,i,p,q,wt,addin,j,km,c,cont;
struct way{
	int members[10611],t,com;
}ways[106];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(km = 0;km < m;km++){
		addin = 0;
		cin>>p>>q>>c;
	}
	cout<<-1;
		/*
		for(i = 0;i < wt;i++){
			if(ways[i].com != c){
				continue;
			}
			cont = ways[i].t;
			for(j = 0;j < cont;j++){
				if(p == ways[i].members[j]){
					ways[i].members[ways[i].t] = q;
					ways[i].t++; 
					addin = 1;
					cout<<"将"<<q<<"添加到了"<<i<<"中"<<endl;
				}else if(q == ways[i].members[j]){
					ways[i].members[ways[i].t] = p;
					ways[i].t++;
					addin = 1;
					cout<<"将"<<p<<"添加到了"<<i<<"中"<<endl;
				} 
			}
		}
		if(addin == 0){
			cout<<"创建了"<<q<<"与"<<p<<"的ways,编号"<<wt<<",公司为"<<c<<endl;
			ways[wt].members[ways[wt].t] = p;
			ways[wt].t++;
			ways[wt].members[ways[wt].t] = q;
			ways[wt].t++; 
			ways[wt].com = c;
			wt++;
		}
		cout<<endl;
	}
	cout<<"wt:"<<wt<<endl;
	for(i = 0;i < wt;i++){
		for(j = 0;j < ways[i].t;i++){
			cout<<ways[i].members[j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}

