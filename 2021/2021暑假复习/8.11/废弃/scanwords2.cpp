#include<bits/stdc++.h>
using namespace std;
int n,c3,i,j,last_w[260],m;
char c1,c2;
struct snn{
	string s;
	int page;
}sn[20001],snn_c;
string s;
int main(){
	freopen("scanwords.in","r",stdin);
	freopen("scanwords.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>sn[i].s;
		cin>>sn[i].page;
	}
	for(i = 0;i < n;i++){
		for(j = i+1;j < n;j++){
			if(sn[i].s[0] > sn[j].s[0]){
				snn_c = sn[i];
				sn[i] = sn[j];
				sn[j] = snn_c;
			}else if(sn[i].s[1] > sn[j].s[1]&&sn[i].s[0] == sn[j].s[0]){
				snn_c = sn[i];
				sn[i] = sn[j];
				sn[j] = snn_c;
			}
		}
	}
	for(i = 0;i < n;i++){
		last_w[int(sn[i].s[0])] = i;
	}
	for(i = 1;i < 260;i++){
		if(last_w[i] == 0)last_w[i] = last_w[i-1];
	}
	cin>>m;
	while(m--){
		cin>>s;
		c1 = s[0],c2 = c1;
		i = last_w[int(c1)-1];
		while(s != sn[i].s){
			i++;
		}
		cout<<sn[i].page<<endl;
	}
	return 0;
}

