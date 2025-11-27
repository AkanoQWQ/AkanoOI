如题，经过这几天的不懈~~摸鱼~~奋斗，咱使用 Windows 的 管道（pipe）写出了一个 IO式 的交互器。    

相信很多和咱一样的交互题爱好者总是在想打个交互题的时候因为其不方便调试而放弃，也有很多人望而止步。  

这个交互器能够**在一定程度上**帮助调试本地的IO程序  

然而不得不说的是，以前想要本地调试IO几乎不可能，加上这个交互器也只是**略好一些**，咱先来说下这个交互器的缺点  

1. 需要调整程序本身，交互器不使用 `stdin` 和 `stdout`，而是交互库的 `Interactor` 类，这使得你需要在以下方面调整代码：替换 `cin,cout` 为 `inter` （假设你的`Interactor`名字叫做`inter`），并且替换 `endl` 和 `flush` 为 `Flush`，最后在代码开头加上连接。这个咱以后会出一个自动调整代码的评测器，但是现在只能手动调整。  
2. 可能出现交互卡死的情况，这是因为管道通信是阻塞的。“阻塞”这个术语不一定准确，总之意思就是一方读取当前文件内的内容之前程序会卡在写入的地方。一般来说交互都是你一下我一下的，不会出现这种问题，然而有时说不定也会出问题......
3. 像 `cout<<123<<456;` 这种输出 `123456` 的代码可能会导致错误（接收到了`123`）（如果你善用 `Flush` 也许就没问题）
4. 效率极其低下，一般交互题不卡时间还好，卡时间的话可能得算上个几十倍的常数（不过调试的话数据范围应该也不大）  

以下是一个标准的交互程序的示例：  

`judger.cpp`  

```cpp
#include<bits/stdc++.h>
#include<AL/main.h>//包含了交互库的个人库,下载链接在下面 
using namespace std;
Interactor<4096> inter;//创建一个缓冲区为4096的交互器
string password; 
int main(){
	inter.CreateTwoWay("exampl");//连接程序,两边的名字要一样 
	inter>>password;
	if(password == "Hello_world!"){
		cerr<<"答案正确!"<<endl;
	}else{
		cerr<<"答案错误!"<<endl;
	}
	system("pause");
    return 0;
}
```

`user.cpp`

```cpp
#include<bits/stdc++.h>
#include<AL/main.h>//包含了交互库的个人库,下载链接在下面 
using namespace std;
Interactor<4096> inter;//创建一个缓冲区为4096的交互器
string password; 
int main(){
	inter.ConnectTwoWay("exampl");//连接程序,必须一个Create一个Connect 
	srand(time(0));
	if(rand() % 2){
		inter<<"Hello_world!"<<Flush;//记得Flush 
	}else{
		inter<<"I_dont_LIKE_AC!!!!!"<<Flush;//不支持 getline 所以用下划线连起来 
	}
    return 0;
}
```  

顺带一提这个名字是有讲究的，首先不能太长，其次有关键词，example 竟然是关键词（）  

以下是 [loj#6 猜数字](https://loj.ac/p/6/files) 的交互库与选手代码样例：  

`judger.cpp`

```cpp
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
```

`user.cpp`

```cpp
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
```

想要下载的话，来这里就行：[下载链接](http://www.autoac.top/index.php/al_and_peoj/) 

下载 2023.9.7 版本的就行，后面的咱也不确定好用（）  

然后使用方法就是，每次把这个 `AL` 文件夹放在代码目录下并且 `#include""`。如果想要长期使用可以把这个文件夹放在编译器 `include` 目录下并 `#include<>`

再顺带一提，所有内容都放在了 `server.h` 下，如果你不想捆绑着下载咱的个人库的话，只放 `server.h` 也是可以的
