#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const double EPS = 0.1;
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f=-1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
} 
long long n;
double a[MAXN],ans = 123456789;
long long np1,np2;
int main(){
	n = read(); 
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	if(n == 2){
		printf("%lld",(long long)(min(a[1],a[2])));
		return 0;
	}else{
		for(int fp = 1;fp <= n;fp++){
			double cnt = 0;
			while(1){
				bool fd = 1;
				for(int i = 1;i <= n;i++){
					if(i == fp || a[i] <= EPS)continue;
					int l = i - 1;
					int r = i + 1;
					if(l == 0)l = r;
					if(r == n+1)r = 1;
					a[l] += a[i] / 2;
					a[r] += a[i] / 2;
					cnt += a[i];
					a[i] = 0;
					fd = 0;
					break;
				}
				if(fd){
					ans = min(ans,cnt);
					break;
				}
			}
		}
		printf("%.0lf",ans);
	}
	
	return 0;
}
