#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
constexpr int MAXN = 19;
constexpr int MAXSTAT = (1<<18) + 1018 + 1108;
constexpr int MAXM = MAXN * MAXN;
constexpr int INF = 1e9;

template<typename valueT>
class SetBasic{
private:
	valueT val;
public:
	inline bool Include(int _val){
#ifdef EXCONTAINER_SAFE
		assert(1 <= _val && _val <= numeric_limits<valueT>::digits);
#endif
		return (val & (valueT(1)<<(_val-1)));
	}
	inline bool Include(SetBasic oth){
		return ((val & oth.val) == oth.val);
	}
	inline bool In(SetBasic oth){
		return oth.Include(*this);
	}
	inline void Flip(int _val){
#ifdef EXCONTAINER_SAFE
		assert(1 <= _val && _val <= numeric_limits<valueT>::digits);
#endif
		val ^= (valueT(1)<<(_val-1));
		return ;
	}
	inline void Insert(int _val){
#ifdef EXCONTAINER_SAFE
		assert(1 <= _val && _val <= numeric_limits<valueT>::digits);
#endif
		val |= (valueT(1)<<(_val-1));
		return ;
	}
	inline void Erase(int _val){
#ifdef EXCONTAINER_SAFE
		assert(1 <= _val && _val <= numeric_limits<valueT>::digits);
#endif
		if(not(Include(_val)))return ;
		return Flip(_val);
	}
	operator valueT(){
		return val;
	}
	SetBasic& operator=(valueT _val){
		val = _val;
		return *this;
	}
	SetBasic& operator=(const char* str){
		val = 0;
		for(;*str;str++){
			val = (val << 1) + ((*str) - '0');
		}
		return *this;
	}
	SetBasic& operator=(const string& str){
		return operator=(str.c_str());
	}
	SetBasic& operator++(){
#ifdef EXCONTAINER_SAFE//有趣的是:uint128不会被识别为unsigned,亦不会报错
		if(is_unsigned<valueT>::value){
			assert(val != numeric_limits<valueT>::max());
		}
#endif
		val++;
		return *this;
	}
	SetBasic operator++(int){
		SetBasic ret = *this;
		operator++();
		return ret;
	}
	SetBasic& operator--(){
#ifdef EXCONTAINER_SAFE
		if(is_unsigned<valueT>::value){
			assert(val != 0);
		}
#endif
		val--;
		return *this;
	}
	SetBasic operator--(int){
		SetBasic ret = *this;
		operator--();
		return ret;
	}
	SetBasic(){
		val = 0;
		return ;
	}
	template<typename T>
	SetBasic(T _val){
		operator=(_val);
		return ;
	}
};
//Set32/Set64/Set128 可能导致无符号整形下溢,谨慎使用
using Set32 = SetBasic<unsigned int>;
using Set64 = SetBasic<unsigned long long>;
using Set128 = SetBasic<unsigned __int128>;
using Set31 = SetBasic<int>;
using Set63 = SetBasic<long long>;
using Set127 = SetBasic<__int128>;
using Set = Set31;

int T,n,m,C,cost[MAXM];
vector<pii> e[MAXM];
Set maxs,trans[MAXSTAT][MAXM];
pii f[MAXSTAT];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ifstream fin("game.in");
	ofstream fout("game.out");
	fin>>T;
	while(T--){
		fin>>n>>m>>C;
		for(int i = 1;i <= C;i++){
			fin>>cost[i];
			e[i].clear();
		}
		for(int i = 1,u,v,c;i <= m;i++){
			fin>>u>>v>>c;
			e[c].emplace_back(u,v);
		}
		maxs = (1<<n) - 1;
		for(Set i = 1;i <= maxs;i++){
			for(int j = 1;j <= C;j++){
				trans[i][j] = i;
				for(pii edge : e[j]){
					if(i.Include(edge.first)){
						trans[i][j].Insert(edge.second);
					}
					if(i.Include(edge.second)){
						trans[i][j].Insert(edge.first);
					}
				}
			}
			f[i] = {INF,INF};
		}
		f[1] = {0,0};
		for(Set stat = 1;stat <= maxs;stat++){
			for(int edge = 1;edge <= C;edge++){
				Set nxt = trans[stat][edge];
				f[nxt] = min(f[nxt],{f[stat].first+1,f[stat].second + cost[edge]});
			}
		}
		for(Set stat = maxs;stat >= 1;stat--){
			for(int i = 1;i <= n;i++){
				if(stat.Include(i)){
					Set nxt = stat;
					nxt.Erase(i);
					f[nxt] = min(f[nxt],f[stat]);
				}
			}
		}
		long long ans1 = 0,ans2 = 0;
		for(Set stat = 1;stat <= maxs;stat++){
			const int wcount = __builtin_popcount(stat);
			ans1 += wcount * f[stat].first;
			ans2 += wcount * f[stat].second;
		}
		fout<<ans1<<" "<<ans2<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
