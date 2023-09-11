#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
//돈모으기
int rs = 0;
int usmoney = 2000000;

void lurlet()
{
	srand((unsigned int)time(NULL));
	int red = 0, black = 0, green = 0;   //선택
	int ch1 = 0, ch2 = 0, ch3 = 0;    //레드 블랙 그린의 확률
	int choice;   //선택
	int rs = 0;  //확률표시
	int g = 0; //배팅액
	int h = 0; //딴금액
	system("cls");
	while (ch1 == 0 && ch2 == 0 && ch3 == 0)
	{
		printf("얼마를 하시겠습니까?  (소지액 : %d)\n", usmoney);
		scanf("%d", &g);
		if (g > usmoney)
		{
			printf("현제 소유금액보다 많은 금액입니다.\n");
			Sleep(200);
			system("cls");
			continue;
		}
		usmoney -= g;
		printf("1: red 2: black 3: green 중 하나를 고르십시오\n1번과 2번은 40%%확률로 1.5배이고 실패시 현제금액에 반을 가져갑니다. 3번은 2배인 대신 실패시 모든금액을 가져갑니다.\n");
		scanf("%d", &choice);
		if (choice == 1)  ch1++;
		else if (choice == 2)  ch2++;
		else if (choice == 3)  ch3++;
		if (ch1 == 0 && ch2 == 0 && ch3 == 0)
		{
			printf("없는 번호입니다. 다시 입력해주세요\n");
			Sleep(200);
			system("cls");
			continue;
		}
	}
	system("cls");
	printf("룰렛이 돌아가는 중입니다.......");
	rs = rand() % 10 + 1;
	Sleep(4500);
	system("cls");
	if (rs <= 4 && rs > 0)
	{
		red++;
		if (ch1 == red)
		{
			h = g * 1.5;
			usmoney += h;
			printf("축하합니다. 금액에 1.5배를 얻으셨습니다.\n");
			printf("이익 : %d\n", h - g);
			printf("자산 : %d", usmoney);
		}
		else
		{
			h = g / 2;
			usmoney += h;
			printf("반을 잃으셨습니다.");
			printf("손해 : %d\n", h - g);
			printf("자산 : %d", usmoney);
		}
	}
	else if (rs <= 8)
	{
		black++;
		if (ch2 == black)
		{
			h = g * 1.5;
			usmoney += h;
			printf("축하합니다. 금액에 1.5배를 얻으셨습니다.\n");
			printf("손해 : %d\n", h - g);
			printf("자산 : %d", usmoney);
		}
		else
		{
			h = g / 2;
			usmoney += h;
			printf("반을 잃으셨습니다.");
			printf("손해 : %d\n", h - g);
			printf("자산 : %d", usmoney);
		}
	}
	else
	{
		green++;
		if (ch2 == black)
		{
			h = g * 2;
			usmoney += h;
			printf("축하합니다. 금액에 2배를 얻으셨습니다.\n");
			printf("이익 : %d\n", h - g);
			printf("자산 : %d", usmoney);
		}
		else
		{
			printf("모든 돈을 잃으셨습니다.");
			printf("자산 : %d", usmoney);
			g = 0;
		}
	}
	Sleep(4000);
	system("cls");
};
void holzzak()
{
	srand((unsigned int)time(NULL));
	int g = 0; //얼마를 할지
	int sz = 0; //주사위결과
	int h = 0, z = 0;  //홀짝 변환
	int hz = 0;   //홀짝
	int u = 0; //시작과 끝
	printf("홀짝은 미리 홀짝을 고르고 주사위를 굴려 홀과 짝이 맞으면 돈을 따는 룰입니다. 5는 꽝 6은 다시 입니다.");
	Sleep(1000);
	system("cls");
	while (u == 0)
	{
		while (h == 0 && z == 0)
		{
			printf("얼마를 하시겠습니까?  (소지액 : %d)\n", usmoney);
			scanf("%d", &g);
			if (g > usmoney)
			{
				printf("현제 소유금액보다 많은 금액입니다.\n");
				Sleep(200);
				system("cls");
				continue;
			}
			else
			{
				printf("홀(1)과 짝(2)중 고르십시오.\n");
				scanf("%d", &hz);
				if (hz == 1)
				{
					h++;
				}
				else if (hz == 2)
				{
					z++;
				}
				else
				{
					printf("홀과 짝중 선택해주십시오.");
					Sleep(1000);
					system("cls");
					continue;
				}
			}
			usmoney -= g;
		}

		system("cls");
		printf("주사위를 굴리는 중입니다.......");
		Sleep(4500);
		rs = rand() % 6 + 1;
		system("cls");
		if (hz == 1)
		{
			if (rs == 1 || rs == 3)
			{
				g *= 1.2;
				usmoney += g;
				printf("홀\n");
				printf("축하드립니다. 1.2배를 얻으셧습니다.\n");
				printf("지급액 : %d  총 자산 : %d", g, usmoney);
				u++;
			}
			if (rs == 2 || rs == 4)
			{
				g /= 1.2;
				usmoney -= g;
				printf("짝\n");
				printf("1.2배를 잃으셨습니다.\n");
				printf("손해 : %d  총 자산 : %d", g, usmoney);
				u++;
			}
			if (rs == 5)
			{
				printf("다시\n");
				continue;
			}
			if (rs == 6)
			{
				printf("꽝\n");
				g = 0;
				printf("총 자산 : %d", usmoney);
				u++;
			}
		}
		if (hz == 2)
		{
			if (rs == 1 || rs == 3)
			{
				g *= 1.2;
				usmoney += g;
				printf("홀\n");
				printf("1.2배를 잃으셨습니다.\n");
				printf("손해 : %d  총 자산 : %d", g, usmoney);
				u++;
			}
			if (rs == 2 || rs == 4)
			{
				g /= 1.2;
				usmoney -= g;
				printf("짝\n");
				printf("축하드립니다. 1.2배를 얻으셧습니다.\n");
				printf("지급액 : %d  총 자산 : %d", g, usmoney);
				u++;
			}
			if (rs == 5)
			{
				printf("다시\n");
				continue;
			}
			if (rs == 6)
			{
				printf("꽝\n");
				g = 0;
				printf("총 자산 : %d", usmoney);
				u++;
			}

		}
	}
	Sleep(4000);
	system("cls");
};
void slot()
{
	srand((unsigned int)time(NULL));
	int z = 0;   //돈이 들어왔는지
	int g = 0; //얼마 넣는지
	int o = 0, t = 0, th = 0;    //3가지 랜덤수
	printf("슬롯은 3개의 수를 7까지 무작위로 돌려 조건에 따라 보상을 얻는 구조입니다.");
	Sleep(1000);
	system("cls");
	while (z == 0)
	{
		printf("얼마를 하시겠습니까?  (소지액 : %d)\n", usmoney);
		scanf("%d", &g);
		if (g > usmoney)
		{
			printf("현제 소유금액보다 많은 금액입니다.\n");
			Sleep(200);
			system("cls");
			continue;
		}
		else 
		{
			z++;
		}
	}
	system("cls");
	usmoney -= g;
	printf("슬롯이 돌아가는 중입니다......");
	Sleep(4000);
	o = rand() % 7 + 1;
	t = rand() % 7 + 1;
	th = rand() % 7 + 1;
	system("cls");
	printf("%d %d %d\n", o, t, th);
	if (o != t && t != th && th != o)
	{
		printf("꽝\n");
		printf("모든 금액을 잃으셨습니다. 총 자산 : %d", usmoney);
	}
	else if (o == t == th)
	{
		g *= 5;
		usmoney += g;
		printf("축하드립니다.\n");
		printf("금액의 5배를 얻으셨습니다. 총 자산 : %d", usmoney);
	}
	else
	{
		g *= 2;
		usmoney += g;
		printf("축하드립니다.\n");
		printf("금액의 2배를 얻으셨습니다. 총 자산 : %d", usmoney);
	}
	Sleep(4000);
	system("cls");
}
void mainpt()
{
	printf("  총 자산 : %d                                        \n\n\n", usmoney);
	printf("         ****************************                                          \n");
	printf("                   돈모으기                                      \n");
	printf("         ****************************                                          \n");
	printf("                                                   \n");
	printf("                  1. 룰렛                                 \n\n");
	printf("                  2. 홀짝                                 \n\n");
	printf("                  3. 슬롯                                 ");
}
int main()
{
	int usmoneymax = 5000000;
	int wgam = 0;
	while (usmoney > 0 || usmoney < usmoneymax)
	{
		mainpt();
		scanf("%d", &wgam);
		if (wgam == 1)
		{
			system("cls");
			lurlet();
			continue;
		}
		else if (wgam == 2)
		{
			system("cls");
			holzzak();
			continue;
		}
		else if (wgam == 3)
		{
			system("cls");
			slot();
			continue;
		}
		else
		{
			continue;
		}
	}
	printf("게임이 종료되었습니다. 감사합니다");
}





