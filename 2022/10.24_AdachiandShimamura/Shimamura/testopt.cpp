#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
struct Lysarfa{
	int org,to;
}lsf[MAXN*2];
int needed;
int n,m1,m2;
struct plane{
	int a,b;
}p1[MAXN],p2[MAXN];
bool cmp4plane(plane a,plane b){
	return a.a < b.a;
}
struct node{
	int v,no;
	operator <(const node a)const{
		if(this->v != a.v)return this->v > a.v;
		return this->no > a.no;
	}
};
priority_queue<node> wating;
priority_queue<int> poss;
int s1[MAXN],s2[MAXN];
int main(){
	node a,b,c;
	a.v = 13,b.v = 156,c.v = 1;
	a.no = 1,b.no = 2,c.no = 3;
	wating.push(a);
	wating.push(b);
	wating.push(c);
	cout<<wating.top().no;
	return 0;
}

