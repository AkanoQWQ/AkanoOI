#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

constexpr int n = 10;
constexpr int ALIVE = 2;
constexpr int Turns = 1e4;
constexpr int TimeUP = 20;


inline double Tanh(double x){
	constexpr static double eval = 2.7182818284590452353602874713526624977572;
	return (pow(eval,x)-pow(eval,-x))/(pow(eval,x)+pow(eval,-x));
}
inline double ReLU(double x){
	return max(double(0),x);
}
mt19937 NNrng(time(0));
uniform_real_distribution<double> NNrngDis(-1,1);
class NN{
private:
	using vd = vector<double>;
	using vi = vector<int>;
	using funcT = function<double(double)>;
	
	int tier;//层
	vi width;//每一层的宽度
	struct Node{
		funcT afunc;
		vd w;
		double b,inputval,outputval;
		inline void AddVal(int no,double x){
//			cerr<<no<<" w "<<w[no]<<" b "<<b<<" get "<<x<<" -> "<<x * w[no] + b<<" in "<<w.size()<<endl;
			inputval += x * w[no] + b;
			return ;
		}
		inline void Calc(){
			outputval = afunc(inputval);
			return ;
		}
		Node(){
			inputval = outputval = b = 0;
			return ;
		}
	};
	vector<vector<Node> > node;
public:
	inline void SetSize(int _tier,const vi& _width){
		tier = _tier,width = _width;
		node.clear();
		node.resize(tier+1);
		for(int i = 1;i <= tier;i++){
			node[i].resize(width[i]+1);
			if(i != 1){
				for(int j = 1;j <= width[i];j++){
					node[i][j].w.resize(width[i-1]+1);
				}
			}
		}
		return ;
	}
	inline void SetFunc(funcT _func){
		for(int t = 1;t <= tier;t++){
			for(int i = 1;i <= width[t];i++){
				node[t][i].afunc = _func;
			}
		}
		return ;
	}
	inline vd Calc(const vd& _input){
		for(int i = 1;i <= width[1];i++){
			node[1][i].inputval = _input[i];
		}
		for(int t = 1;t < tier;t++){
			for(int u = 1;u <= width[t+1];u++){
				node[t+1][u].inputval = 0;//清空
			}
			for(int u = 1;u <= width[t];u++){
				node[t][u].Calc();
				for(int v = 1;v <= width[t+1];v++){
					node[t+1][v].AddVal(u,node[t][u].outputval);
				}
			}
		}
		vd ret(width[tier]+1);
		for(int i = 1;i <= width[tier];i++){
			node[tier][i].Calc();
			ret[i] = node[tier][i].outputval;
		}
		return ret;
	}
	inline void RandChange(double temp){
		for(int t = 2;t <= tier;t++){
			for(int i = 1;i <= width[t];i++){
				for(int j = 1;j <= width[t-1];j++){
					node[t][i].w[j] += NNrngDis(NNrng) * temp;
				}
				node[t][i].b += NNrngDis(NNrng) * temp;
			}
		}
		return ;
	}
	NN(){
		tier = 0;
		return ;
	}
	NN(const vi& _width){
		SetSize(int(_width.size()) - 1,_width);
		return ;
	}
	NN(int _tier,const vi& _width){
		SetSize(_tier,_width);
		return ;
	}
};
NN nns[n + 2],emp = NN({0,1,3,4,3,1});
double score[n + 2];
inline double P(double x){
	return x * x;
}
bool CmpByScore(int x,int y){
	return score[x] < score[y];
}
mt19937 mainrng(time(0));
inline int Rand(int l,int r){
	return (mainrng() % (r - l + 1)) + l;
}
inline bool Judge(double x){
	return (11 <= x && x <= 20) || (31 <= x && x <= 70);
}
int main(){
	emp.SetFunc(ReLU);
	for(int i = 0;i <= n;i++){
		nns[i] = emp;
	}
	int best = 0;
	vector<int> numberVec;
	for(int i = 1;i <= n;i++){
		numberVec.push_back(i);
	}
	while(clock() < TimeUP * CLOCKS_PER_SEC){
		double maxscore = 0.0001;
		for(int i = 1;i <= n;i++){
			maxscore = max(maxscore,score[i]);
		}
		for(int i = 1;i <= n;i++){
			if(i != best)nns[i].RandChange(100 * score[i] / maxscore);	
		}
		int cnttrue = 0,cntfalse = 0;
		for(int i = 1;i <= n;i++){
			score[i] = 0;
			for(int inputx = 1;inputx <= 100;inputx++){
				vector<double> res = nns[i].Calc({0,double(inputx)});
				if((res[1] < 0.5) != (Judge(inputx))){
					score[i]++;
				}
				if(res[1] < 0.5){
					cnttrue++;
				}else{
					cntfalse++;
				}
				if(isnan(res[1])){
					nns[i] = nns[i-1];
					score[i] = score[i-1];
					break;
				}
			}
		}
		sort(numberVec.begin(),numberVec.end(),CmpByScore);
		while(int(numberVec.size()) > ALIVE){
			numberVec.pop_back();
		}
		best = numberVec[0];
		for(int i = 1;i <= n;i++){
			int x = numberVec[Rand(0,ALIVE-1)];
			if(score[x] < score[i]){
				nns[i] = nns[x];
			}
		}
	}
	cerr<<"score "<<score[best]<<endl;
	int cnttrue = 0,cntfalse = 0,tscore = 0;
	for(int i = 1;i <= 100;i++){
		vector<double> res = nns[best].Calc({0,double(i)});
		if(res[1] < 0.5){
			cnttrue++;
		}else{
			cntfalse++;
		}
		if((res[1] < 0.5) != (Judge(i))){
			tscore++;
		}
	}
	cerr<<cnttrue<<" and "<<cntfalse<<" tscore "<<tscore<<endl;
	while(true){
		double x;
		cout<<"input x:";
		cin>>x;
		double res = nns[best].Calc({0,x})[1];
		if(res < 0.5){
			cout<<" is true"<<endl;
		}else{
			cout<<" is false"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
