#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
const int MAXK = 1e5 + 6;
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
struct Item{
	int a,b,c;
	Item(){}
	Item(int _a,int _b,int _c){a = _a,b = _b,c = _c;}
};
struct Query{
	int m,k,s,no;
	Query(){}
	Query(int _m,int _k,int _s,int _no){m = _m,k = _k,s = _s,no = _no;}
};
vector<Item> items;
vector<Query> querys;
bool Cmp4Item(Item ia,Item ib){
	return ia.a > ib.a;
}
bool Cmp4Query(Query qa,Query qb){
	return qa.m < qb.m;
}
int f[MAXK],n,q;
inline void AddItem(const Item& itm){
	for(int i = MAXK - itm.c - 1;i >= 0;i--){
		f[i+itm.c] = max(f[i+itm.c],min(f[i],itm.b));
	}
	return ;
}
const int MAXQ = 1e6 + 6;
bool OK[MAXQ];
int main(){
	freopen("P3537.in","r",stdin);
	n = Read();
	for(int i = 1;i <= n;i++){
		int _c = Read(),_a = Read(),_b = Read();
		items.push_back(Item(_a,_b,_c));
	}
	q = Read();
	for(int i = 1;i <= q;i++){
		int _m = Read(),_k = Read(),_s = Read();
		querys.push_back(Query(_m,_k,_s,i));
	}
	sort(items.begin(),items.end(),Cmp4Item);
	sort(querys.begin(),querys.end(),Cmp4Query);
	memset(f,128,sizeof(f));f[0] = 0x7fffffff;
	for(auto& query : querys){
		while(items.size() > 0 && items[items.size()-1].a <= query.m){
			AddItem(items[items.size()-1]);
			items.pop_back();
		}
		if(f[query.k] > query.m + query.s){
			OK[query.no] = true;
		}
	}
	for(int i = 1;i <= q;i++){
		if(OK[i]){
			puts("TAK");
		}else{
			puts("NIE");
		}
	}
	return 0;
}
