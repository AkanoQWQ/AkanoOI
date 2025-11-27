#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 2e5 + 1018 + 1108;
namespace ScanLine{
	struct Line{
		int l,r,v;
		Line() = default;
		Line(int _l,int _r,int _v){
			l = _l,r = _r,v = _v;
			return ;
		}
	};
	vector<Line> offline;
	inline void AddRectangle(int l,int r,int u,int d){
		
		return ;
	}
}
vector<int> xvec,yvec;
int n,orgrect[MAXN][4];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>orgrect[i][0]>>orgrect[i][1]>>orgrect[i][2]>>orgrect[i][3];
		xvec.push_back(orgrect[i][0]),xvec.push_back(orgrect[i][2]);
		yvec.push_back(orgrect[i][1]),yvec.push_back(orgrect[i][3]);
	}
	sort(xvec.begin(),xvec.end()),sort(yvec.begin(),yvec.end());
	xvec.erase(unique(xvec.begin(),xvec.end()),xvec.end());
	yvec.erase(unique(yvec.begin(),yvec.end()),yvec.end());
	for(int i = 0)
	return not(Akano loves pure__Elysia);
}
