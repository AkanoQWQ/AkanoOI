#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
const ull base = 101811082121;
const ull ST = 1e9 + 7;

template<typename Val>
struct HashSetNode{
	Val val;
	int nxt;//索引范围int,也许需要使用更规范的类型
	HashSetNode(){val = Val(),nxt = 0;}
	HashSetNode(Val _val){val = _val,nxt = 0;}
};
template<typename Val,typename HashClass,int SIZE>
class HashSet{
	typedef HashSetNode<Val> Node;
private:
	HashClass hasher = HashClass();
	int head[SIZE],tot;
	vector<Node> content;
	inline int FindIndex(const Val& val){
		const int hashVal = hasher(val) % SIZE;
		for(int i = head[hashVal];i;i = content[i].nxt){
			if(content[i].val == val)return i;
		}
		return 0;
	}
	inline int InsertContent(const Val& val){
		const int hashVal = hasher(val) % SIZE;
		int lst = head[hashVal];
		head[hashVal] = ++tot;
		content.emplace_back(val);
		content[tot].nxt = lst;
		return tot;
	}
public:
	inline bool Insert(const Val& val){
		int idx = FindIndex(val);
		if(idx)return false;
		InsertContent(val);
		return true;
	}
	inline bool Find(const Val& val){
		int idx = FindIndex(val);
		return (idx != 0);
	}
	HashSet(){//初始一个空元素,下标为0,非常重要 
		content.emplace_back();
		return ;
	}
	HashSet(int initVal){//初始一个空元素,下标为0,非常重要 
		content.reserve(initVal);
		content.emplace_back();
		return ;
	}
};
int value[66];
struct Hasher{
	inline int Trans(char ch){
		if('a' <= ch && ch <= 'z')return ch - 'a';
		if('A' <= ch && ch <= 'Z')return ch - 'A' + 26;
		return ch - '0' + 52;
	}
	ull operator()(const string& str){
		ull ret = ST;
		for(auto i : str){
			ret = ret * base + value[Trans(i)];
		}
		return ret;
	}
};
const int SIZEE = 1e6;
HashSet<string,Hasher,SIZEE> st;
mt19937_64 rng(time(0));
int n,ans;
vector<ull> hashs;
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 0;i <= 64;i++){
		value[i] = rng();
	}
	cin>>n;
	while(n--){
		cin>>str;
		ans += st.Insert(str);
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
