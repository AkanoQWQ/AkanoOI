//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1e5 + 1018 + 1108;
//const int SIZE = MAXN * 7;
//const int money1 = 300000;
//const int money2 = 4000;
//const int money3 = 500;
//int value[103][4];
//struct Node{
//	int pos,fir,sec,dep;
//	Node(){}
//	Node(int _pos,int _fir,int _sec,int _dep){
//		pos = _pos,fir = _fir,sec = _sec,dep = _dep;
//	}
//};
//class Trie{
//	private:
//		int nxt[SIZE][11],cnt[SIZE],tot;
//	public:
//		inline void Insert(const string& str){
//			int u = 0;
//			for(auto ch : str){
//				if(nxt[u][ch - '0'] == 0)nxt[u][ch - '0'] = ++tot;
//				u = nxt[u][ch - '0'];
//				cnt[u]++;
//			}
//		}
//		inline void Build(){
//			queue<Node> q;
//			q.push(Node(0,0,0,0));
//			while(!q.empty()){
//				const Node now = q.front();
//				q.pop();
//				const int nowval = now.fir * 10 + now.sec;
//				if(now.dep == 2){
//					value[nowval][1] = max(value[nowval][1],cnt[now.pos] * money3);
//				}else if(now.dep == 4){
//					value[nowval][2] = max(value[nowval][2],cnt[now.pos] * money2);
//				}else if(now.dep == 6){
//					value[nowval][3] = max(value[nowval][3],cnt[now.pos] * money1);
//					continue;
//				}
//				for(int i = 0;i < 10;i++){
//					if(nxt[now.pos][i] == 0)continue;
//					if(now.dep == 0){
//						q.push(Node(nxt[now.pos][i],i,now.sec,now.dep+1));
//					}else if(now.dep == 1){
//						q.push(Node(nxt[now.pos][i],now.fir,i,now.dep+1));
//					}else{
//						q.push(Node(nxt[now.pos][i],now.fir,now.sec,now.dep+1));
//					}
//				}
//			}
//		}
//}tr;
//int n;
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("lottery/lottery1.in","r",stdin);
//	cin>>n;
//	for(int i = 1;i <= n;i++){
//		string str;
//		cin>>str;
//		tr.Insert(str);
//	}
//	tr.Build();
//	for(int i = 1;i <= 100;i++){
//		for(int j = 1;j <= 3;j++){
//			if(value[i][j] != 0){
//				cout<<i<<" to "<<j<<" val "<<value[i][j]<<endl;
//			}
//		}
//	}
//	return 0;
//}

