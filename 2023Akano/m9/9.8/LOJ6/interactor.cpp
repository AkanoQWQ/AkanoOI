#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
Interactor<4096> inter;
int nguess,n;
vector<int> nums;
inline void ReadInData(){
	freopen("data5.in","r",stdin);//也不需要把stdin改回去了,用不到 
    cin>>n;
    nums.resize(n);
    for(int i = 0;i < n;i++){
        cin>>nums[i];
    }
	return ;
}
int main(){
	inter.CreateTwoWay("aplusb");
	cerr<<"连接到了选手程序!开始评测"<<endl;
	ReadInData();
    while(true){
        string cmd;
        inter>>cmd;
        if(cmd == "get_num"){
            inter<<n<<Flush;
        }else if(cmd == "guess"){
            nguess++;
            int index = 0,val = 0;
            inter>>index>>val;
			if(index < 0 || index >= n){
				cerr<<"index must in [0, n)!"<<endl;
				return 1;
			}
			if(val < nums[index]){
				inter<<-1<<Flush;
			}else if (val > nums[index]){
				inter<<1<<Flush;
			}else{
				inter<<0<<Flush;
			}
        }
        else if (cmd == "submit"){
            bool wrongAnswer = false;
            for(int i = 0; i < n; i++){
                int x;
                inter>>x;
                if (x != nums[i] && !wrongAnswer){
                    wrongAnswer = true;
                    cerr<<"First differ on the "<<i<<"-th number!"<<endl;
					return 1;
                    
                }
            }
            if(!wrongAnswer){
                cerr<<"nguess = "<<to_string(nguess)<<endl;
                return 0;
            }
        }
		else{
			cerr<<"Invalid command "<<cmd<<"!"<<endl;
			return 1;
		}
    }
}
