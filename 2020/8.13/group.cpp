#include<bits/stdc++.h>
using namespace std;
class peo{
	public:
		int enemy[1006];
		int fri[1006];
		int frinum,enenum; 
		bool ingroup;
}pop[1006];
int p,x,y,i,j,k,cache,ans,n,m;
int main(){
	freopen("group.in","r",stdin);
	//freopen("realtion.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cin>>p>>x>>y; 
		if(cache == 0){
			pop[x].fri[pop[x].frinum] = y;
			pop[y].fri[pop[y].frinum] = x;
			pop[x].frinum++;
			pop[y].frinum++;
			for(j = 0;j < pop[y].enenum;j++){
				pop[x].enemy[pop[x].enenum] = pop[y].enemy[j];
				pop[x].enenum++;
			}
			for(j = 0;j < pop[x].enenum;j++){
				pop[y].enemy[pop[y].enenum] = pop[x].enemy[j];
				pop[y].enenum++;
			}
		}else{
			pop[x].enemy[pop[x].enenum] = y;
			pop[y].enemy[pop[y].enenum] = x;
			pop[x].enenum++;
			pop[y].enenum++;
			pop[y].fri[pop[y].frinum] = pop[x].enemy[pop[x].enenum];
			pop[y].frinum++;
			pop[pop[x].enemy[pop[x].enenum]].fri[pop[pop[x].enemy[pop[x].enenum]].frinum] = y;
			pop[pop[x].enemy[pop[x].enenum]].frinum++;
			pop[x].fri[pop[x].frinum] = pop[y].enemy[pop[y].enenum];
			pop[x].frinum++;
			pop[pop[y].enemy[pop[y].enenum]].fri[pop[pop[y].enemy[pop[y].enenum]].frinum] = x;
			pop[pop[y].enemy[pop[y].en
			enum]].frinum++;
			pop[x].enemy[pop[x].enenum] = y;
			pop[y].enemy[pop[y].enenum] = x;
		}
	} 
	for(i = 1;i <= n;i++){//!pop[i].ingroup
		if(pop[i].ingroup){
			cout<<i<<"已经加入"<<endl;
			for(j = 0;j < pop[i].frinum;j++){
				pop[pop[i].fri[j]].ingroup = 1;
				cout<<i<<" "<<pop[i].fri[j]<<endl;
			}
			continue;
		}
		pop[i].ingroup = 1;
		for(j = 0;j < pop[i].frinum;j++){
			pop[pop[i].fri[j]].ingroup = 1;
		}
		cout<<i<<"是组长"<<endl;
		ans++;
	}
	cout<<ans;
	return 0;
	
}
