#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 2;
string str;
int u,pos,n,dir[255];
char ch,nxt[14];
struct Matrix{
	ll c[9][9];
	ll* operator[](int x){
		return c[x];
	}
	const ll* operator[](int x)const {
		return c[x];
	}
	Matrix(){memset(c,0,sizeof(c));}
	Matrix(int val){
		memset(c,0,sizeof(c));
		for(int i = 0;i <= 8;i++){
			c[i][i] = val;
		}
		return ;
	}
};
Matrix operator*(const Matrix& mtx1,const Matrix& mtx2){
	Matrix ret;
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			for(int k = 0;k < 9;k++){
				ret[i][j] += mtx1[i][k] * mtx2[k][j];
			}
		}
	}
	return ret;
}
inline Matrix MakeOPT(char ch){//1~6 f_1~6 7 ans答案(delta) 8 数字1 9总答案(ans)   9调整为0,为了卡大小 
	Matrix ret;
	for(int i = 0;i < 9;i++)ret[i][i] = 1;//默认要把信息继承下去
	ret[8][1] = 1;//新增一个入口 
	ret[7][0] = 1;//delta答案对总答案的贡献 
	for(int i = 1;i <= 6;i++){
		if(ch == nxt[i]){
			if(i == 6){
				ret[i][1] = ret[i][7] = 1;//对f_1 的贡献 和 对delta答案的贡献
				ret[i][0] = 1;//记得对delta答案产生贡献也会对总答案产生贡献
				//并且因为转移顺序的问题没有转移到,所以要额外单独对总答案贡献 
			}else{
				ret[i][i+1] = 1;
				if(i == 1){//因为要先转移 f_1++; 
					ret[8][1] = 0;
					ret[8][2] = 1;//转移到f_2 
				}
			}
			ret[i][i] = 0;//清空自己对自己的贡献(转移了) 
		}
	}
	return ret;
}
template<int SIZE>
class SegmentTree{
	private:
		Matrix val[SIZE * 4];
		inline void PushUp(int p){
			val[p] = val[p*2] * val[p*2+1];
			return ;
		}
		void Change(int p,int l,int r,int OBJ,const Matrix& mtx){
			if(l == r){
				val[p] = mtx;
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,mtx);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,mtx);
			PushUp(p);
			return ;
		}
	public:
		inline void Change(int pos,const Matrix& mtx){
			Change(1,1,n,pos,mtx);
			return ;
		}
		inline Matrix Query(){
			return val[1];
		}
};
SegmentTree<MAXN> tr;
inline ll Solve(){
	Matrix ans;
	ans[1][8] = 1;//设置 1 为 1 
	ans = ans * tr.Query();
	return ans[1][0];
}
Matrix save[7];//预处理Matrix 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	nxt[1] = 'b',nxt[2] = 'e',nxt[3] = 's',nxt[4] = 's',nxt[5] = 'i',nxt[6] = 'e';
	save[1] = MakeOPT('b'),save[2] = MakeOPT('e'),save[3] = MakeOPT('s'),save[4] = MakeOPT('i'),save[0] = MakeOPT('q');
	dir['b'] = 1,dir['e'] = 2,dir['s'] = 3,dir['i'] = 4;
	cin>>str;
	n = str.length();
	str = "." + str;
	cin>>u;
	for(int i = 1;i <= n;i++){
		tr.Change(i,save[dir[str[i]]]);
	}
	cout<<Solve()<<endl;
	for(int i = 1;i <= u;i++){
		cin>>pos>>ch;
		tr.Change(pos,save[dir[ch]]);
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
