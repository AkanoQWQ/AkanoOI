#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
ll n,d,a[MAXN],x[MAXN],s[MAXN];
double ans;
namespace ConvexHull{
	struct Point{
		double x,y;
		Point(){}
		Point(double _x,double _y){x = _x,y = _y;}
	};
	bool operator==(const Point& pa,const Point& pb){
		return pa.x == pb.x && pa.y == pb.y;
	}
	bool operator!=(const Point& pa,const Point& pb){
		return !(pa == pb);
	}
	bool operator<(const Point& pa,const Point& pb){
		if(pa == pb)return false;
		if(pa.x != pb.x)return pa.x < pb.x;
		return pa.y > pb.y;
	}
	bool operator>(const Point& pa,const Point& pb){
		if(pa == pb)return false;
		if(pa.x != pb.x)return pa.x > pb.x;
		return pa.y < pb.y;
	}
	Point operator-(const Point& pa,const Point& pb){
		return Point(pa.x-pb.x,pa.y-pb.y);
	}
	double operator*(const Point& pa,const Point& pb){
		return pa.x * pb.y - pb.x * pa.y;
	}
	ostream& operator<<(ostream& cout,Point outP){
		cout<<"("<<outP.x<<","<<outP.y<<")";
		return cout;
	}
	using setit = _Rb_tree_const_iterator<Point>;
	setit operator+(setit it,int num){
		for(int i = 1;i <= num;i++)it++;
		return it;
	}
	setit operator-(setit it,int num){
		for(int i = 1;i <= num;i++)it--;
		return it;
	}
	struct KDP{
		set<Point> st;
		inline bool Corner(auto it){
			return (it == st.begin() || it == (st.end()-1));	
		}
		inline void Insert(Point ins){
			auto res = st.insert(ins);
			auto it = res.first;
			bool suc = res.second;
			if(!suc)return ;
			Point nowP = *it;
			if(!Corner(it)){
				auto pre = it - 1,nxt = it + 1;
				Point preP = *pre,nxtP = *nxt;
				if((nowP - preP) * (nxtP - nowP) < 0){//在凸包内部 
					st.erase(it);
					return ;
				}
			}
			if(it + 1 != st.end()){
				if((*it).x == (*(it+1)).x){
					st.erase(it);
					return ;
				}
			}
			while(it != st.begin() && it-1 != st.begin()){
				auto pre = it - 1,ppre = pre - 1;
				Point preP = *pre,ppreP = *ppre;
				if((preP - nowP) * (ppreP - nowP) > 0){//OK?
					st.erase(pre);
				}else{
					break;
				}
			}
			while(it != st.end()-1 && it+1 != st.end()-1){
				auto nxt = it + 1,nnxt = nxt + 1;
				Point nxtP = *nxt,nnxtP = *nnxt;
				if((nnxtP - nowP) * (nxtP - nowP) > 0){
					st.erase(nxt);
				}else{
					break;
				}
			}
			return ;
		}
	};
}
using namespace ConvexHull;
KDP kdp;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>d;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>x[i];
		s[i] = s[i-1] + a[i];
		double y = 0;
		double upperi = s[i],loweri = x[i] + i * d;
		kdp.Insert(Point(-s[i-1],-d*i));
		for(auto p : kdp.st){
			y = max(y,double(upperi + p.x) / double(loweri + p.y));
		}
		ans += y;
	}
	cout<<fixed<<setprecision(0)<<ans<<endl;
	return 0;
}
