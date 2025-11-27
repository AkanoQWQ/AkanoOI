#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
    for(int i=1;i<=100000;i++)
    {
        system("multiplydata.exe");
        system("multiply_COME_AND_HACK_ME.exe");
        system("multiply_std.exe");
        if(system("fc multiply.out multiply.ans ")){
        	cout<<"WA"<<endl;
        	break;
		}
		else{
			printf("%d\n",i);
		}
    }
    return 0;
}
