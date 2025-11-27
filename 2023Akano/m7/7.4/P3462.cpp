#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
#define int long long
//#pragma GCC optimize(2)
using namespace std;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXN = 1e5 + 6;
int n,Mcnt,tail,cnt[MAXN],val[MAXN],w[MAXN],m[MAXN],ans[MAXN],Tans;
signed main(){
	freopen("P3462.in","r",stdin);
	n = Read(),Mcnt = Read();
	for(int i = 1;i <= n;i++){
		w[i] = Read();
	}
	for(int i = 1;i <= Mcnt;i++){
		m[i] = Read();
	}
	sort(m + 1,m + Mcnt + 1);
	for(int i = 1;i <= Mcnt;i++){
		if(m[i] == m[i-1]){
			cnt[tail]++;
		}else{
			cnt[++tail] = 1;
			val[tail] = m[i];
		}
	}
	for(int i = 1;i <= n;i++){
		int t2 = tail;
		while(w[i] && t2){
			if(w[i] >= val[t2]){
				ans[t2] += w[i] / val[t2];
				w[i] %= val[t2];
			}
			--t2;
		}
	}
	val[0] = 1;//should'nt been used
	for(int i = 1;i < tail;i++){
		if(ans[i] < cnt[i]){
			const int comp = val[i+1] / val[i];
			const int left = cnt[i] - ans[i];
			const int psd = ceil(1.0f * left / comp);
			ans[i] += psd * comp,ans[i+1] -= psd; 
		}
	}
	for(int i = tail;i >= 1;i--){
		if(ans[i] < 0){
			const int need = abs(ans[i]);
			const int comp = val[i] / val[i-1];
			ans[i-1] -= need * comp;
			ans[i] = 0;
		}
		Tans += min(ans[i],cnt[i]);
	}
	Write(Tans);
	return 0;
}
