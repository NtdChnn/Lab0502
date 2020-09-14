#include<stdio.h>
#include<windows.h>
#include<conio.h>
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); setcolor(2, 4); printf("<-0->");
}
void delete_ship(int x, int y)
{
	gotoxy(x, y); setcolor(0, 0); printf("      ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ammo(int x, int y)
{
	gotoxy(x += 2,--y); setcolor(2, 0); printf("^");
}
void delete_ammo(int x, int y)
{
	gotoxy(x +=2 , --y); setcolor(0, 0); printf(" ");
}

int main()
{
	setcursor(0);
	int x1 = 38,x2 = 38, y1 = 20 ,y2 = 20, i = 0,k = 0;
	draw_ship(x1, y1);
	char ch = '.';
	do {
		if (_kbhit()) {
			fflush(stdin);
			ch = _getch();
			if (ch == 'a') { i = 1;}
			if (ch == 'd') { i = 2;}
			if (ch == 's') { i = 0;}
			if (ch == ' ') { k = 1;}
		}
		if (i == 1 && x1 > 0) { delete_ship(x1, y1); draw_ship(--x1, y1); }
		if (i == 2 && x1 < 75){ delete_ship(x1, y1); draw_ship(++x1, y1); }
		if (k == 0) { x2 = x1; }
		if (k == 1 && y2 > 0) { delete_ammo(x2, y2); draw_ammo(x2, --y2); }
		if (y2 == 1) { delete_ammo(x2, y2); k = 0; y2 = y1; }
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
