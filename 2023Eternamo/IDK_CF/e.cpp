#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 1018 + 1108;
int t,n,m,k;
struct Rain{
	int l,r,id;
}rain[MAXN];
bool Cmp(Rain r1,Rain r2){
	if(r1.l != r2.l)return r1.l < r2.l;
	return r1.id < r2.id;
}
int cnt[MAXN],cnt1[MAXN],cnt2[MAXN],mx[6],posans[MAXN];
int imp[MAXN][2];
set<int> nowset;
class SegmentTree{
private:
	vector<int> now[MAXN * 4];
	bool cleartag[MAXN * 4];
	inline void PushDown(int p){
		if(cleartag[p]){
			cleartag[p*2] = cleartag[p*2+1] = true;
			now[p*2].clear(),now[p*2+1].clear();
		}
		return ;
	}
	void Insert(int p,int l,int r,int OBJL,int OBJR,int _val){
		if(OBJL <= l && r <= OBJR){
			now[p].push_back(_val);
			return ;
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Insert(p*2,l,mid,OBJL,OBJR,_val);
		if(mid < OBJR)Insert(p*2+1,mid+1,r,OBJL,OBJR,_val);
		return ;
	}
	void Search(int p,int l,int r){
		if(l == r){
			if(nowset.size() <= 2){
				int a1 = (*nowset.begin()),a2 = *(++nowset.begin());
				imp[l][0] = a1,imp[l][1] = a2;
			}else{
				imp[l][0] = imp[l][1] = 0;
			}
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		Search(p*2,l,mid),Search(p*2+1,mid+1,r);
		for(auto i : now[p])nowset.erase(i);
		return ;
	}
public:
	inline void Clear(){
		cleartag[1] = true;
		now[1].clear();
		return ;
	}
	inline void Insert(int l,int r,int _val){
		Insert(1,1,n,l,r,_val);
		return ;
	}
	inline void Search(){
		Search(1,1,n);
		return ;
	}
}tr;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i = 1;i <= n;i++)cnt[i] = 0;
		for(int i = 1;i <= m;i++){
			cin>>rain[i].l>>rain[i].r;
			cnt[rain[i].l]++,cnt[rain[i].r+1]--;
			rain[i].id = i;
		}
		int org0 = 0;
		for(int i = 1;i <= n;i++){
			cnt[i] += cnt[i-1];
			if(cnt[i] == 0)org0++;
			cnt1[i] = cnt1[i-1] + (cnt[i] == 1);
			cnt2[i] = cnt2[i-1] + (cnt[i] == 2);
		}
		sort(rain+1,rain+m+1,Cmp);
		tr.Clear();
		mx[1] = mx[2] = mx[3] = mx[4] = 0;
		for(int i = 1;i <= m;i++){
			posans[i] = cnt1[rain[i].r] - cnt1[rain[i].l-1];
			tr.Insert(rain[i].l,rain[i].r,i);
			if(posans[i] > mx[1]){
				mx[4] = mx[3],mx[3] = mx[2],mx[2] = mx[1],mx[1] = posans[i];
			}else if(posans[i] > mx[2]){
				mx[4] = mx[3],mx[3] = mx[2],mx[2] = posans[i];
			}else if(posans[i] > mx[3]){
				mx[4] = mx[3],mx[3] = posans[i];
			}else if(posans[i] > mx[4]){
				mx[4] = posans[i];
			}
		}
		tr.Search();
		posans[0] = posans[m+1] = -100;
		rain[m+1].l = n + 1;
		int ans = 0,tail = 0;
		for(int i = 1;i <= m;i++){
			int now = posans[i] + mx[1];
			if(mx[1] == posans[i]){
				now = posans[i] + mx[2];
			}
			set<int> imps;
			while(tail+1 <= rain[i].r && rain[imp[tail+1][0]].l <= rain[i].l && rain[imp[tail+1][1]].l <= rain[i].l){
				tail++;
				cerr<<tail<<" belong "<<imp[tail][0]<<" and "<<imp[tail][1]<<" in "<<i<<endl;
				if(imp[tail][0] == i){
					imps.insert(imp[tail][1]);
				}else if(imp[tail][1] == i){
					imps.insert(imp[tail][0]);
				}
			}
			
			for(auto j : imps){
				int realL = max(rain[i].l,rain[j].l),realR = min(rain[i].r,rain[j].r);
				now = max(now,posans[i] + posans[i-1] + cnt2[realR] - cnt2[realL-1]);
			}
			ans = max(ans,now);
		}
		cout<<ans+org0<<endl;
	}
	return 0;
}
