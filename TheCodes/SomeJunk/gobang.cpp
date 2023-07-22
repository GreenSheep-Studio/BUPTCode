#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <position.h>
#include <graphics.h>



#define LONG	19
#define WIDE	19
#define SIZE	30

int goboard[LONG][WIDE];
int w = 1;
IMAGE img[5];


void Borngoboard()
{
	initgraph(LONG * SIZE, WIDE * SIZE, SHOWCONSOLE);

	loadimage(&img[0], L"./五子棋素材/1.png", SIZE, SIZE);
	loadimage(&img[1], L"./五子棋素材/2.png", SIZE, SIZE);
	loadimage(&img[2], L"./五子棋素材/3.png", SIZE, SIZE);
	loadimage(&img[3], L"./五子棋素材/BW.png", WIDE * SIZE, LONG * SIZE);
	loadimage(&img[4], L"./五子棋素材/WW.png", WIDE * SIZE, LONG * SIZE);

	for (int i = 0; i < LONG; i++)
	{
		for (int j = 0; j < WIDE; j++)
		{
			goboard[i][j] = 0;
		}
	}
}

void SetGame()
{
	for (int i = 0; i < LONG; i++)
	{
		for (int j = 0; j < WIDE; j++)
		{
			if (goboard[i][j] == 0) putimage(j*SIZE, i *SIZE, &img[0]);
			else if (goboard[i][j] == 1) putimage(j*SIZE, i *SIZE, &img[1]);
			else if (goboard[i][j] == -1) putimage(j*SIZE, i *SIZE, &img[2]);
		}
	}
}

int WinIf(int e, int f)
{
	int w1 = 1;
	int w2 = 1;
	int w3 = 1;
	int w4 = 1;

	for (int i = e + 1;; i++)
	{
		if (goboard[i][f] == goboard[e][f]) w1++;
		else if (goboard[i][f] != goboard[e][f]) break;
	}
	for (int i = e - 1;; i--)
	{
		if (goboard[i][f] == goboard[e][f]) w1++;
		else if (goboard[i][f] != goboard[e][f]) break;
	}
	for (int i = f + 1;; i++)
	{
		if (goboard[e][i] == goboard[e][f]) w2++;
		else if (goboard[e][i] != goboard[e][f]) break;
	}
	for (int i = f - 1;; i--)
	{
		if (goboard[e][i] == goboard[e][f]) w2++;
		else if (goboard[e][i] != goboard[e][f]) break;
	}
	int a = e + 1;
	int b = f - 1;
	do
	{
		if (goboard[a][b] == goboard[e][f])
		{
			w3++;
			a++;
			b--;
		}
		else if (goboard[a][b] != goboard[e][f]) break;
	} while (w != 0);
	int c = e - 1;
	int d = f + 1;
	do
	{
		if (goboard[c][d] == goboard[e][f])
		{
			w3++;
			c--;
			d++;
		}
		else if (goboard[c][d] != goboard[e][f]) break;
	} while (w != 0);
	int p = e + 1;
	int q = f + 1;
	do
	{
		if (goboard[p][q] == goboard[e][f])
		{
			w4++;
			p++;
			q++;
		}
		else if (goboard[p][q] != goboard[e][f]) break;
	} while (w != 0);
	int m = e - 1;
	int n = f - 1;
	do
	{
		if (goboard[m][n] == goboard[e][f])
		{
			w4++;
			m--;
			n--;
		}
		else if (goboard[m][n] != goboard[e][f]) break;
	} while (w != 0);

	if (w1 == 5 || w2 == 5 || w3 == 5 || w4 == 5) return 0;
	else return 1;
}

void main()
{
	int g;
	Borngoboard();
	SetGame();
	int wb = 0;
	int ww = 0;
	while (1)
	{
		int n = 1;
		int hand = 0;
		printf("NOW SCORE:\n");
		printf("Black Score:%d\nWhite Score:%d\n", wb, ww);
		Borngoboard();
		SetGame();
		do
		{
			MOUSEMSG msg = { 0 };
			msg = GetMouseMsg();

			if (hand == 0)
			{
				if (msg.uMsg == WM_LBUTTONDOWN)
				{
					int w1 = 1;
					if (goboard[msg.y / SIZE][msg.x / SIZE] == 0)
					{
						goboard[msg.y / SIZE][msg.x / SIZE] = 1;
					}
					int x = msg.y / SIZE;
					int y = msg.x / SIZE;
					n = WinIf(x, y);
					if (n == 0)
					{
						wb++;
						putimage(1, 1, &img[3]);
						Sleep(2000);
						break;
					}
					hand = 1;
				}
			}

			else if (hand == 1)
			{
				if (msg.uMsg == WM_RBUTTONDOWN)
				{
					if (goboard[msg.y / SIZE][msg.x / SIZE] == 0)
					{
						goboard[msg.y / SIZE][msg.x / SIZE] = -1;
					}
					int x = msg.y / SIZE;
					int y = msg.x / SIZE;
					n = WinIf(x, y);
					if (n == 0)
					{
						ww++;
						putimage(1, 1, &img[4]);
						Sleep(2000);
						break;
					}
					hand = 0;
				}
			}

			SetGame();
		} while (n != 0);
		system("cls");
		printf("NOW SCORE:\n");
		printf("Black Score:%d\nWhite Score:%d\n", wb, ww);
		printf("Whether to continue\n");
		printf("Yes press 1  NO press 0\n");
		scanf_s("%d", &g);
		if (g == 0) break;
		system("cls");
	}

}