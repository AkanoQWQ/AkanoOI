#include<bits/stdc++.h>
using namespace std;
long long a,b,i,j,n,L,Q,step,obj,days,tail,maxtail,cache;
long long hotels[1000006];
int main(){
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>hotels[i];
	}
	cin>>L>>Q;
	while(Q--){
		cin>>a>>b;
		days = 0;
		step = a-1;
		obj = b-1;
		if(step > obj){
			cache = obj;
			obj = step;
			step = cache;
		}
		//cout<<"开始"<<step<<"目标"<<obj<<endl;
		if(step < obj){
			while(1){
				if(step >= obj){
					break;
				}
				tail = step;
				//cout<<"tail为"<<tail<<",";
				while(1){
					tail++;
					if(hotels[tail] - hotels[step] <= L && hotels[tail] != 0){
						maxtail = tail;
					}else{
						break;
					}
				}
				days++;
				//cout<<"差为:"<<hotels[tail] - hotels[step]<<",";
				step = maxtail;
				//cout<<days<<"天走到了"<<step<<",maxtail为"<<maxtail<<endl;
			}
			cout<<days<<endl;
		}
	}
	return 0;
}

