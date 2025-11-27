//namespace Subtask2{
//	const int MAXN = 1e5 + 1018 + 1108;
//	const int INF = 2e5;
//	int dis[MAXN];
//	class SegmentTree{
//		private:
//			bool status;
//			int val[MAXN * 4];
//			inline void PushUp(int p){
//				if(status == false){
//					val[p] = max(val[p*2],val[p*2+1]);
//				}else{
//					val[p] = min(val[p*2],val[p*2+1]);
//				}
//				return ;
//			}
//			void Build(int p,int l,int r,int _val){
//				val[p] = _val;
//				if(l == r)return ;
//				const int mid = (l + r) >> 1;
//				Build(p*2,l,mid,_val),Build(p*2+1,mid+1,r,_val);
//				return ;
//			}
//			void Change(int p,int l,int r,int OBJ,int _val){
//				if(l == r){
//					val[p] = _val;
//					return ;
//				}
//				const int mid = (l + r) >> 1;
//				if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
//				if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
//				PushUp(p); 
//				return ;
//			}
//			int Query(int p,int l,int r,int OBJL,int OBJR){
//				if(OBJL <= l && r <= OBJR){
//					return val[p];
//				}
//				const int mid = (l + r) >> 1;
//				if(mid >= OBJL && mid < OBJR){
//					if(status == false){
//						return max(Query(p*2,l,mid,OBJL,OBJR),Query(p*2+1,mid+1,r,OBJL,OBJR));
//					}else{
//						return min(Query(p*2,l,mid,OBJL,OBJR),Query(p*2+1,mid+1,r,OBJL,OBJR));
//					}
//				}else if(mid >= OBJL){
//					return Query(p*2,l,mid,OBJL,OBJR);
//				}else if(mid < OBJR){
//					return Query(p*2+1,mid+1,r,OBJL,OBJR);
//				}
//				cerr<<"ERR"<<endl;
//				return 10181108;
//			}
//		public:
//			inline void Build(bool ins){
//				status = ins;
//				if(ins == false){
//					Build(1,1,n,0);
//				}else{
//					Build(1,1,n,INF);
//				}
//			}
//			inline void Change(int pos,int _val){
//				Change(1,1,n,pos,_val);
//				return ;
//			}
//			inline int Query(int l,int r){
//				return Query(1,1,n,l,r);
//			}
//	};
//}
