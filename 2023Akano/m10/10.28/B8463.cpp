#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const int INF = 1e9 + 1018 + 1108;

class FastIO{
private:
	const static int buffSize = 1<<23;
	using charp = char*;
	using ccp = const char*;
	using FILEp = FILE*;
	typedef ostream& (*ostreamFunc)(ostream&);
	FILEp inFile,outFile;
	char inputBuff[buffSize +2],outputBuff[buffSize + 2];
	charp inputPtr = inputBuff,inputEnd = inputPtr;
	charp outputPtr = outputBuff,outputEnd = outputBuff + buffSize;
	inline bool IsSplited(char ch){
		return (ch == ' ' || ch == '\n');
	}
	template <typename T>
	void ReadInt(T &x){
		x = 0;
		char ch = FastGetChar();
		int f = 1;
		while(!isdigit(ch) && !fail){
			if(ch == '-')f = -1;
			ch = FastGetChar();
		}
		while(isdigit(ch)  && !fail){
			x = (x * 10) + (ch ^ 48);
			ch = FastGetChar();
		}
		x *= f;
		return ;
	}
	template <typename T>
	void WriteInt(T x){
		static int writeBuff[128];
		if(x < 0){
			FastPutChar('-');
			x = -x;
		}else if(x==0){
			FastPutChar('0');
		}
		int tail = 0;
		while(x){
			writeBuff[++tail] = x % 10;
			x /= 10;
		}
		while(tail){
			FastPutChar(writeBuff[tail--] + '0');
		}
		return ;
	}
	inline void ReadString(string& str){
		str = "";
		char ch = FastGetChar();
		while(!IsSplited(ch) && !fail){
			str += ch;
			ch = FastGetChar();
		}
		return ;
	}
	inline void WriteString(const string& str){
		for(auto i : str){
			FastPutChar(i);
		}
		return ;
	}
	inline void FmtOutput(ccp format){
		for(;*format;format++){
			FastPutChar(*format);
		}
		return ;
	}
	template<typename FirstType,typename... ResType>
	inline void FmtOutput(ccp format,const FirstType& firstElement,const ResType&... res){
		for(;*format;format++){
			if(*format == '{' && *(format+1) == '}'){
				operator<<(firstElement);
				FmtOutput(format + 2,res...);
				return ;
			}
			FastPutChar(*format);
		}
		return ;
	}
	template<typename T>
	inline void ReadFloat(T& ret){
		ret = 0;
		int f = 1;
		char ch = FastGetChar();
		while(!isdigit(ch)){
			if(ch == '-')f = -1;
			ch = FastGetChar();
		}
		bool afterPoint = false;
		T now = 1;
		while(isdigit(ch) || ch == '.'){
			if(ch == '.'){
				afterPoint = true;
			}else if(afterPoint == false){
				ret = ret * 10 + ch - '0';
			}else{
				now /= 10;
				ret += now * (ch - '0');
			}
			ch = FastGetChar();
		}
		ret *= f;
		return ;
	}
	template<typename T>
	inline void WriteFloat(T x){
		const static double EPS = 1e-8;
		if(fabs(x) <= EPS){
			FastPutChar('0');
			return ;
		}else if(x < 0){
			FastPutChar('-');
			x = -x;
		}
		T noww = 1;
		while(noww * 10 <= x)noww *= 10;
		while(noww >= 1){
			int cnt = x / noww;
			x -= cnt * noww;
			FastPutChar('0' + cnt);
			noww /= 10;
		}
		if(fabs(x) <= EPS)return ;
		FastPutChar('.');
		T nowEPS = EPS;
		while(fabs(x) > nowEPS){
			x *= 10;
			int res = int(x);
			x -= res % 10;
			nowEPS *= 10;
			FastPutChar('0' + res);
		}
		return ;
	}
public:
	bool fail;
	inline char FastGetChar(){
		if(inputPtr == inputEnd){
			size_t res = fread(inputBuff,1,buffSize,inFile);
			inputEnd = inputBuff + res;//为什么其他地方不改inputEnd呢
			if(res == 0){
				fail = true;
				inputPtr = inputBuff;
				return EOF;
			}
			inputPtr = inputBuff;
		}
		return *(inputPtr++);
	}
	inline void FastPutChar(char ch){
		if(outputPtr == outputEnd){
			Flush();
		}
		*(outputPtr++) = ch;
		return ;
	}
	inline void Flush(){
		fwrite(outputBuff,1,outputPtr - outputBuff,outFile);
		outputPtr = outputBuff;
		return ;
	}
	inline void Endl(){
		FastPutChar('\n');
		return ;
	}
	FastIO& operator>>(short& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(int& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(long& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(long long& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(__int128& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(float& floatVar){
		ReadFloat(floatVar);
		return *this;
	}
	FastIO& operator>>(double& floatVar){
		ReadFloat(floatVar);
		return *this;
	}
	FastIO& operator>>(string& stringVar){
		ReadString(stringVar);
		return *this;
	}
	FastIO& operator>>(char& charVar){
		charVar = FastGetChar();
		while(IsSplited(charVar))charVar = FastGetChar();
		return *this;
	}
	FastIO& operator<<(short integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(int integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(long integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(long long integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(__int128 integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(string stringVar){
		WriteString(stringVar);
		return *this;
	}
	FastIO& operator<<(char charVar){
		FastPutChar(charVar);
		return *this;
	}
	FastIO& operator<<(float floatVar){
		WriteFloat(floatVar);
		return *this;
	}
	FastIO& operator<<(double floatVar){
		WriteFloat(floatVar);
		return *this;
	}
	FastIO& operator<<(ostreamFunc func){
		ostringstream oss;
		oss<<func;
		string str = oss.str();
		for(auto i : str){
			FastPutChar(i);
		}
		Flush();
		return *this;
	}
	template<typename... ArgTypes>
	FastIO& operator()(ccp format,const ArgTypes&... args){
		FmtOutput(format,args...);
		return *this;
	}
	operator bool(){
		return not(fail);
	}
	FastIO(){
		inFile = stdin,outFile = stdout;
		return ;
	}
	FastIO(FILEp _inFile,FILEp _outFile){
		inFile = _inFile,outFile = _outFile;
		return ;
	}
	~FastIO(){
		Flush();
		return ;
	}
};
FastIO fio(stdin,stdout),ferr(nullptr,stderr);

ll n,k,a[MAXN],q;
ll farL[MAXN],farR[MAXN],f[MAXN];
ll F(int x){
	if(f[x] != -2)return f[x];
	if(a[farL[x]] < a[farR[x]]){
		f[x] = F(farL[x]) + 1;
	}else if(a[farL[x]] > a[farR[x]]){
		f[x] = F(farR[x]) + 1;
	}else{
		f[x] = F(farR[x]) + 1;
	}
	return f[x];
}
inline void Solve(){
	a[0] = a[n+1] = INF;
	stack<int> stk;
	for(int i = 1;i <= n;i++){
		while(!stk.empty() && a[stk.top()] < a[i]){
			farR[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		farR[stk.top()] = n + 1;
		stk.pop();
	}
	for(int i = n;i >= 1;i--){
		while(!stk.empty() && a[stk.top()] < a[i]){
			farL[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		farL[stk.top()] = 0;
		stk.pop();
	}
	for(int i = 1;i <= n;i++){
		f[i] = -2;
	}
	f[0] = f[n+1] = -1;
	return ;
}

template<int SIZE,typename T = int>
class SegmentTree{
private:
	struct SegmentTreeNode{
		T val,lazy;
		int len;
		SegmentTreeNode(){val = lazy = 0,len = 0;}
	};
	SegmentTreeNode node[(SIZE + 4) * 4];
	int OBJL,OBJR,_val;
	T* arr;
	inline void PushUp(int p){
		node[p].val = node[p*2].val + node[p*2+1].val;
		return ;
	}
	inline void PushDown(int p){
		if(node[p].lazy == 0)return ;
		node[p*2].val += node[p*2].len * node[p].lazy;
		node[p*2+1].val += node[p*2+1].len * node[p].lazy;
		node[p*2].lazy += node[p].lazy,node[p*2+1].lazy += node[p].lazy;
		node[p].lazy = 0;
		return ;
	}
	void Build(int p,int l,int r){
		node[p].len = r - l + 1;
		if(l == r){
			if(arr != nullptr){
				node[p].val = arr[l];
			}
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r); 
		PushUp(p);
		
		return ;
	}
	void ChangeInner(int p,int l,int r){
		if(OBJL <= l && r <= OBJR){
			node[p].val += _val * node[p].len;
			node[p].lazy += _val;
			return ;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)ChangeInner(p*2,l,mid);
		if(mid < OBJR)ChangeInner(p*2+1,mid+1,r);
		PushUp(p);
		return ;
	}
	T Query(int p,int l,int r){
		if(OBJL <= l && r <= OBJR){
			return node[p].val;
		}
		const int mid = (l + r) >> 1;
		T ret = 0;
		PushDown(p);
		if(mid >= OBJL)ret = Query(p*2,l,mid);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r);
		return ret;
	}
	class Reference{
	private:
		friend class SegmentTree;
		SegmentTree* source;
		size_t l,r;
		Reference() = default;
		Reference(SegmentTree* _source,int _l,int _r){
			source = _source,l = _l,r = _r;
			return ;
		}
	public:
		operator T(){
			return source->Query(l,r);
		}
		Reference& operator+=(int x){
			source->Change(l,r,x);
			return *this;
		}
		Reference& operator-=(int x){
			source->Change(l,r,-x);
			return *this;
		}
	};
public:
	inline void Build(){
		Build(1,1,SIZE);
		return ;
	}
	inline void Build(T* _arr){
		arr = _arr;
		Build(1,1,SIZE);
		arr = nullptr;
		return ;
	}
	inline void Change(int l,int r,int inval){
		if(l > r)return ;
		OBJL = l,OBJR = r,_val = inval;
		ChangeInner(1,1,SIZE);
		return ;
	}
	inline T Query(int l,int r){
		OBJL = l,OBJR = r;
		return Query(1,1,SIZE);
	}
	SegmentTree(){
		Build();
		return ;
	}
	SegmentTree(T* _arr){
		Build(_arr);
		return ;
	}
	inline Reference operator[](pair<int,int> lr){
		return Reference(this,lr.first,lr.second);
	}
	inline Reference operator()(int l,int r){
		return Reference(this,l,r);
	}
};
SegmentTree<MAXN,ll> vtr;
class ArraySegmentTree{
private:
	int maxa[MAXN * 4];
	inline void PushUp(int p){
		maxa[p] = max(maxa[p*2],maxa[p*2+1]);
		return ;
	}
	void Build(int p,int l,int r){
		if(l == r){
			maxa[p] = a[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		PushUp(p);
		return ;
	}
	void Change(int p,int l,int r,int OBJ,int _val){
		if(l == r){
			maxa[p] = _val;
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
		if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
		PushUp(p);
		return ;
	}
	int QueryPre(int p,int l,int r,int pos,int _val){
		if(l == r){
			if(maxa[p] >= _val)return l;
			return l - 1;
		}
		if(maxa[p] < _val)return l - 1;
		const int mid = (l + r) >> 1;
		if(mid < pos){
			int ret = QueryPre(p*2+1,mid+1,r,pos,_val);
			if(ret <= mid)ret = QueryPre(p*2,l,mid,pos,_val);
			return ret;
		}else{
			return QueryPre(p*2,l,mid,pos,_val);
		}
		return 10181108;
	}
	int QueryNxt(int p,int l,int r,int pos,int _val){
		if(l == r){
			if(maxa[p] >= _val)return l;
			return r + 1;
		}
		if(maxa[p] < _val)return r + 1;
		const int mid = (l + r) >> 1;
		if(mid >= pos){
			int ret = QueryNxt(p*2,l,mid,pos,_val);
			if(ret >= mid+1)ret = QueryNxt(p*2+1,mid+1,r,pos,_val);
			return ret;
		}else{
			return QueryNxt(p*2+1,mid+1,r,pos,_val);
		}
		return 10181108;
	}
public:
	inline void Build(){
		Build(1,1,n);
		return ;
	}
	inline void Change(int pos,int _val){
		Change(1,1,n,pos,_val);
		return ;
	}
	inline int QueryPre(int pos,int _val){
		return QueryPre(1,1,n,pos,_val);
	}
	inline int QueryNxt(int pos,int _val){
		return QueryNxt(1,1,n,pos,_val);
	}
}atr;
ll ansarr[MAXN + 2],cnts;
int main(){
	fio>>n>>k;
	for(int i = 1;i <= n;i++)fio>>a[i];
	Solve();
	for(int i = 1;i <= n;i++)ansarr[i] = F(i);
	atr.Build();
	vtr.Build(ansarr);
	fio>>q;
	for(int nowq = 1;nowq <= q;nowq++){
		int x,l,r;
		fio>>x>>l>>r;
		f[x] = vtr[{x,x}],f[x+1] = vtr[{x+1,x+1}];
		if(a[x] < a[x+1]){
			if(x - 1 >= 1){
				int lpos = atr.QueryPre(x-1,a[x]);
				if(a[lpos] != a[x]){
					vtr[{lpos+1,x-1}] -= 1;
				}
			}
			if(x <= n-2){
				int rpos = atr.QueryNxt(x+2,a[x]);
				if(a[rpos] != a[x]){
					vtr[{x+2,rpos-1}] += 1;
				}
				if(a[rpos] >= a[x+1]){
					f[x] = f[x+1] + 1;
				}else{
					f[x] = vtr[{rpos,rpos}];
					if(a[rpos] != a[x])f[x]++;
				}
			}else{
				f[x] = f[x+1] + 1;
			}
		}else if(a[x] > a[x+1]){
			if(x <= n){
				int rpos = atr.QueryNxt(x+2,a[x+1]);
				if(a[rpos] != a[x+1]){
					vtr[{x+2,rpos-1}] -= 1;
				}
			}
			if(x >= 2){
				int lpos = atr.QueryPre(x-1,a[x+1]);
				if(a[lpos] != a[x+1]){
					vtr[{lpos+1,x-1}] += 1;
				}
				if(a[lpos] >= a[x]){
					f[x+1] = f[x] + 1;
				}else{
					f[x+1] = vtr[{lpos,lpos}];
					if(a[lpos] != a[x+1])f[x+1]++;
				}
			}else{
				f[x+1] = f[x] + 1;
			}
		}
		swap(a[x],a[x+1]),swap(f[x],f[x+1]);
		int deltaX = f[x] - vtr[{x,x}],deltaR = f[x+1] - vtr[{x+1,x+1}];
		vtr[{x,x}] += deltaX,vtr[{x+1,x+1}] += deltaR;
		atr.Change(x,a[x]),atr.Change(x+1,a[x+1]);
		fio<<vtr[{l,r}] * k + ll(r - l + 1) * (n -1)<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
