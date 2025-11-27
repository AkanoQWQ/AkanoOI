#include<bits/stdc++.h>
using namespace std;
string ord;
int x,y,step;
bool ST = true,NOWX = true;
vector<int> xVec,yVec;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>ord>>x>>y;
	ord += "T";
	for(auto i : ord){
		if(i == 'F'){
			step++;
		}else{
			if(ST){
				x -= step;
				ST = false;
			}else{
				if(NOWX){
					xVec.push_back(step);
				}else{
					yVec.push_back(step);
				}
			}
			NOWX = !NOWX;
			step = 0;
		}
	}
	if(st.find(make_pair(x,y)) != st.end()){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

