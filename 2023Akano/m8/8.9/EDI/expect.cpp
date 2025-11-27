#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int MAXSTAT = 1<<MAXN;
const int MAXSTAT2 = 1<<(MAXN / 2);
inline int Lowbit(int x){
	return x & (-x);
}
int n,n2,pre,lst;
unordered_map<int,int> dir;
double poss[MAXN][MAXN],ans,f[MAXSTAT],p[MAXSTAT2][MAXSTAT2],d[MAXSTAT2][MAXSTAT2],l[MAXSTAT2][MAXSTAT2],r[MAXSTAT2][MAXSTAT2];
vector<int> Trans(int stat){
	vector<int> ret;
	for(int i = 1;i <= n;i++){
		if(stat & (1<<(i-1))){
			ret.push_back(i);
		}
	}
	return ret;
}
inline double Split(int s,int t){
	double ret = 1;	
	int s1 = s % (pre+1);
	int s2 = s >> n2;
	int t1 = t % (pre+1);
	int t2 = t >> n2;
	ret *= p[s1][t2];
//	cout<<s1<<" and "<<t2<<"("<<(t2<<n2)<<") p "<<p[s1][t2]<<endl;
	ret *= p[t1][s2];
//	cout<<t1<<" and "<<s2<<"("<<(s2<<n2)<<") p "<<p[t1][s2]<<endl;
	ret *= l[s1][t1];
//	cout<<s1<<" and "<<t1<<" l "<<l[s1][t1]<<endl;
	ret *= r[s2][t2];
//	cout<<s2<<" and "<<t2<<" r "<<r[s2][t2]<<" ("<<(s2<<n2)<<") and ("<<(t2<<n2)<<")"<<endl;
//	cout<<"finally "<<s<<" and "<<t<<" split "<<ret<<endl;
	return ret;
}
inline double Calc(int stat){
	double ret = 1;
	int imp = Lowbit(stat);
	for(int i = (stat - 1) & stat;i > 0;i = (i-1) & stat){
		int s = i,t = stat ^ i;
		if(!(s & imp))continue;
		ret -= Split(s,t) * f[s];
	}
	return ret;
}
inline void Pre(){
	for(int s = 0;s <= pre;s++){
		for(int t = 0;t <= lst;t++){
			int realt = t << n2;
			p[s][t] = 1;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if((s & (1<<(i-1))) && (realt & (1<<(j-1)))){
						p[s][t] *= 1 - poss[i][j];
					}
				}
			}
		}
	}
	for(int s1 = 0;s1 <= pre;s1++){
		for(int s2 = 0;s2 <= pre;s2++){
			l[s1][s2] = 1;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if((s1 & (1<<(i-1))) && (s2 & (1<<(j-1)))){
						l[s1][s2] *= 1 - poss[i][j];
					}
				}
			}
		}
	}
	for(int t1 = 0;t1 <= lst;t1++){
		for(int t2 = 0;t2 <= lst;t2++){
			int rt1 = t1 << n2;
			int rt2 = t2 << n2;
			r[t1][t2] = 1;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if((rt1 & (1<<(i-1))) && (rt2 & (1<<(j-1)))){
						r[t1][t2] *= 1 - poss[i][j];
					}
				}
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("expect.in","r",stdin);
//	freopen("expect.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>poss[i][j];
		}
		f[1<<(i-1)] = 1;
		dir[1<<(i-1)] = i;
	}
	const int MAXS = (1<<n) - 1;
	n2 = n / 2;
	pre = (1<<n2) - 1;
	lst = MAXS >> n2;
	Pre();
	for(int stat = 1;stat <= MAXS;stat++){
		int s = stat,t = MAXS ^ stat;
		f[stat] = Calc(s);
		double g = 0;
		g = Split(s,t);
		ans += f[stat] * g * 1;
	}
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
