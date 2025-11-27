#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ppiipii = pair<pii,pii>;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXLG = log2(MAXN) + 2;
const int INF = 1e9;
template<typename T> class ST_table{
	private:
		T val[MAXN][MAXLG];
		int pos[MAXN][MAXLG],tot;
	public:
		inline void Insert(T x){
			val[++tot][0] = x,pos[tot][0] = tot;
			return ;
		}
		inline void PreCalc(){
			const int lg = log2(tot)+1;
			for(int len = 1;len <= lg;len++){
				for(int i = 1;i <= tot;i++){
					const int ed = min(i + (1<<len) - 1,tot);
					const int mid = ed - (1<<(len-1)) + 1;
					if(val[i][len-1] < val[mid][len-1]){
						val[i][len] = val[i][len-1],pos[i][len] = pos[i][len-1];
					}else{
						val[i][len] = val[mid][len-1],pos[i][len] = pos[mid][len-1];
					}
				}
			}
			return ;
		}
		inline pair<T,int> Query(int l,int r){
			if(l > r)return make_pair(INF,tot);
			int len = log2(r - l + 1);
			const int ed = min(l + (1<<len) - 1,tot);
			const int mid = ed - (1<<(len-1)) + 1;
			if(val[l][len-1] < val[mid][len-1]){
				return make_pair(val[l][len-1],pos[l][len-1]);
			}else{
				return make_pair(val[mid][len-1],pos[mid][len-1]);
			}
		}
};
ST_table<int> st,sec1,sec2;
struct Node{
	int l,r;
	inline ppiipii Val(){//val1 val2 pos1 pos2
		pii val1_pos1 = st.Query(l,r-1);
		pii val2_pos2;
		if(val1_pos1.second & 1){
			val2_pos2 = sec1.Query(val1_pos1.second+1,r);
		}else{
			val2_pos2 = sec2.Query(val1_pos1.second+1,r);
		}
		return make_pair(val1_pos1,val2_pos2);
	}
	Node(){}
	Node(int _l,int _r){l = _l,r = _r;}
};
bool operator<(Node na,Node nb){
	ppiipii val1 = na.Val(),val2 = nb.Val();
	if(val1.first.first != val2.first.first){
		return val1.first.first > val2.first.first;
	}
	if(val1.first.second != val2.first.second){
		return val1.first.second > val2.first.second;
	}
	return val1.second.first < val2.second.first;
}
priority_queue<Node> q;
int n,c;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>c;
		if(i & 1){
			st.Insert(c),sec1.Insert(c),sec2.Insert(INF);
		}else{
			st.Insert(c),sec1.Insert(INF),sec2.Insert(c);
		}
	}
	st.PreCalc(),sec1.PreCalc(),sec2.PreCalc();
	q.push(Node(1,n));
	Node tp = q.top();
	cout<<"TEST"<<endl;
	cout<<tp.l<<" to "<<tp.r<<endl;
	//return 0;
	cout<<tp.Val().first.first<<","<<tp.Val().first.second<<endl;
	return 0;
}

