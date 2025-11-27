#include<bits/stdc++.h>
using namespace std;
const int MAXN = 60000 + 1018 + 1108;
const int INF = 0;
struct Node{
	int connect,splitL,splitR,splitLR;
	Node(){connect = splitL = splitR = splitLR = 0;}
};
int n,q;
int LR[MAXN][2],mnLR[MAXN],sumLR[MAXN],UD[MAXN];
inline Node Merge(Node n1,Node n2,int mid){
	Node ret;
//	cout<<"MERGE "<<mid<<" with "<<mnLR[mid]<<" and "<<sumLR[mid]<<endl;
	const int val1 = n1.splitL + n2.splitR + mnLR[mid];
	const int val2 = n1.splitL + n2.splitLR + sumLR[mid];
	const int val3 = n1.splitLR + n2.splitR + sumLR[mid];
	ret.splitLR = min(val1,min(val2,val3));
	const int val4 = n1.connect + n2.splitR + mnLR[mid];
	const int val5 = n1.connect + n2.splitLR + sumLR[mid];
	const int val6 = n1.splitR + n2.splitR + sumLR[mid];
	ret.splitR = min(val4,min(val5,val6));
	const int val7 = n1.splitL + n2.connect + mnLR[mid];
	const int val8 = n1.splitLR + n2.connect + sumLR[mid];
	const int val9 = n1.splitL + n2.splitL + sumLR[mid];
	ret.splitL = min(val7,min(val8,val9));
	const int ex1 = n1.connect + n2.connect + mnLR[mid];
	const int ex2 = n1.connect + n2.splitL + sumLR[mid];
	const int ex3 = n1.splitR + n2.connect + sumLR[mid];
	ret.connect = min(ex1,min(ex2,ex3));
	return ret;
}
class SegmentTree{
	private:
		Node node[MAXN * 4];
		vector<pair<int,int> > dir[MAXN];
		inline void PushUp(int p,int l,int r){
			const int mid = (l + r) >> 1;
			node[p] = Merge(node[p*2],node[p*2+1],mid);
			return ;
		}
		void Build(int p,int l,int r){
			if(l == r){
				node[p].connect = UD[l],node[p].splitL = node[p].splitR = INF;
				node[p].splitLR = 0;
				return ;
			}
			const int mid = (l + r) >> 1;
			dir[mid].push_back(make_pair(l,r));
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			PushUp(p,l,r);
			return ;
		}
		Node Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
//				cout<<l<<" Query "<<r<<" is "<<node[p].connect<<","<<node[p].split<<" in "<<p<<endl;
				return node[p];
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL && mid < OBJR){
				Node n1 = Query(p*2,l,mid,OBJL,OBJR);
				Node n2 = Query(p*2+1,mid+1,r,OBJL,OBJR);
				return Merge(n1,n2,mid);
			}else if(mid >= OBJL){
				return Query(p*2,l,mid,OBJL,OBJR);
			}else if(mid < OBJR){
				return Query(p*2+1,mid+1,r,OBJL,OBJR);
			}
			cout<<"ERR"<<endl;
			Node ret;
			return ret;//SHOULD'NT
		}
		void UpdateUD(int p,int l,int r,int OBJ){
			if(l == r){
				node[p].connect = UD[l],node[p].splitL = node[p].splitR = INF;
				node[p].splitLR = 0;
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)UpdateUD(p*2,l,mid,OBJ);
			if(mid < OBJ)UpdateUD(p*2+1,mid+1,r,OBJ);
			PushUp(p,l,r);
			return ;
		}
		void UpdateLR(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
//				cout<<"FIND "<<l<<","<<r<<" in "<<OBJL<<" and "<<OBJR<<endl;
				PushUp(p,l,r);
//				cout<<l<<" to "<<r<<" is "<<node[p].connect<<" ? "<<(l+r)/2<<endl;
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)UpdateLR(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)UpdateLR(p*2+1,mid+1,r,OBJL,OBJR);
			PushUp(p,l,r);
			return ;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline int Query(int l,int r){
			Node ret = Query(1,1,n,l,r);
			return ret.connect;
		}
		inline void UpdateUD(int pos){
			UpdateUD(1,1,n,pos);
			return ;
		}
		inline void UpdateLR(int pos){
			for(auto i : dir[pos]){
//				cout<<"UPD "<<i.first<<" to "<<i.second<<endl;
				UpdateLR(1,1,n,i.first,i.second);
			}
			return ;
		}
}tr;
int arr[1];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P5618.in","r",stdin);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		cin>>LR[i][0];
	}
	for(int i = 1;i < n;i++){
		cin>>LR[i][1];
		mnLR[i] = min(LR[i][0],LR[i][1]);
		sumLR[i] = LR[i][0] + LR[i][1];
	}
	for(int i = 1;i <= n;i++){
		cin>>UD[i];
	}
	tr.Build();
	while(q--){
		char opt;
		cin>>opt;
		if(opt == 'Q'){
			int l,r;
			cin>>l>>r;
			cout<<tr.Query(l,r)<<endl;
		}else{
			int _x0,_y0,_x1,_y1,val;
			cin>>_x0>>_y0>>_x1>>_y1>>val;
			if(_y0 == _y1){
				UD[_y0] = val;
				tr.UpdateUD(_y0);
			}else{
				int pos = min(_y0,_y1);
				LR[pos][_x0-1] = val;
				mnLR[pos] = min(LR[pos][0],LR[pos][1]);
				sumLR[pos] = LR[pos][0] + LR[pos][1];
				tr.UpdateLR(pos);
			}
		}
	}
	return 0;
}
