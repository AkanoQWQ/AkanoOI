#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1e6 + 1018 + 1108;
const int MAXM = 4e6 + 1018 + 1108;
const int MAXON = 1e5 + 1018 + 1108;

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

struct Edge{
	int nxt,to;
}e[MAXM];
struct SaveEdge{
	int u,v,x,y;
	SaveEdge() = default;
	SaveEdge(int _u,int _v,int _x,int _y){
		u = _u,v = _v,x = _x,y = _y;
		return ;
	}
};
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
vector<int> vec[MAXON],no[MAXON];
vector<SaveEdge> edges;
int n,m,nnt,dir2time[MAXN],vis[MAXN];
inline void BFS(int st){
	queue<int> q;
	vis[st] = st;
	q.push(st);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(vis[v])continue;
			q.push(v),vis[v] = vis[u];
		}
	}
	return ;
}
int main(){
//	freopen("loj2872.in","r",stdin);
	fio>>n>>m;
	for(int i = 1,u,v,x,y;i <= m;i++){
		fio>>u>>v>>x>>y;
		edges.emplace_back(u,v,x,y);
		vec[u].push_back(x),vec[v].push_back(y);
	}
	for(int u = 1;u <= n;u++){
		sort(vec[u].begin(),vec[u].end());
		for(int i = 0;i < int(vec[u].size());i++){
			no[u].push_back(++nnt);
			dir2time[nnt] = -1;
		}
		for(int i = 0;i < int(vec[u].size());i++){
			if(i+1 < int(vec[u].size())){
				AddEdge(no[u][i],no[u][i+1]);
			}
		}
	}
	dir2time[0] = -1;
	for(auto i : edges){
		int u = *(lower_bound(vec[i.u].begin(),vec[i.u].end(),i.x) - vec[i.u].begin() + no[i.u].begin());
		int v = *(lower_bound(vec[i.v].begin(),vec[i.v].end(),i.y) - vec[i.v].begin() + no[i.v].begin());
		AddEdge(u,v);
	}
	for(int i = int(no[1].size()) - 1;i >= 0;i--){
		dir2time[no[1][i]] = vec[1][i];
		BFS(no[1][i]);
	}
	int Q,t;
	fio>>Q;
	while(Q--){
		fio>>t;
		auto it = upper_bound(vec[n].begin(),vec[n].end(),t);
		if(it == vec[n].begin()){
			fio<<-1<<'\n';
			continue;
		}
		it--;
		int now = vis[*(it - vec[n].begin() + no[n].begin())];
		fio<<dir2time[now]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
