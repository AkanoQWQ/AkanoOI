#include<Windows.h>
#include<bits/stdc++.h>
using namespace std;

int delCnt,totCnt = 0;

inline void ShowEvent(){
	const static int refreshTick = 8;
	while(true){
		system("cls");
		cout<<delCnt<<" / "<<totCnt<<endl;
		int prec1 = max(totCnt,1);
		cout<<delCnt * 100 / prec1<<" % 删除率"<<endl;
		int prec2 = max(totCnt - delCnt,1);
		cout<<delCnt * 100 / prec2<<" % 错误率"<<endl;
		Sleep(1000 / refreshTick);
	}
	return ;
}
HHOOK keyboardHookHandle;
LRESULT CALLBACK keyboardHook(int code, WPARAM wParam, LPARAM lParam) {
	KBDLLHOOKSTRUCT* kbDllHookStruct = (KBDLLHOOKSTRUCT*)lParam;
	int vkey = kbDllHookStruct->vkCode;
	if (code == HC_ACTION){
		if(wParam == WM_KEYDOWN){
			BYTE state[256];
			GetKeyboardState(state);
			char ret[256];
			if(ToAscii(vkey,kbDllHookStruct->scanCode,state,(LPWORD)ret,0) > 0){
				int ch = int(ret[0]);
				if(ch == 8){
					delCnt++;
				}
				totCnt++;
			}
		}
	}
	return CallNextHookEx(keyboardHookHandle, code, wParam, lParam);
}

int main(){
	SetConsoleTitle("错误检测器");
	thread showThread(ShowEvent);
	showThread.detach();
	keyboardHookHandle = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardHook, GetModuleHandle(NULL), 0);
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0));
	UnhookWindowsHookEx(keyboardHookHandle);
	system("pause");
	return 0;
}
