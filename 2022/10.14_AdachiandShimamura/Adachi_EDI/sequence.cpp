#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,t,a[1000006],b[1000006],ans = 1;//100000
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read(),b[i] = read();
	}
	for(int j = 1;j <= n;j++){
		if(n-j+1 <= ans)break;
		if(a[j] > a[j-1] && j != 1)continue;
		bool STP = 0;
		int t = a[j];
		for(int s = j+1;s <= n;s++){
			if(a[s] > t){
				t = a[s];
			}else if(b[s] < t){
				ans = max(ans,s-j);
				STP = 1;
				break;
			}
		}
		if(!STP){
			ans = max(ans,n-j+1);
			break;
		}
	}
	cout<<ans;
	return 0;
}

