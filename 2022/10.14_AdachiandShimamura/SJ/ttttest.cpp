#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;



typedef struct Node
{
	int Data[2];             //数据域
	struct Node *next;     //指针域
}Snake;
Snake * NewSnake(){//初始化蛇
	Snake *head, *p,*tail;
	head = (Snake*)malloc(sizeof(Snake));
	p = (Snake*)malloc(sizeof(Snake));
	tail = (Snake*)malloc(sizeof(Snake));
	if (head == NULL || p == NULL || tail == NULL)
		return head;
	head->Data[0] = 10;
	head->Data[1] = 10;
	p->Data[0] = 11;
	p->Data[1] = 10;
	tail->Data[0] = 12;
	tail->Data[1] = 10;
	head->next = p;
	p->next = tail;
	tail->next = NULL;
	return head;
}
void PrintSnake(Snake *head,int Map[20][20])
{//载入地图
	Snake* p = head;
	if (p != NULL){
		while (p != NULL)
		{
			Map[p->Data[0]][p->Data[1]] = 2;
			p = p->next;
		}
	}
}
void Move(Snake * head,bool & GameState, int Map[20][20], int cx, int cy){
	//改变方向，刷新数据
	Snake *one = head;
	Snake *two = (Snake*)malloc(sizeof(Snake));
	two->Data[0] = one->Data[0];
	two->Data[1] = one->Data[1];
	two->next = one->next;
	one->Data[0] += cx;
	one->Data[1] += cy;
	one->next = two;

	if (Map[one->Data[0]][one->Data[1]] == 3)
	{//如果吃到豆子，则产生新的豆子
		Map[one->Data[0]][one->Data[1]] = 2;
		while (true)
		{
			int Dx = rand() % 20;
			int Dy = rand() % 20;
			if (Map[Dx][Dy] == 0){
				Map[Dx][Dy] = 3;
				break;
			}
		}
		
	}
	else if (Map[one->Data[0]][one->Data[1]] == 0)
	{//什么都没有吃到
		Map[one->Data[0]][one->Data[1]] = 2;
		Snake *delone, *deltwo;
		delone = one;
		deltwo = one->next;
		while (deltwo->next != NULL){
		delone = deltwo;
		deltwo = delone->next;
		}
		Map[deltwo->Data[0]][deltwo->Data[1]] = 0;
		free(deltwo);
		delone->next = NULL;
	}
	else{//吃到墙壁或是自己
		GameState = false; 
	}
}
void MapPrint(int Map[20][20]){
	//绘制地图
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (Map[i][j] == 0){ cout << "  "; }
			else if (Map[i][j] == 1){ cout << "■"; }
			else if (Map[i][j] == 2){ cout << "●"; }
			else if (Map[i][j] == 3){ cout << "★"; }
		}
		cout << endl;
	}
}

int main(){
	HANDLE hOutput;
	COORD coord = { 0, 0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hOutBuf = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
		);
	SetConsoleActiveScreenBuffer(hOutBuf);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutBuf, &cci);
	DWORD bytes = 100;
	char data[1600];
	while(1){
		int a;
		cin>>a;
		cout<<a<<endl;
		ReadConsoleOutputCharacterA(hOutput, data, 1600, coord, &bytes);
		WriteConsoleOutputCharacterA(hOutBuf, data, 1600, coord, &bytes);
		system("cls");
	}
	ReadConsoleOutputCharacterA(hOutput, data, 1600, coord, &bytes);
	WriteConsoleOutputCharacterA(hOutBuf, data, 1600, coord, &bytes);
	system("pause");
}


