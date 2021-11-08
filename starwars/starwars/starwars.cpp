#include <iostream>
#include "time.h"
#include <conio.h>
#include <Windows.h>
using namespace std;
void setcur(int x, int y)//установка курсора на позицию  x y 
{
	COORD coord;
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
		Black         = 0,
		Blue          = 1,
		Green         = 2,
		Cyan          = 3,
		Red           = 4,
		Magenta       = 5,
		Brown         = 6,
		LightGray     = 7,
	   &nbsp;DarkGray      = 8,
		LightBlue     = 9,
		LightGreen    = 10,
		LightCyan     = 11,
		LightRed      = 12,
		LightMagenta  = 13,
		Yellow        = 14,
		White         = 15

*/
/*

176░
177▒
178▓
179│
180┤
181╡
182╢
183╖
184╕
185╣
186║++++++++++++
187╗+++++++++++++++++++++
188╝+++++++++++++++++++
189╜
190╛
191┐
192└
193┴
194┬
195├
196─
197┼
198╞
199╟
200╚++++++++++++++++++++++++
201╔+++++++++++++++++++++
202╩++++++++++++++++++
203╦++++++++++++++
204╠
205═+++++++++++++++++++
206╬
207╧
208╨
209╤
210╥
211╙
212╘
213╒
214╓  
215╫
216╪     
217┘
218┌
219█
220▄
221▌
222▐
223▀
248°
249∙
250·
251√
252№
253¤
254■                                         BOSS
						   ██████████████████████████████████████
						   ╨╨██████████████████████████████████╨╨
							 ╨╨╨▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╨╨╨
								╨╨╨╨╨▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╨╨╨╨╨
									 ╨╨╨▒▒▒▒▒▒▒▒▒▒▒▒╨╨╨
										╨╨╨░░░░░░╨╨╨
										   ╨╨░░╨╨
											 ╠╣
											 ╨╨

*/
void logic(int *shipx, int*shipy, char **bullets, bool**enemies, int *CountOfEnemies, int *timer, int *score, bool *BossTime, int *BossLives, char **boss, int *count, char **bulletsboss, int *cboss, int *PlayerLives, int *cbosses, int *cships) {
	if (*count == 20) {
		system("cls");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		
		for (int i = 0; i < 30; i++) {
			
			if (i % 2 == 0) {
				SetConsoleTextAttribute(h, 4);
			}
			else { SetConsoleTextAttribute(h, 2); }
			setcur(i, 4);
			cout << "$$$$$___$$$$___$$$$___$$$$" << endl; setcur(i, 5);
			cout << "$$__$$_$$__$$_$$_____$$" << endl; setcur(i, 6);
			cout << "$$$$$__$$__$$__$$$$___$$$$" << endl; setcur(i, 7);
			cout << "$$__$$_$$__$$_____$$_____$$" << endl; setcur(i, 8);
			cout << "$$$$$___$$$$___$$$$___$$$$" << endl; setcur(i, 9);
		
			system("cls");
		}
		*BossTime = true; *BossLives = 100; *count = 0; 
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 40; j++) {
				enemies[i][j] = false;
			}
		}
		*CountOfEnemies = 0;
	}
	
	if (*BossTime == true&&*BossLives!=0) {
		if (*cboss < 7) {
			bulletsboss[2][1 + rand() % 37] = '*';
			*cboss += 1;
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 40; j++) {
				if (bullets[i][j] == '*' && i == 0) { bullets[i][j] = ' '; }
				if (bullets[i][j]=='*'&&boss[i-1][j]!=' '&&i!=0) {
					bullets[i][j] = ' ';
					*BossLives-=1;
					*score += 20;
				}
			}
		}
		if (*BossLives == 0) {
			*cbosses+=1; *BossTime = false; *count = 0;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 40; j++) {
				bulletsboss[i][j] = ' ';
			
			}
		}
		*cboss = 0;
		}
	}
	else {
		if (*CountOfEnemies < 7) {
			enemies[1][rand() % 38] = true;
			*CountOfEnemies += 1;
		}
	}
	if (*timer % 5 == 0) { *score += 1; }
	if (*timer % 10 == 0) {
		for (int i = 19; i >= 0; i--) {
			for (int j = 39; j >= 0; j--) {
				if (enemies[i][j] == true && ((i == *shipy - 1 && j == *shipx) || (i == *shipy - 1 && j == *shipx - 1) || (i == *shipy - 1 && j == *shipx + 1) || (i == *shipy && j == *shipx) || (i == *shipy && j == *shipx - 1) || (i == *shipy && j == *shipx + 1) || (i == *shipy + 1 && j == *shipx) || (i == *shipy + 1 && j == *shipx - 1) || (i == *shipy + 1 && j == *shipx + 1) || (i == *shipy + 1 && j == *shipx - 2) || (i == *shipy + 1 && j == *shipx + 2))) {
					enemies[i][j] = false;
					*PlayerLives -= 1;
					*CountOfEnemies -= 1;
					
				}
				if (enemies[i][j] == true && i != 19 && i != 0) {
					enemies[i][j] = false;
					enemies[i + 1][j] = true;
					
					break;
				}
				
				if (bulletsboss[i][j] == '*' && ((i == *shipy-1  && j == *shipx) || (i == *shipy-1  && j == *shipx - 1) || (i == *shipy-1 && j == *shipx + 1) || (i == *shipy  && j == *shipx) || (i == *shipy  && j == *shipx - 1) || (i == *shipy  && j == *shipx + 1) || (i == *shipy + 1 && j == *shipx) || (i == *shipy + 1 && j == *shipx - 1) || (i == *shipy+1 && j == *shipx + 1)|| (i == *shipy + 1 && j == *shipx - 2) || (i == *shipy + 1 && j == *shipx + 2))) {
					bulletsboss[i][j] = ' ';
					*PlayerLives -= 2;
					*cboss -= 1;
				}
				if (bulletsboss[i][j] == '*' && i != 19 && i != 0) {
					bulletsboss[i][j] = ' ';
					bulletsboss[i + 1][j] = '*';
					break;
				}

			}

		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (bulletsboss[18][j] == '*') { bulletsboss[18][j] = ' '; *cboss -= 1; }
		if (enemies[18][j] == true) { enemies[18][j] = false; *CountOfEnemies -= 1; }
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (enemies[i][j] == true && (bullets[i + 1][j] == '*'|| bullets[i + 1][j+1] == '*'|| bullets[i + 1][j-1] == '*')) {
				bullets[i + 1][j] = ' ';
				bullets[i + 1][j+1] = ' ';
				bullets[i + 1][j - 1] = ' '; 
				*score += 10;
				*count += 1;
				*cships += 1;
				enemies[i][j] = false;
				*CountOfEnemies -= 1;
			}
		}
	}


}
void draw(int *shipx, int *shipy, char **bullets, bool **enemies, bool *BossTime, char **boss, char **bulletsboss, int *playerlives, int *score, int* BossLives, int *cships, int *cbosses) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (i == *shipy && j == *shipx - 1) {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				cout << char(214); SetConsoleTextAttribute(h, 12); cout << char(215); SetConsoleTextAttribute(h, 9); cout<<char(183); j += 2;
			}
			else if (i == *shipy + 1 && j == *shipx - 1) {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				cout << char(204); SetConsoleTextAttribute(h, 10); cout << char(206); SetConsoleTextAttribute(h, 9); cout << char(185); j += 2;
			}
			else if (i == *shipy + 2 && j == *shipx - 2) {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 4); cout << char(213); SetConsoleTextAttribute(h, 9); cout << char(202) << char(202) << char(202); SetConsoleTextAttribute(h, 4); cout<< char(184); SetConsoleTextAttribute(h, 9); j += 4;
			}
			else if (*BossTime == true && boss[i][j]!=' ') {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 14); cout << boss[i][j];
				SetConsoleTextAttribute(h, 9);
			}
			else if (*BossTime == true && bulletsboss[i][j] != ' ') { 
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 4);
				cout << "*";
				SetConsoleTextAttribute(h, 9); }
			else if (j == 0 || j == 39 || i == 0 || i == 19) {
				cout << char(219);
			}
			else if (enemies[i][j + 1] == true) {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 4); cout << char(211) << char(215) << char(189); j += 2; 
				SetConsoleTextAttribute(h, 9);
			}
			else if (bullets[i][j] == '*') {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 14);
				cout << "*";
				SetConsoleTextAttribute(h, 9);
				bullets[i][j] = ' ';
				bullets[i - 1][j] = '*';
			}
			else cout << " ";
		}
		cout << endl;
	}
	setcur(0, 20);
	cout << char(219);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int l = *playerlives;
	for (int i = 0; i < l; i++) {
		if (l > 6) { SetConsoleTextAttribute(h, 2); }
		if (l > 3&&l<=6) { SetConsoleTextAttribute(h, 6); }
		if (l<=3) { SetConsoleTextAttribute(h, 4); }
			cout << char(219);
			SetConsoleTextAttribute(h, 9);
	}
	SetConsoleTextAttribute(h, 1);
	cout <<char(179)<<"   ";
	setcur(0, 21);
	SetConsoleTextAttribute(h, 9);
	for (int i = 0; i < 12; i++) {
		cout << char(219);
	}
	setcur(1, 22);
	SetConsoleTextAttribute(h, 2);
	cout << "H E A L T H";
	if (*BossTime == true) {
		setcur(42, 6);
		int boslives = *BossLives / 10;
		for (int i = 0; i < boslives; i++) {
			if (boslives > 6) { SetConsoleTextAttribute(h, 2); }
			if (boslives > 3 && boslives <= 6) { SetConsoleTextAttribute(h, 6); }
			if (boslives <= 3) { SetConsoleTextAttribute(h, 4); }
			cout << char(219) << char(219);
		}
		SetConsoleTextAttribute(h, 1);
		cout << char(179) << "   ";
		setcur(47, 7);
		SetConsoleTextAttribute(h, 2);
		cout << "B O S S";
	}
	else {
		setcur(42, 6);
		cout << "                                            " << endl;
		setcur(42, 7);
		cout << "                                            " << endl;
	}
	setcur(28, 20);
	SetConsoleTextAttribute(h, 2);
	cout <<"SCORE:"<< *score;
	setcur(28, 21);
	cout << "SHIPS KILLED:"<<*cships;
	setcur(28, 22);
	cout << "BOSSES KILLED:" << *cbosses;
	SetConsoleTextAttribute(h, 9);
	//cout << "y:" << *shipy <<"x:"<< *shipx;
	
}
void ShipControl(int *shipx, int *shipy, char **bullets) {
	while (_kbhit()) {
		switch (_getch())
		{
		case 'w':
			*shipy-=1; break;
		case 'a':
			*shipx-=1; break;
		case 's':
			*shipy+=1; break;
		case 'd':
			*shipx+=1; break;
		case 32:
			bullets[*shipy - 1][*shipx] = '*';
			break;
		}
	}
	if (*shipx == 37|| *shipx == 38) { *shipx = 36; }
	if (*shipx == 2|| *shipx == 1) { *shipx = 3; }
	if (*shipy == 17) { *shipy = 16; }
	if (*shipy == 0) { *shipy = 1; }
}
int  menu(COORD c, INPUT_RECORD all_events) {
	int choose=0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 9);
		setcur(10, 0);
		int ls = 10;
		for (int i = 0; i < 3; i++) {
			setcur(ls, i);
			for (int j = 0; j < 9; j++) {
				if (i == 0 || j == 0 || i == 2 || j == 8) {
					if (c.Y >= 0 && c.Y <= 2 && c.X >= 10 && c.X <= 18) {
						SetConsoleTextAttribute(h, 2);
						cout << char(219);
					}
					else { cout << char(219); }
				}
				else if (i == 1 && j == 1) {
					if (c.Y >= 0 && c.Y <= 2 && c.X >= 10 && c.X <= 18) {
						SetConsoleTextAttribute(h, 9);
						cout << "P L A Y"; SetConsoleTextAttribute(h, 9);
					}
					else { SetConsoleTextAttribute(h, 2); cout << "P L A Y"; SetConsoleTextAttribute(h, 9); }
				}
				else if (i != 1 && j != 1) cout << " ";
			}
			cout << endl;
		}
		setcur(10, 6);
		 ls = 8;
		SetConsoleTextAttribute(h, 9);
		for (int i = 0; i < 3; i++) {
			setcur(ls, i+5);
			for (int j = 0; j < 13; j++) {
				if (i == 0 || j == 0 || i == 2 || j == 12) {
					if (c.Y >= 5 && c.Y <= 7 && c.X >= 8 && c.X <= 20) {
						SetConsoleTextAttribute(h, 2);
						cout << char(219);
					}
					else { cout << char(219); }
				}
				else if (i == 1 && j == 1) {
					if (c.Y >= 5 && c.Y <= 7 && c.X >= 8 && c.X <= 20) {
						SetConsoleTextAttribute(h, 9);
							cout << "HOW TO PLAY"; SetConsoleTextAttribute(h, 9);
					}
					else { SetConsoleTextAttribute(h, 2); cout << "HOW TO PLAY"; SetConsoleTextAttribute(h, 9); }
				}
				else if (i != 1 && j != 1) cout << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(h, 9);
		setcur(10, 12);
		ls = 10;
		for (int i = 0; i < 3; i++) {
			setcur(ls, i+10);
			for (int j = 0; j < 9; j++) {
				if (i == 0 || j == 0 || i == 2 || j == 8) {
					if (c.Y >= 10 && c.Y <= 12 && c.X >= 10 && c.X <= 18) {
						SetConsoleTextAttribute(h, 2);
						cout << char(219);
					}
					else { cout << char(219); }
				}
				else if (i == 1 && j == 1) {
					if (c.Y >= 10 && c.Y <= 12 && c.X >= 10 && c.X <= 18) {
						SetConsoleTextAttribute(h, 9);
						cout << "E X I T"; SetConsoleTextAttribute(h, 9);
					}
					else { SetConsoleTextAttribute(h, 2); cout << "E X I T"; SetConsoleTextAttribute(h, 9); }
				}
				else if (i != 1 && j != 1) cout << " ";

			}
			cout << endl;
		}
		//Play 
		if (all_events.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y >= 0 && c.Y <= 3 && c.X >= 10 && c.X <= 18) {
			choose = 1;

		}
		//How to play
		if (all_events.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y >= 5 && c.Y <= 7 && c.X >= 8 && c.X <= 20) {
			choose = 2;
		
		}
		//Exit
		if (all_events.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y >= 10 && c.Y <= 12 && c.X >= 10 && c.X <= 18) {
			choose = 3;

		}
	return choose;
}
int main()
{ 
	SetConsoleTitleA("SORRY I CAN'T");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(h, &info);
	char** bullets = new char* [20];
	for (int i = 0; i < 20; i++) {
		bullets[i] = new char[40];
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			bullets[i][j]=' ';
		}
	}
	char** bulletsboss = new char* [20];
	for (int i = 0; i < 20; i++) {
		bulletsboss[i] = new char[40];
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			bulletsboss[i][j] = ' ';
		}
	}
	char** boss = new char* [20];
	for (int i = 0; i < 20; i++) {
		boss[i] = new char[40];
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			boss[i][j] = ' ';
		}
	}
	bool** enemies = new bool* [20];
	for (int i = 0; i < 20; i++) {
		enemies[i] = new bool[40];
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			enemies[i][j] = false;
		}
	}
	int CountOfDeadShips = 0;
	int CountOfDeadBosses = 0;
	int* cds = &CountOfDeadShips;
	int *cdb = &CountOfDeadBosses;
	int pll = 10;
	int* PlayerLives = &pll;
	int cou = 0;
	int* count = &cou;
	int x = 19;
	int y = 16;
	int co = 0;
	int* CountOfEnemies = &co;
	int *shipx = &x;
	int *shipy = &y;
	int sc = 0;
	int* score = &sc;
	bool bs = false;
	bool* BossTime = &bs;
	int bslives = 100;
	int* BossLives = &bslives;
	int countofbossbull = 0;
	int* CountOfBossBullets = &countofbossbull;
	for (int j = 1; j < 39; j++) {
		boss[1][j] = char(176);

	}
	boss[2][1] = char(208);
	boss[2][2] = char(208);
	boss[2][37] = char(208);
	boss[2][38] = char(208);
	for (int j = 3; j < 37; j++) {
		boss[2][j] = char(176);
	}
	boss[3][3] = char(208);
	boss[3][4] = char(208);
	boss[3][5] = char(208);
	boss[3][34] = char(208);
	boss[3][35] = char(208);
	boss[3][36] = char(208);
	for (int j = 6; j < 34; j++) {
		boss[3][j] = char(177);
	}
	boss[4][6] = char(208);
	boss[4][7] = char(208);
	boss[4][8] = char(208);
	boss[4][9] = char(208);
	boss[4][10] = char(208);
	boss[4][33] = char(208);
	boss[4][32] = char(208);
	boss[4][31] = char(208);
	boss[4][30] = char(208);
	boss[4][29] = char(208);
	for (int j = 11; j < 29; j++) {
		boss[4][j] = char(177);
	}
	boss[5][11] = char(208);
	boss[5][12] = char(208);
	boss[5][13] = char(208);
	boss[5][26] = char(208);
	boss[5][27] = char(208);
	boss[5][28] = char(208);
	for (int j = 14; j < 26; j++) {
		boss[5][j] = char(178);
	}
	boss[6][14] = char(208);
	boss[6][15] = char(208);
	boss[6][16] = char(208);
	boss[6][25] = char(208);
	boss[6][24] = char(208);
	boss[6][23] = char(208);
	for (int j = 17; j < 23; j++) {
		boss[6][j] = char(219);
	}
	boss[7][17] = char(208);
	boss[7][18] = char(208);
	boss[7][22] = char(208);
	boss[7][21] = char(208);
	for (int j = 19; j < 21; j++) {
		boss[7][j] = char(219);
	}
	boss[8][19] = char(204);
	boss[8][20] = char(185);
	boss[9][19] = char(208);
	boss[9][20] = char(208);
	srand(time(NULL));
	for (int i = 0; i < 3; i++,*CountOfEnemies+=1) {
	enemies[1][rand() % 38] = true;
	}
	//cout << *CountOfEnemies;
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // дескриптор окна для работы с мышкой
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки
	COORD c;
	DWORD a;
	INPUT_RECORD all_events;
	while (true) {
		ReadConsoleInput(hin, &all_events, 1, &a);
		c.X = all_events.Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
		c.Y = all_events.Event.MouseEvent.dwMousePosition.Y;
		int menuresult = menu(c, all_events);
		if (menuresult == 1) {
			system("cls");
			int ti = 0;
			int *timer = &ti;
			while (true) {
				Sleep(10);
				setcur(0, 0);
				draw(shipx, shipy, bullets, enemies, BossTime, boss, bulletsboss, PlayerLives, score, BossLives, cdb, cds);
				ShipControl(shipx, shipy, bullets);
				logic(shipx,shipy,bullets,enemies,CountOfEnemies, timer, score, BossTime, BossLives, boss, count, bulletsboss, CountOfBossBullets, PlayerLives, cdb, cds);
				*timer+=1;
				if (*PlayerLives <= 0) {
					system("cls");
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					for (int i = 0; i < 30; i++) {
						if (i % 2 == 0) {
							SetConsoleTextAttribute(h, 4);
						}
						else { SetConsoleTextAttribute(h, 2); }
						setcur(i, 4);
						cout << "_$$$$___$$$$__$$___$_$$$$$" << endl; setcur(i, 5);
						cout << "$$_____$$__$$_$$$_$$_$$" << endl; setcur(i, 6);
						cout << "$$_$$$_$$$$$$_$$_$_$_$$$$" << endl; setcur(i, 7);
						cout << "$$__$$_$$__$$_$$___$_$$" << endl; setcur(i, 8);
						cout << "_$$$$__$$__$$_$$___$_$$$$$" << endl; setcur(i, 9);
						cout << endl;
						setcur(i, 10);
						cout << "_$$$$__$$__$$_$$$$$__$$$$$" << endl; setcur(i, 11);
						cout << "$$__$$_$$__$$_$$_____$$__$$" << endl; setcur(i, 12);
						cout << "$$__$$_$$__$$_$$$$___$$$$$" << endl; setcur(i, 13);
						cout << "$$__$$__$$$$__$$_____$$__$$" << endl; setcur(i, 14);
						cout << "_$$$$____$$___$$$$$__$$__$$" << endl; setcur(i, 15);
						system("cls");
					}
					
					main();
				}
				/*cout <<endl<< *score;
				cout << endl << *BossLives;
				cout << endl << *count;
				cout << endl << *PlayerLives;*/
			}
		}
		if (menuresult == 2) {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 2);
				cout << "The w a s d keys are used to control your ship." << endl << "Space bar is used for shooting.Every 20 small ships destroyed, a boss will appear."<<endl<<"The lower left corner displays your health.Small ship hits take 10 % of your health." << endl<<"The boss takes 20 % of your health.The bottom right corner displays your score." << endl << "Have a nice game!";
				SetConsoleTextAttribute(h, 9);
				cout << endl;
				cout << endl;
				menuresult = 0;
				continue;
		}
		if (menuresult == 3) {
			system("cls");
			cout << "_$$$$__$$$$$__$$$$$" << endl;
			cout << "$$_____$$_____$$" << endl;
			cout << "_$$$$__$$$$___$$$$" << endl;
			cout << "____$$_$$_____$$" << endl;
			cout << "_$$$$__$$$$$__$$$$$" << endl;
			cout << endl;
			cout << "$$__$$__$$$$__$$__$$" << endl;
			cout << "_$$$$__$$__$$_$$__$$" << endl;
			cout << "__$$___$$__$$_$$__$$" << endl;
			cout << "__$$___$$__$$_$$__$$" << endl;
			cout << "__$$____$$$$___$$$$" << endl;
			cout << endl;
			cout << "$$______$$$$__$$$$$$_$$$$$__$$$$$" << endl;
			cout << "$$_____$$__$$___$$___$$_____$$__$$" << endl;
			cout << "$$_____$$$$$$___$$___$$$$___$$$$$" << endl;
			cout << "$$_____$$__$$___$$___$$_____$$__$$" << endl;
			cout << "$$$$$$_$$__$$___$$___$$$$$__$$__$$" << endl;
			break;
		}
		if (*PlayerLives <= 0) { break; }
		cout << endl;
		//cout << c.X << "  " << endl << c.Y << "  ";
	}
    return 0;
}
