#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 10 + 18 + 11 + 8;
template<typename T,int SIZE>
class SparseTable{
private:
	T vals[SIZE][int(ceil(sqrt(SIZE)))];
	int logval[SIZE];
public:
	template<typename Itor>
	inline void Build(Itor _begin,Itor _end){//左闭右开
		int cnt = 0,nowlog = 0;
		for(Itor it = _begin;it != _end;it++){
			vals[++cnt][0] = *it;
		}
		for(int i = 2;i <= cnt;i++){
			logval[i] = logval[i/2] + 1;
		}
		nowlog = logval[cnt];
		for(int i = 1;i <= nowlog;i++){
			for(int j = 1;j <= cnt;j++){
				const int nxt = min(j + (1<<(i-1)),cnt);
				vals[j][i] = max(vals[j][i-1],vals[nxt][i-1]);
			}
		}
		return ;
	}
	inline T Query(int l,int r){
		int nowlog = logval[r - l + 1];
		return max(vals[l][nowlog],vals[r - (1<<nowlog) + 1][nowlog]);
	}
};
SparseTable<int,MAXN> st;
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
inline void Write(int x){
	const static int WriteSize = 1018;
	static int buff[WriteSize];
	int tail = 0;
	if(x < 0){
		putchar('-');
		x = -x;
	}else if(x == 0){
		putchar('0');
	}
	while(x > 0){
		buff[++tail] = x % 10;
		x /= 10;
	}
	for(int i = tail;i > 0;i--){
		putchar('0' + buff[i]);
	}
	return ;
}
int n,q,arr[MAXN];
int main(){
	n = Read(),q = Read();
	for(int i = 1;i <= n;i++){
		arr[i] = Read();
	}
	st.Build(arr+1,arr+n+1);
	while(q--){
		int l = Read(),r = Read();
		Write(st.Query(l,r)),putchar('\n');
	}
	return not(Akano loves pure__Elysia);
}
