#include<bits/stdc++.h>
using namespace std;
const long double EPS = 1e-7;
const int MAXN = 106;
int n;
struct line{
	long double a[MAXN];
}l[MAXN];
long double ans[MAXN];
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n+1;j++){
			cin>>l[i].a[j];
		}
	}
	for(int i = 1;i <= n;i++){
		if(abs(l[i].a[i]) <= EPS){
			int swaptail = -1;
			for(int j = i+1;j <= n;j++){
				if(abs(l[j].a[i]) > EPS){
					swaptail = j;
					break;
				}
			}
			if(swaptail != -1){
				swap(l[i],l[swaptail]);
			}
		}
		if(abs(l[i].a[i]) <= EPS)continue;
		for(int j = n+1;j >= i;j--){
			l[i].a[j] /= l[i].a[i];
		}
		for(int j = i+1;j <= n;j++){
			if(abs(l[j].a[i]) <= EPS)continue;
			for(int k = n+1;k >= i;k--){
				l[j].a[k] -= l[j].a[i] * l[i].a[k];
			}
		}
	}
	/*for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n+1;j++){
			cout<<l[i].a[j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i = n;i >= 1;i--){
		ans[i] = l[i].a[n+1] / l[i].a[i];
		for(int j = i-1;j >= 1;j--){
			l[j].a[n+1] -= ans[i] * l[j].a[i];
		}
	}
	for(int i = 1;i <= n;i++){
		if(abs(ans[i]) >= EPS){
			//why?????我反过来写就不对了????? 
		}else{
			printf("No Solution");
			return 0;
		}
	}
	for(int i = 1;i <= n;i++){
		if(abs(ans[i]) >= EPS){
			printf("%.2Lf\n",ans[i]);
		}
	}
	return 0;
}
