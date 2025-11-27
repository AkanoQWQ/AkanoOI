#include<bits/stdc++.h>
using namespace std;
string a,b;
int i,j,same,k,cache,s;
char sames[30];
int main(){
	freopen("jqr.in","r",stdin);
	freopen("jqr.out","w",stdout);
	cin>>a>>b;
	for(i = 0;i < a.length();i++){
		for(j = 0;j < b.length();j++){
			if(a[i] == b[j]){
				for(s = 0;s < same;s++){
					if(a[i] == sames[s]){
						cache = 1;
					}
				}
			if(!cache){
					sames[same] = a[i];
					same += 1;
				}
				cache = 0;
			}	
		}
	}
	if(!same){
		cout<<"WuXiao";
		return 0;
	}
	if(!(same-1)){
		cout<<"ZhiHui"<<endl<<sames[0];
	}else{
		cout<<"XunLuo"<<endl<<same<<endl;
		for(i = 65;i < 91;i++){
			for(j = 0;j < same;j++){
				if(int(sames[j]) == i){
					k++;
					if(k < same){
						cout<<sames[j]<<"-";
					}else{
						cout<<sames[j];
					}
				}
			}
		}
	}
	return 0;
}
