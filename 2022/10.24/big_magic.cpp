#include<bits/stdc++.h>
using namespace std;
const int len = 4;
const int llen = len+2;
const int MOD = 998244353;
const int MAXN = 250006;
int n,m,cnt;
struct mat{
	int a[llen][llen];
}op[7],mat1,mat0,mat1111;
int magic[MAXN][3];
mat operator *(mat a,mat b){
	mat c;
	int i,j,k;
	for(int i = 1;i <= 4;++i){
		for(int j = 1;j <= 4;++j){
			c.a[i][j] = 0;
			c.a[i][j] = (c.a[i][j] + (1ll * a.a[i][1] * b.a[1][j])) % MOD;
			c.a[i][j] = (c.a[i][j] + (1ll * a.a[i][2] * b.a[2][j])) % MOD;
			c.a[i][j] = (c.a[i][j] + (1ll * a.a[i][3] * b.a[3][j])) % MOD;
			c.a[i][j] = (c.a[i][j] + (1ll * a.a[i][4] * b.a[4][j])) % MOD;
		}
	}
	return c;
}
mat operator +(mat a,mat b){
	int i,j,k;
	for(int i = 1;i <= 4;++i){
		for(int j = 1;j <= 4;++j){
			a.a[i][j] = a.a[i][j] + b.a[i][j];
			if(a.a[i][j] > MOD)a.a[i][j] -= MOD;
		}
	}
	return a;
}
void write(int x){
     if(x>9)write(x/10);
     putchar(x%10+'0');
}
int read(){
    int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
    while(c >= '0' && c <= '9'){
    	x = x * 10 + c - '0';
		c = getchar();
	}
    return x*f;
}
struct tree{
	mat mt,lazy;
}t[MAXN*4+6];
void pushup(int p){
	t[p].mt = t[p*2].mt  + t[p*2+1].mt;
	return ;
}
void build(int l,int r,int p){
	t[p].mt.a[1][4] = r-l+1;
	t[p].lazy = mat1111;
	if(l == r){
		t[p].mt.a[1][1] = magic[l][0];
		t[p].mt.a[1][2] = magic[l][1];
		t[p].mt.a[1][3] = magic[l][2];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	pushup(p);
	return ;
}
void push_down(int p){
	t[p*2].mt = t[p*2].mt*t[p].lazy,t[p*2+1].mt = t[p*2+1].mt*t[p].lazy;
	t[p*2].lazy = t[p*2].lazy*t[p].lazy,t[p*2+1].lazy = t[p*2+1].lazy*t[p].lazy;
	t[p].lazy = mat1111;
	return ;
}
void printMT(mat a){
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			cout<<a.a[i][j]<<' ';
		}
		cout<<endl;
	}
	return ;
}
void update(int l,int r,int objl,int objr,mat v,int p){
	if(objl <= l && r <= objr){
		t[p].mt = t[p].mt*v;
		t[p].lazy = t[p].lazy*v;
		return ;
	}
	push_down(p);
	int mid = (l+r) >> 1;
	if(mid >= objl)update(l,mid,objl,objr,v,p*2);
	if(mid < objr)update(mid+1,r,objl,objr,v,p*2+1);
	pushup(p);
	return ; 
}
mat query(int l,int r,int objl,int objr,int p){
	mat ret = mat0;
	if(objl <= l && r <= objr){
		return t[p].mt;
	}
	push_down(p);
	int mid = (l+r) >> 1;
	if(mid >= objl)ret = ret + query(l,mid,objl,objr,p*2);
	if(mid < objr)ret = ret + query(mid+1,r,objl,objr,p*2+1);
	return ret; 
}
signed main(){
	//freopen("qmhwdnmd.in","r",stdin);
	//freopen("qmhwdnmd.out","w",stdout);
	n = read();
	for(int i = 1;i <= 6;i++){
		for(int j = 1;j <= 4;j++)op[i].a[j][j] = 1;
	}
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			mat1.a[i][j] = 1;
		}
	}
	for(int i = 1;i <= 4;i++){
		mat1111.a[i][i] = 1;
	}
	op[1].a[2][1] = 1;
	op[2].a[3][2] = 1;
	op[3].a[1][3] = 1;
	op[6].a[3][3] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 3;j++)magic[i][j] = read();
	}
	build(1,n,1);
	m = read();
	while(m--){
		int opt = read(),l = read(),r = read(),v;
		if(opt == 1){
			update(1,n,l,r,op[1],1);
		}else if(opt == 2){
			update(1,n,l,r,op[2],1);
		}else if(opt == 3){
			update(1,n,l,r,op[3],1);
		}else if(opt == 4){
			v = read();
			op[4].a[4][1] = v;
			update(1,n,l,r,op[4],1);
		}else if(opt == 5){
			v = read();
			op[5].a[2][2] = v;
			update(1,n,l,r,op[5],1);
		}else if(opt == 6){
			v = read();
			op[6].a[4][3] = v;
			update(1,n,l,r,op[6],1);
		}else if(opt == 7){
			mat output = query(1,n,l,r,1);
			write(output.a[1][1]),putchar(' ');
			write(output.a[1][2]),putchar(' ');
			write(output.a[1][3]),putchar('\n');
		}
	}
	return 0;
}
