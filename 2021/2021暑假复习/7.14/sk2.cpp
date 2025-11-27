#include<bits/stdc++.h>
using namespace std;
int n,maxw,w[106],v[106],i,ans;
int package[106][100006];//10600000
int sk(int cnt,int weight){//前n个物品 剩多少重量 值多少钱 
	int maxans,aw,a,b;
	aw = weight;
	cout<<cnt<<":test"<<endl;
	if(weight < 100006){
		if(package[cnt][weight] == 0){
			if(cnt < n-1){
				if(weight >= w[cnt]){
					a = sk(cnt+1,weight-w[cnt])+v[cnt];
					b = sk(cnt+1,weight);
					maxans = max(a,b);
					package[cnt+1][weight] = b;
					package[cnt+1][weight-w[cnt]] = a;
					package[cnt][weight] = maxans;
				}else{
					maxans = sk(cnt+1,weight);
					package[cnt][weight] = maxans;
				}
			}else{
				if(weight >= w[cnt]){
					maxans = v[cnt];
				}else{
					maxans = 0;
				}
			}
		}else{
			maxans = package[cnt][weight];
		}
	}else{
		if(cnt < n-1){
			if(weight >= w[cnt]){
				maxans = max(sk(cnt+1,weight-w[cnt])+v[cnt],sk(cnt+1,weight));
			}else{
				maxans = sk(cnt+1,weight);
			}
		}else{
			if(weight >= w[cnt]){
				maxans = v[cnt];
			}else{
				maxans = 0;
			}
		}
	}
	
	//cout<<"第"<<cnt<<"个数字maxans为"<<maxans<<",weight"<<weight<<",本来剩余"<<aw<<endl;
	return maxans;
}
int main(){
	freopen("sk.in","r",stdin);
	//freopen("sk.out","w",stdout);
	cin>>n>>maxw;
	for(i = 0;i < n;i++){
		cin>>w[i]>>v[i];
	}
	ans = sk(0,maxw);
	cout<<ans;
	return 0;
}

