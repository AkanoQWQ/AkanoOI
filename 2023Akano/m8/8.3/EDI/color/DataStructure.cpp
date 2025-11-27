class PlatSeg{
	private:
		int arr[MAXN];
	public:
		inline void Change(int l,int r,int _val){
			for(int i = l;i <= r;i++){
				arr[i] += _val;
				if(arr[i] < 0)cout<<"SEG ERR"<<endl;
			}
			return ;
		}
		inline void Change(int pos,int _val){
			Change(pos,pos,_val);
			return ;
		}
		inline int Query(int l,int r){
			int ret = 0;
			for(int i = l;i <= r;i++)ret += arr[i];
			return ret;
		}
}tr;
