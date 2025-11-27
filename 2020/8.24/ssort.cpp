#include<bits/stdc++.h>
using namespace std;
int x,y,i,wei,c,c2,j;
struct num{
	int self,dao;
}num[106],ccc; 

int main(){
	freopen("ssort.in","r",stdin);
	freopen("ssort.out","w",stdout);
	cin>>x>>y;
	for(i = 0;i <=y - x;i++){
		wei = 1;
		num[i].self = i+x;
		c = num[i].self;
		while(c >= 10){
			c /= 10;
			wei *= 10; 
		}
		c = num[i].self;//25
		while(c){
			c2 = c % 10;
			num[i].dao += c2 * wei;
			wei /= 10;
			c /= 10;
		}//500
	}
	for(i = 0;i <= y-x;i++){
		for(j = i;j <= y-x;j++){
			if(num[i].dao > num[j].dao){
				ccc = num[i];
				num[i] = num[j];
				num[j] = ccc;
			}
		}
	}
	for(i = 0;i <= y-x;i++){
		cout<<num[i].self<<endl;
	}
	return 0;
}
