#include<bits/stdc++.h>
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;
using ll = long long;
using vi = vector<long long>;
using pil = pair<int,long long>;
using pii = pair<int,int>;
using ull = unsigned long long;
using i128 = __int128;
const ll MAXN = 1e12;
const int MAXV = 14672 + 1108 + 1018;
const int MOD = 1e9 + 7;
int nxt[12],a[15],len;
ll n,k,cnt[MAXV],cnt2[MAXV],ans;
vi fi,prim = {2,3,5,7};
void predfs(ll nownum,int w){
    if(nownum > n)return ;
    if(!w && nownum != 0){
        fi.push_back(nownum);
        return ;
    }
    predfs(nownum * w,w);
    predfs(nownum,nxt[w]);
    return ;
}
inline void Pre(){
    nxt[2] = 3,nxt[3] = 5,nxt[5] = 7,nxt[7] = 0;
    predfs(1,2);
    ll copyn = n;
    while(copyn){
        a[++len] = copyn % 10;
        copyn /= 10;
    }
    return ;
}
struct my_hash{
    ull operator()(pil x)const {
        ull ret = x.first * (1ll << 30) + x.second;
        return ret;
    }
};
bool operator==(pil xa,pil xb){
    if(xa.first != xb.first)return false;
    return xa.second == xb.second;
}
unordered_map<pil,ll,my_hash> mp;
ll dfs(int pos,ll mul,bool limit,bool lead0){
    if(!pos)return (mul == 1 && lead0 == 0);
    ll ret = 0;
    int up = limit ? a[pos] : 9;
    if(!limit && !lead0 && mp.find(make_pair(pos,mul)) != mp.end()){
        return mp[make_pair(pos,mul)];
    }
    //choose 0
    if(lead0){
        // cout<<"in "<<pos<<" choose "<<0<<" mul "<<mul<<endl;
        ret += dfs(pos-1,mul,false,lead0);
    }
    for(int p = 1;p <= up;p++){
        if(mul % p != 0)continue;
        // cout<<"in "<<pos<<" choose "<<p<<" mul "<<mul<<endl;
        ret += dfs(pos-1,mul / p,limit && (p == up),false);
    }
    if(!limit && !lead0){
        mp[make_pair(pos,mul)] = ret;
    }
    // cout<<pos<<" ret "<<ret<<endl;
    return ret;
}
inline ll Solve(ll x){
//    cout<<"NOW CALC "<<x<<endl;
    return dfs(len,x,true,true);
}
inline ll F(ll x){
    ll ret = 1;
    while(x){
        ret *= x % 10;
        x /= 10;
    }
    return ret;
}
bool cmp(ll xa,ll xb){
    return xa > xb;
}
struct Node{
    int fir,sec;
    Node(){
        fir = sec = 0;
    }
    Node(int inf,int ins){
        fir = inf,sec = ins;
    }
};
i128 i128_1 = 1;
bool operator<(Node xa,Node xb){
    i128 vala = i128_1 * cnt[xa.fir] * cnt[xa.sec];
    i128 valb = i128_1 * cnt[xb.fir] * cnt[xb.sec];
    return vala < valb;
}
ostream& operator<<(ostream& cout,Node x){
    cout<<x.fir<<" "<<x.sec;
    return cout;
}
int main(){
	freopen("P3303.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    Pre();
    for(int i = 0;i < fi.size();i++){
        cnt[i] = Solve(fi[i]);
        if(i > 0 && fi[i] == fi[i-1])cout<<"??????"<<endl;
        //cout<<fi[i]<<" : "<<cnt[i]<<" ? "<<cnt2[fi[i]]<<endl;
    }
    sort(cnt,cnt + fi.size(),cmp);
    // for(int i = 0;i < fi.size();i++){
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<endl;
    priority_queue<Node> q;
    for(int i = 0;i < fi.size();i++){
        if(cnt[i] == 0)break;
        q.push(Node(i,0));
    }
    for(int i = 1;i <= k;i++){
        if(q.empty())break;
        Node u = q.top();
        q.pop();
        ans += cnt[u.fir] * cnt[u.sec];
        ans %= MOD;
        //cout<<u<<" : "<<cnt[u.fir]<<" * "<<cnt[u.sec]<<endl;
        u.sec++;
        if(cnt[u.sec] > 0){
            q.push(u);
        }
    }
    cout<<ans;
    return 0;
}
