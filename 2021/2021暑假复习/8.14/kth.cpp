#include<bits/stdc++.h>
using namespace std;
long long n,q,a[102006],b[102006],i,j,tail = 1,cnt,addd[102006],adk;
struct qq{
	int que,num,ans;
}k[102006];
bool comp1(qq qa,qq qb){
	return qa.que < qb.que;
}
bool comp2(qq qa,qq qb){
	return qa.num < qb.num;
}
int main(){
	freopen("kth.in","r",stdin);
	//freopen("kth.out","w",stdout);
	cin>>n>>q;
	for(i = 1;i <= n;i++){
		cin>>a[i];
		b[i] = a[i] - a[i-1] - 1;
	}
	for(i = 1;i <= q;i++){
		cin>>k[i].que;
		k[i].num = i;
	}
	sort(k,k+q+1,comp1);
	for(j = 1;j <= q;j++){
		if(cnt >= k[j].que){
			k[j].ans = a[tail] - (cnt-k[j].que) - 1;
			continue;
		}
		if(tail > n){
			k[j].ans = a[n] + (k[j].que-adk);
		}
		while(cnt < k[j].que&&tail <= n){
			if(addd[tail] == 0){
				cnt += b[tail];
				addd[tail] = 1;
			}
			if(tail == n){
				adk = cnt;
			}
			//cout<<j<<":(tail)"<<tail<<" "<<cnt<<",que:"<<k[j].que<<endl;
			if(cnt >= k[j].que){
				k[j].ans = a[tail] - (cnt-k[j].que) - 1;
				break;
			}
			tail++;
			if(tail > n){
				k[j].ans = a[n] + (k[j].que-adk);
			}
		}
		if(tail > n){
			k[j].ans = a[n] + (k[j].que-adk);
		}
	}
	sort(k,k+q+1,comp2);
	for(i = 1;i <= q;i++){
		cout<<k[i].ans<<endl;
	}
	return 0;
}
//0 3 5 6 7 0 0 0 0 0 
//0 3 2 1 1 0 0 0 0 0
//0 2 1 0 0 
//Q:3(4)  Q:4(8)  Q:5(9) Q:2(2)
//0 3 5 6 7 9 13 16 0 0  a[n]+(que-adk) 
//0 3 2 1 1 2 4 3 0 0
//0 2 1 0 0 1 3 2 0 0
//0 2 3 3 3 4 7 9 0 0
//Q:6(11) Q:7(12) Q:8(14) Q:11(18)
//0 3 5 6 7

//0 3 5 6 7
//0 3 2 1 1
//0 2 1 0 0
//0 2 3 3 3
