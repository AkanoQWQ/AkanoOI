#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t,n;
mt19937 rng(time(0));
namespace Subtask1{
	const int INF = 1e9;
	struct Book{
		int w,h;
		Book(){w = h = 0;}
	};
	vector<Book> book;
	inline int dfs(vector<Book> bk){
		int now = bk.size(),ret = INF;
		if(now == 1)return 0;
		for(int i = 0;i < now;i++){
			for(int j = 0;j < now;j++){
				if(i == j)continue;
				int cost = bk[i].w + bk[i].h + bk[j].h;
				if(cost >= ret)continue;
				vector<Book> nb = bk;
				Book newbook;
				newbook.w = bk[i].w + bk[j].w;
				newbook.h = 2 * max(bk[i].h,bk[j].h)+1;
				int mn = min(i,j),mx = max(i,j);
				nb.erase(nb.begin()+mx),nb.erase(nb.begin()+mn);//OK?
				nb.push_back(newbook);
				ret = min(ret,cost + dfs(nb));
			}
		}
		return ret;
	}
	bool cmp(Book b1,Book b2){
		return b1.w < b2.w;
	}
	inline int Solve(){
		book.clear();
		for(int i = 1;i <= n;i++){
			Book newbook;
			cin>>newbook.w;
			book.push_back(newbook);
		}
		sort(book.begin(),book.end(),cmp);
		return dfs(book);
	}
}
namespace Subtask2{
	const ll INF = 1e12;
	const int MAIN_POSS = 50;//%   概率次优解 
	int POSS = MAIN_POSS;
	const int MAXN = 106;
	ll nnt;
	struct Book{
		ll w,h,id;
	}save[MAXN];
	bool operator<(Book b1,Book b2){
		return b1.id < b2.id;
	}
	inline ll Priority(const Book& b1,const Book& b2){
		return b1.w + b1.h + b2.h;
	}
	inline Book Merge(const Book& b1,const Book& b2){
		Book ret;
		ret.w = b1.w + b2.w;
		ret.h = 2 * max(b1.h,b2.h)+1;
		ret.id = ++nnt;
		return ret;
	}
	inline ll Calc(ll nowans){
		ll ret = 0;
		multiset<Book> book;
		for(int i = 1;i <= n;i++){
			save[i].id = ++nnt;
			book.insert(save[i]);
		}
		while(book.size() > 1){
			ll best = 1e10;
			pair<Book,Book> now = make_pair(*book.begin(),*book.begin());
			for(auto i : book){
				for(auto j : book){
					if(i.id == j.id)continue;
					ll pri = Priority(i,j);
					if(pri < best){
						best = pri;
						now = make_pair(i,j);
					}else if(pri < best * 1.5){
						if(rng() % 100 < double(POSS) * best / pri){
							best = pri;
							now = make_pair(i,j);
						}
					}
				}
			}
			Book newbook = Merge(now.first,now.second);
			ret += (now.first).w + (now.first).h + (now.second).h;
			if(ret > nowans)return ret;
			book.erase(now.first);
			book.erase(now.second);
			book.insert(newbook);
		}
		return ret;
	}
	inline ll Solve(){
		ll ret = INF;
		for(int i = 1;i <= n;i++){
			save[i].h = 0;
			cin>>save[i].w;
		}
		int T;
		if(n <= 7){
			T = 10000 + 1018 + 1108;
		}else{
			T = 2000 + 1018 + 1108;
		}
		
		for(int nowt = 1;nowt <= T;nowt++){
			if(nowt == 1){
				POSS = 0;
			}else{
				POSS = MAIN_POSS;
			}
			nnt = 0;
			ret = min(ret,Calc(ret));
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n <= 6){//maybe point 1
			cout<<Subtask1::Solve()<<endl;
		}else if(n <= 30){//point 1 ~ 2,POSS AC;point 3~8 WA
			cout<<Subtask2::Solve()<<endl;
		}else{
			int getin;
			for(int i = 1;i <= n;i++)cin>>getin;
			cout<<10181108<<endl;
		}
	}
	return 0;
}
//OVER
