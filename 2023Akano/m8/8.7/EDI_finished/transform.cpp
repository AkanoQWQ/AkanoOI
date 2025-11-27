#include<bits/stdc++.h>
using namespace std;
using pdd = pair<double,double>;
const double pi = 3.14159265358979323846;
const double EPS = 1e-10;
const int MAXN = 106;
struct Matrix{
	double c[8][8];//size = 7 a,b,c,A,B,C,1
	inline void Set1(){
		for(int i = 1;i <= 7;i++)c[i][i] = 1;
		return ;
	}
	Matrix(){memset(c,0,sizeof(c));}
};
Matrix operator*(Matrix m1,Matrix m2){
	Matrix ret;
	for(int i = 1;i <= 7;i++){
		for(int j = 1;j <= 7;j++){
			for(int k = 1;k <= 7;k++){
				ret.c[i][j] += m1.c[i][k] * m2.c[k][j];
			}
		}
	}
	return ret;
}
inline Matrix KSM(Matrix a,int b){
	Matrix ret;
	ret.Set1();
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
int n;
pdd p[MAXN];
stack<pair<int,Matrix> > stk;
char opt;
inline Matrix GetOPT(double sn,double co,double _x0,double _y0){
	if(fabs(sn) <= EPS)sn = 0;
	if(fabs(co) <= EPS)co = 0;
	Matrix ret;
	ret.c[1][1] = co;
	ret.c[4][1] = sn;
	ret.c[2][2] = co;
	ret.c[5][2] = sn;
	ret.c[3][3] = co;
	ret.c[6][3] = sn;
	ret.c[7][3] = - (co * _x0) - (sn * _y0) + _x0;
	
	ret.c[4][4] = co;
	ret.c[1][4] = -sn;
	ret.c[5][5] = co;
	ret.c[2][5] = -sn;
	ret.c[6][6] = co;
	ret.c[3][6] = -sn;
	ret.c[7][6] = - (co * _y0) + (sn * _x0) + _y0;
	
	ret.c[7][7] = 1;
	
	return ret;
}
int main(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lf %lf",&p[i].first,&p[i].second);
	}
	pair<int,Matrix> mainstk;
	mainstk.first = 1,mainstk.second.Set1();
	stk.push(mainstk);
	while(scanf("%c",&opt) != EOF){
		if(opt == 'T'){//OK
			double dx,dy;
			scanf("rans(%lf,%lf)",&dx,&dy);
			Matrix optm;
			optm.Set1();
			optm.c[7][3] = dx;
			optm.c[7][6] = dy;
			stk.top().second = stk.top().second * optm;
		}else if(opt == 'L'){//OK
			int nowdep;
			scanf("oop(%d)",&nowdep);
			pair<int,Matrix> tp;
			tp.first = nowdep,tp.second.Set1();
			stk.push(tp);
		}else if(opt == 'S'){//OK
			double dx,dy;
			scanf("cale(%lf,%lf)",&dx,&dy);
			Matrix optm;
			for(int i = 1;i <= 3;i++)optm.c[i][i] = dx;
			for(int i = 4;i <= 6;i++)optm.c[i][i] = dy;
			optm.c[7][7] = 1;
			stk.top().second = stk.top().second * optm;
		}else if(opt == 'R'){//OK
			double theta,dx,dy;
			scanf("otate(%lf,%lf,%lf)",&theta,&dx,&dy);
			double omg = theta / 180 * pi;
			double sn = sin(omg),co = cos(omg);
			Matrix optm = GetOPT(sn,co,dx,dy);
			stk.top().second = stk.top().second * optm;
		}else if(opt == 'E'){//OK
			scanf("nd");
			Matrix nowtp = stk.top().second;
			nowtp = KSM(nowtp,stk.top().first);
			stk.pop();
			stk.top().second = stk.top().second * nowtp;
		}
	}
	Matrix def;
	def.Set1();
	def.c[1][1] = def.c[1][5] = def.c[1][7] = 1;
	Matrix mainOPT = def * stk.top().second;
	for(int i = 1;i <= n;i++){
		const double nowx = p[i].first * mainOPT.c[1][1] + p[i].second * mainOPT.c[1][2] + mainOPT.c[1][3];
		const double nowy = p[i].first * mainOPT.c[1][4] + p[i].second * mainOPT.c[1][5] + mainOPT.c[1][6];
		printf("%.4lf %.4lf\n",nowx,nowy);
	}
	return 0;
}
