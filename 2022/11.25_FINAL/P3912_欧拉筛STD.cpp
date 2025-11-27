#include<bits/stdc++.h>
using namespace std;
void init() {
  for (int i = 2; i < MAXN; ++i) {
    if (!vis[i]) {
      pri[cnt++] = i;
    }
    for (int j = 0; j < cnt; ++j) {
      if (1ll * i * pri[j] >= MAXN) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0)break;
    }
  }
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	return 0;
}

