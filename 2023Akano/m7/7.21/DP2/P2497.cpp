#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const bool OTP = false;
const int MAXN = 5e5 + 1018 + 1108;
const double INF = 1e16;
inline double P(ll inx){
	return inx * inx;
}
int n,m;
struct BaseStation{
	ll x,r,v;
}s[MAXN];
double dp[MAXN],ans = INF,dp2[MAXN];
inline double Cost(int l,int r){
	const double deltaX = s[r].x - s[l].x;
	return deltaX / (2 * sqrt(s[l].r));
}
namespace TwoDPoint{
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
}
using namespace TwoDPoint;
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
	inline double GetK(Point pa,Point pb){
		return (pa.y - pb.y) / (pa.x - pb.x);
	}
	inline double GetB(double nowK){
		if(st.empty())return 0;
		while(true){
			auto it = st.begin();
			if(it + 1 == st.end())break;
			auto nxt = it + 1;
			Point nowP = *it,nxtP = *nxt;
			if(GetK(nowP,nxtP) < nowK){
				st.erase(it);
			}else{
				break;
			}
		}
		Point ans = *(st.begin());
		return ans.y - ans.x * nowK;
	}
}kdp;
inline Point GetPoint(int u){
	return Point(-1.0f / (2 * sqrt(s[u].r)),dp[u] - (s[u].x / (2 * sqrt(s[u].r))));
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>s[i].x>>s[i].r>>s[i].v;
		dp[i] = INF;
	}
	dp[1] = s[1].v;
	kdp.Insert(GetPoint(1));
	for(int i = 2; i <= n;i++){
		double nowans = s[i].v + kdp.GetB(s[i].x);
		dp[i] = nowans;
		kdp.Insert(GetPoint(i));
		if(m - s[i].x <= s[i].r){
			ans = min(ans,dp[i]);
		}
	}
	cout<<fixed<<setprecision(3)<<ans<<endl;
	return 0;
}
/*
dp_i = max{dp_j + (x_i - x_j) / (2*sqrt(r_j))} + s[i].v
b = dp_i - v_i    (dp_i = -b + v_i)
k = x_i
x = -1 / (2 * sqrt(r_j))
y = dp_j - x_j / (2*sqrt(r_j))
*/
