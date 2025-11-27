#ifndef UNICODE
#define UNICODE
#endif 
#include<Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
    // 注册 Windows 窗口 
    const wchar_t CLASS_NAME[]  = L"Windows windows";
    WNDCLASS wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);//窗口类注册到操作系统。

    // 创建窗口 
    HWND hwnd = CreateWindowEx(
        0,                              // 窗口样式 
        CLASS_NAME,                     // Window class
        L"Windows窗口",    				// 标题名
        WS_OVERLAPPEDWINDOW,            // 窗口主题(?) 

        // 大小和位置,这里使用的是默认 
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // 父窗口 
        NULL,       // 菜单 
        hInstance,  // 实例句柄 
        NULL        // 额外应用数据 
    );

    if(hwnd == NULL)return 0;

	//展示窗口 
    ShowWindow(hwnd, nCmdShow);

    //循环获得信息
    MSG msg = { };
    while(GetMessage(&msg, NULL, 0, 0) > 0){
		//TranslateMessage 函数与键盘输入相关
		//它将击键 (键向下、向上键) 转换为字符
		//你不必真正知道此函数的工作原理;请记得在 DispatchMessage 之前调用它
		TranslateMessage(&msg);
		//函数指示操作系统调用窗口的窗口过程,该窗口是消息的目标
		//换句话说,操作系统在其窗口表中查找窗口句柄,查找与窗口关联的函数指针,并调用 函数。
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){//回调函数
    switch (uMsg){
	    case WM_DESTROY:{
			PostQuitMessage(0);
			return 0;
		}
	        
	
	    case WM_PAINT:{
            PAINTSTRUCT ps;
			//通过调用 BeginPaint 函数启动绘制操作
            HDC hdc = BeginPaint(hwnd, &ps);
            
			//当前更新区域在 PAINTSTRUCT 的 rcPaint 成员中提供
			//第二个参数提供要填充的矩形的坐标
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			
			//所有绘画都在 BeginPaint 和 EndPaint之中完成
            EndPaint(hwnd, &ps);
			return 0;
		}
	        
		case WM_CLOSE:{
			if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK){
				DestroyWindow(hwnd);
			}
			// Else: User canceled. Do nothing.
			return 0;
		}
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
