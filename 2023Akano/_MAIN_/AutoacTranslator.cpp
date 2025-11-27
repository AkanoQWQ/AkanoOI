#include<bits/stdc++.h>
using namespace std;
string name;
bool pre = 1;
string str,otp;
inline char SafeGet(int pos){
    if(pos >= str.length())return ' ';
    return str[pos];
}
int main(){
    cin>>name;
    freopen(name.c_str(),"r",stdin);
    freopen(("AutoAC_"+name).c_str(),"w",stdout);
    while(getline(cin,str)){
        otp = "";
        for(int i = 0;i < str.length();i++){
            if(str[i] == '$'){
                if(SafeGet(i+1) == '$')continue;
                if(pre){
                    otp += "  [kat";
                    otp += "ex]  ";
                }else{
                    otp += "  [/kat";
                    otp += "ex]  ";//分开写是为了防歧义
                }
                pre = !pre;
            }else if(str[i] == '<'){
                otp += "&l";
                otp += "t;";//同理，防歧义
            }else if(str[i] == '&'){
                otp += "&a";
                otp += "mp;";
            }else{
                otp += str[i];
            }
            if(str[i] == ']' && SafeGet(i+1) == '['){//避免Katex中 双[]被识别 
                otp += "  ";
            }
        }
        cout<<otp<<endl;
    }
    return 0;
}
