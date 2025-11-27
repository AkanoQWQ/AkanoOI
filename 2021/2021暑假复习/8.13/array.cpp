#include<bits/stdc++.h>
using namespace std;
long long i,j,n,tail,arr_num,a[102006],l1,l2,r1,r2,c,lnum,rnum,ans;
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>c;
		a[i] = a[i-1] + c;
	}
	tail = n;
	if(n == 1){//以下 
		cout<<0;
		return 0;
	}else if(n == 2){
		if(a[1] == (a[2]-a[1])){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}//以上,特殊n值处理 (1-2)
	l1 = 1,l2 = 1,r1 = n,r2 = n;
	while(l2 < r2){
		lnum = a[l2] - a[l1-1];
		rnum = a[r1] - a[r2-1];
		if(lnum == rnum){
			//cout<<l2<<" "<<r2<<" 变换!"<<endl;
			l1 = l2+1,l2 = l2 + 1;
			r1 = r2-1,r2 = r2-1;
		}
		if(lnum < rnum){
			l2++;
			ans++;
		}else if(lnum > rnum){
			r2--;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

