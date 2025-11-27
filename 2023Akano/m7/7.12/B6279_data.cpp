#include<bits/stdc++.h>
using namespace std;
int len = 150,n = 30,s = 20;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B6279.in","w",stdout);
	for(int i = 1;i <= len;i++)putchar('a');
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= s;j++)putchar('a');
		putchar('\n');
	}
	return 0;
}

