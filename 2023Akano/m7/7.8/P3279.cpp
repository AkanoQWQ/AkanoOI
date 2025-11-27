#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int MAXN = 1e5 + 6;
const int MAXE = 1006;
char cnt = 'a';
int n,in[MAXN],out[MAXN];
int fa[MAXN],lef[MAXN];
char otp[MAXN];
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
}
inline void Merge(int x,int y){
	x = GetFa(x),y = GetFa(y);
	const int _left = min(lef[x],lef[y]);
	fa[y] = x,lef[x] = lef[y] = _left;
	return ;
}
vector<pair<int,int> > vec,sets;
vector<int> edge[MAXN];
int mirror[MAXN];
int NOTOK[27],choice[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)fa[i] = i,lef[i] = i;
	for(int i = 1;i <= n;i++){
		cin>>in[i];
		for(int j = 1;;j++){
			const int l = i - j + 1,r = i + j - 1;
			if(2 * j - 1 > in[i]){
				if(l <= 0 || r > n)break;
				vec.push_back(make_pair(l,r));
				break;
			}
			Merge(l,r);
		}
	}
	for(int i = 1;i < n;i++){
		cin>>out[i];
		for(int j = 1;;j++){
			const int l = i - j + 1,r = i + j;
			if(2 * j > out[i]){
				if(l <= 0 || r > n)break;
				vec.push_back(make_pair(l,r));
				break;
			}
			Merge(l,r);
		}
	}
	for(int i = 1;i <= n;i++){
		if(GetFa(i) == i)sets.push_back(make_pair(lef[i],i));
	}
	sort(sets.begin(),sets.end());
	for(int i = 0;i < sets.size();i++){
		mirror[sets[i].second] = i;
	}
	for(auto i : vec){
		int x = mirror[GetFa(i.first)],y = mirror[GetFa(i.second)];
		if(x > y)swap(x,y);//x < y
		edge[y].push_back(x);
	}
	for(int i = 0;i < 26;i++)NOTOK[i] = -1;
	for(int i = 0;i < sets.size();i++){
		for(auto j : edge[i]){
			NOTOK[choice[j]] = i;
		}
		for(int j = 0;j < 26;j++){
			if(NOTOK[j] != i){
				choice[i] = j;
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		const int kol = choice[mirror[GetFa(i)]];
		cout<<char('a' + kol);
	}
	return 0;
}
