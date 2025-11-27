#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXTOT = 4e5 + 1018 + 11108;
const int INF = 1e9 + 1018 + 1108;

class FastIO{//1.2
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

int n,m,timeCnt = 1,q,a[MAXN],savea[MAXN];
struct Trans{
	int l,r,x,y;
}trans[MAXN];
struct Query{
	int l,r,k,nowt,id;
}query[MAXN];
unordered_map<int,int> org2val;
int val2org[MAXTOT],tot;

class SegmentTree{
private:
	int sum[MAXTOT * 4],vals[MAXTOT];
	inline void PushUp(int p){
		sum[p] = sum[p*2] + sum[p*2+1];
		return ;
	}
	void Change(int p,int l,int r,int pos,int _val){
		if(l == r){
			vals[l] += _val;
			sum[p] = (vals[l] > 0);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= pos)Change(p*2,l,mid,pos,_val);
		if(mid < pos)Change(p*2+1,mid+1,r,pos,_val);
		PushUp(p);
		return ;
	}
	int QueryKth(int p,int l,int r,int k,int pre){
		if(l == r){
			if((val2org[l+1]-1) - pre - sum[p] >= k)return l;
			return l + 1;
		}
		const int mid = (l + r) >> 1;
		if((val2org[mid+1]-1) - pre - sum[p*2] >= k){
			return QueryKth(p*2,l,mid,k,pre);
		}else{
			return QueryKth(p*2+1,mid+1,r,k,pre + sum[p*2]);
		}
		return 10181108;
	}
	int Query(int p,int l,int r,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR){
			return sum[p];
		}
		const int mid = (l + r) >> 1;
		int ret = 0;
		if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
		return ret;
	}
public:
	inline void Change(int pos,int _val){
		Change(1,1,tot,pos,_val);
		return ;
	}
	inline int QueryKth(int k){
		return QueryKth(1,1,tot,k,0);
	}
	inline int Query(int l,int r){
		if(l > r)return 0;
		return Query(1,1,tot,l,r);
	}
}tr;
vector<int> vec;
namespace Subtask1{
	int belong[MAXN],blk_len,aval[MAXN],ans[MAXN];
	bool Cmp4Query(Query q1,Query q2){
		if(belong[q1.l] != belong[q2.l])return belong[q1.l] < belong[q2.l];
		if(belong[q1.l] & 1){
			return q1.r < q2.r;
		}else{
			return q1.r > q2.r;
		}
	}
	inline void Solve(){
		blk_len = sqrt(n);
		for(int i = 1;i <= n;i++){
			belong[i] = ((i - 1) / blk_len) + 1;
			aval[i] = org2val[a[i]];
		}
		sort(query+1,query+q+1,Cmp4Query);
		for(int nowq = 1,l = 1,r = 0;nowq <= q;nowq++){
			while(l > query[nowq].l){
				tr.Change(aval[--l],1);
			}
			while(r < query[nowq].r){
				tr.Change(aval[++r],1);
			}
			while(l < query[nowq].l){
				tr.Change(aval[l++],-1);
			}
			while(r > query[nowq].r){
				tr.Change(aval[r--],-1);
			}
			int pos = tr.QueryKth(query[nowq].k),pre = tr.Query(1,pos);	
			ans[query[nowq].id] = query[nowq].k+pre;
		}
		for(int i = 1;i <= q;i++){
			fio<<ans[i]<<'\n';
		}
		return ;
	}
}
namespace Subtask2{
	inline void Solve(){
		for(int nowq = 1,nowt = 1;nowq <= q;nowq++){
			while(nowt < query[nowq].nowt){
				for(int i = trans[nowt].l;i <= trans[nowt].r;i++){
					if(a[i] == trans[nowt].x)a[i] = trans[nowt].y;
				}
				nowt++;
			}
			for(int i = query[nowq].l;i <= query[nowq].r;i++){
				tr.Change(org2val[a[i]],1);
			}
			int pos = tr.QueryKth(query[nowq].k),pre = tr.Query(1,pos);		
			fio<<query[nowq].k+pre<<'\n';
			for(int i = query[nowq].l;i <= query[nowq].r;i++){
				tr.Change(org2val[a[i]],-1);
			}
		}
		return ;
	}
}
int main(){
	freopen("kthmex.in","r",stdin);
	freopen("kthmex.out","w",stdout);
	fio>>n>>m;
	for(int i = 1;i <= n;i++){
		fio>>a[i];
		vec.push_back(a[i]);
	}
	for(int i = 1,opt,l,r,x,y;i <= m;i++){
		fio>>opt;
		if(opt == 1){
			fio>>l>>r>>x>>y;
			trans[timeCnt++] = {l,r,x,y};
			vec.push_back(x),vec.push_back(y);
		}else{
			fio>>l>>r>>x;
			q++;
			query[q] = {l,r,x,timeCnt,q};
		}
	}
	vec.push_back(0);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i = 0;i < int(vec.size());i++){
		org2val[vec[i]] = i + 1;
		val2org[i + 1] = vec[i];
	}
	tot = vec.size();
	val2org[tot + 1] = INF;
	if(q == m){
		Subtask1::Solve();
	}else{
		Subtask2::Solve();
	}
	return not(Akano loves pure__Elysia);
}
