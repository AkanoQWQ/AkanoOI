#include<bits/stdc++.h>
using namespace std;
const int MAXN = 506;
const long double EPS = 1e-7;
int n,m,ans,answ;
struct Object{
	long double z[MAXN];
	int c;
}o[MAXN];
bool cmp4obj(Object a,Object b){
	return a.c < b.c;
}
void show(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<o[i].z[j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return ;
}
int main(){
	freopen("buyy.in","r",stdin);
	freopen("buyy.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>o[i].z[j];
		}
	}
	for(int i = 1;i <= n;i++){
		cin>>o[i].c;
	}
	sort(o+1,o+n+1,cmp4obj);
	for(int i = 1;i <= n;i++){
		if(abs(o[i].z[i]) <= EPS){
			int swaptail = -1;
			for(int j = i+1;j <= n;j++){
				if(abs(o[j].z[i]) > EPS){
					swaptail = j;
					break;
				}
			}
			if(swaptail != -1){
				swap(o[i],o[swaptail]);
			}
		}
		if(abs(o[i].z[i]) <= EPS)continue;
		long double aaa = o[i].z[i];
		for(int j = m;j >= i;j--){
			o[i].z[j] /= aaa;
		}
		for(int s = i+1;s <= n;s++){
			if(s == i || abs(o[s].z[i]) <= EPS)continue;
			long double cccc = o[s].z[i];
			for(int k = m;k >= i;k--){
				o[s].z[k] -= cccc * o[i].z[k];
			}
		}
	}
	for(int i = 1;i <= min(n,m);i++){
		bool able = 0;
		for(int j = i;j <= m;j++){
			if(abs(o[i].z[j]) > EPS){
				able = 1;
				break;
			}
		}
		if(able){
			answ += o[i].c;
			ans++;
		}
	}
	cout<<ans<<" "<<answ;
	return 0;
}
