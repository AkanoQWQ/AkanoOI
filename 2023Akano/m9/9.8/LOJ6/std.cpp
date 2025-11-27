#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
Interactor<4096> inter;

int get_num(){
    inter<<"get_num"<<Flush;
    int ret;
    inter>>ret;
    return ret;
}

int guess(int index, int x){
    inter<<"guess "<<index<<" "<<x<<Flush;
    int ret;
    inter>>ret;
    return ret;
}

void submit(const vector<int> &result){
    inter<<"submit ";
    for(auto it = result.begin();it!= result.end();it++){
        inter<<*it<<" ";
    }
    inter<<Flush;
}
inline int solve(int i) {
	int l = 0, r = 1000000;
	while(l < r){
		int mid = l + (r - l) / 2;
		if(guess(i, mid) >= 0){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return l;
}

int main() {
	inter.ConnectTwoWay("aplusb");
	int n = get_num();
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = solve(i);
	}
	submit(a);
	return 0;
}
