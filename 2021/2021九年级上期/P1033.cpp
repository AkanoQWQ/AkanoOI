#include<bits/stdc++.h>
using namespace std;
long long n,k,a[106],b[106],c[106],anses[100006],tail,rans;
bool PRI(long long num){
	if(num == 2)return 1;
	for(int i = 2;i <= sqrt(num);i++){
		if(num % i == 0)return 0;
	}
	return 1;
}
void cala(){
	int ans = 0;
	for(int i = 0;i < k;i++){
		cout<<c[i]<<" ";
		ans += c[i];
	}
	cout<<endl;
	if(PRI(ans))rans++;
	return ;
}
void search(int ns){
	for(int i = 0;i < n;i++){
		if(b[i] == 0 && a[i] >= c[ns-2]){
			b[i] = 1;
			c[ns-1] = a[i];
			if(ns == k){
				cala();
			}else{
				search(ns+1);
			}
			b[i] = 0;
		}
	}
	return ;
}
int main(){
	freopen("P1033.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	search(1);
	cout<<rans; 
	return 0;
}

