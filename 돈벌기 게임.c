#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
//��������
int rs = 0;
int usmoney = 2000000;

void lurlet()
{
	srand((unsigned int)time(NULL));
	int red = 0, black = 0, green = 0;   //����
	int ch1 = 0, ch2 = 0, ch3 = 0;    //���� �� �׸��� Ȯ��
	int choice;   //����
	int rs = 0;  //Ȯ��ǥ��
	int g = 0; //���þ�
	int h = 0; //���ݾ�
	system("cls");
	while (ch1 == 0 && ch2 == 0 && ch3 == 0)
	{
		printf("�󸶸� �Ͻðڽ��ϱ�?  (������ : %d)\n", usmoney);
		scanf("%d", &g);
		if (g > usmoney)
		{
			printf("���� �����ݾ׺��� ���� �ݾ��Դϴ�.\n");
			Sleep(200);
			system("cls");
			continue;
		}
		usmoney -= g;
		printf("1: red 2: black 3: green �� �ϳ��� ���ʽÿ�\n1���� 2���� 40%%Ȯ���� 1.5���̰� ���н� �����ݾ׿� ���� �������ϴ�. 3���� 2���� ��� ���н� ���ݾ��� �������ϴ�.\n");
		scanf("%d", &choice);
		if (choice == 1)  ch1++;
		else if (choice == 2)  ch2++;
		else if (choice == 3)  ch3++;
		if (ch1 == 0 && ch2 == 0 && ch3 == 0)
		{
			printf("���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���\n");
			Sleep(200);
			system("cls");
			continue;
		}
	}
	system("cls");
	printf("�귿�� ���ư��� ���Դϴ�.......");
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
			printf("�����մϴ�. �ݾ׿� 1.5�踦 �����̽��ϴ�.\n");
			printf("���� : %d\n", h - g);
			printf("�ڻ� : %d", usmoney);
		}
		else
		{
			h = g / 2;
			usmoney += h;
			printf("���� �����̽��ϴ�.");
			printf("���� : %d\n", h - g);
			printf("�ڻ� : %d", usmoney);
		}
	}
	else if (rs <= 8)
	{
		black++;
		if (ch2 == black)
		{
			h = g * 1.5;
			usmoney += h;
			printf("�����մϴ�. �ݾ׿� 1.5�踦 �����̽��ϴ�.\n");
			printf("���� : %d\n", h - g);
			printf("�ڻ� : %d", usmoney);
		}
		else
		{
			h = g / 2;
			usmoney += h;
			printf("���� �����̽��ϴ�.");
			printf("���� : %d\n", h - g);
			printf("�ڻ� : %d", usmoney);
		}
	}
	else
	{
		green++;
		if (ch2 == black)
		{
			h = g * 2;
			usmoney += h;
			printf("�����մϴ�. �ݾ׿� 2�踦 �����̽��ϴ�.\n");
			printf("���� : %d\n", h - g);
			printf("�ڻ� : %d", usmoney);
		}
		else
		{
			printf("��� ���� �����̽��ϴ�.");
			printf("�ڻ� : %d", usmoney);
			g = 0;
		}
	}
	Sleep(4000);
	system("cls");
};
void holzzak()
{
	srand((unsigned int)time(NULL));
	int g = 0; //�󸶸� ����
	int sz = 0; //�ֻ������
	int h = 0, z = 0;  //Ȧ¦ ��ȯ
	int hz = 0;   //Ȧ¦
	int u = 0; //���۰� ��
	printf("Ȧ¦�� �̸� Ȧ¦�� ���� �ֻ����� ���� Ȧ�� ¦�� ������ ���� ���� ���Դϴ�. 5�� �� 6�� �ٽ� �Դϴ�.");
	Sleep(1000);
	system("cls");
	while (u == 0)
	{
		while (h == 0 && z == 0)
		{
			printf("�󸶸� �Ͻðڽ��ϱ�?  (������ : %d)\n", usmoney);
			scanf("%d", &g);
			if (g > usmoney)
			{
				printf("���� �����ݾ׺��� ���� �ݾ��Դϴ�.\n");
				Sleep(200);
				system("cls");
				continue;
			}
			else
			{
				printf("Ȧ(1)�� ¦(2)�� ���ʽÿ�.\n");
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
					printf("Ȧ�� ¦�� �������ֽʽÿ�.");
					Sleep(1000);
					system("cls");
					continue;
				}
			}
			usmoney -= g;
		}

		system("cls");
		printf("�ֻ����� ������ ���Դϴ�.......");
		Sleep(4500);
		rs = rand() % 6 + 1;
		system("cls");
		if (hz == 1)
		{
			if (rs == 1 || rs == 3)
			{
				g *= 1.2;
				usmoney += g;
				printf("Ȧ\n");
				printf("���ϵ帳�ϴ�. 1.2�踦 �����˽��ϴ�.\n");
				printf("���޾� : %d  �� �ڻ� : %d", g, usmoney);
				u++;
			}
			if (rs == 2 || rs == 4)
			{
				g /= 1.2;
				usmoney -= g;
				printf("¦\n");
				printf("1.2�踦 �����̽��ϴ�.\n");
				printf("���� : %d  �� �ڻ� : %d", g, usmoney);
				u++;
			}
			if (rs == 5)
			{
				printf("�ٽ�\n");
				continue;
			}
			if (rs == 6)
			{
				printf("��\n");
				g = 0;
				printf("�� �ڻ� : %d", usmoney);
				u++;
			}
		}
		if (hz == 2)
		{
			if (rs == 1 || rs == 3)
			{
				g *= 1.2;
				usmoney += g;
				printf("Ȧ\n");
				printf("1.2�踦 �����̽��ϴ�.\n");
				printf("���� : %d  �� �ڻ� : %d", g, usmoney);
				u++;
			}
			if (rs == 2 || rs == 4)
			{
				g /= 1.2;
				usmoney -= g;
				printf("¦\n");
				printf("���ϵ帳�ϴ�. 1.2�踦 �����˽��ϴ�.\n");
				printf("���޾� : %d  �� �ڻ� : %d", g, usmoney);
				u++;
			}
			if (rs == 5)
			{
				printf("�ٽ�\n");
				continue;
			}
			if (rs == 6)
			{
				printf("��\n");
				g = 0;
				printf("�� �ڻ� : %d", usmoney);
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
	int z = 0;   //���� ���Դ���
	int g = 0; //�� �ִ���
	int o = 0, t = 0, th = 0;    //3���� ������
	printf("������ 3���� ���� 7���� �������� ���� ���ǿ� ���� ������ ��� �����Դϴ�.");
	Sleep(1000);
	system("cls");
	while (z == 0)
	{
		printf("�󸶸� �Ͻðڽ��ϱ�?  (������ : %d)\n", usmoney);
		scanf("%d", &g);
		if (g > usmoney)
		{
			printf("���� �����ݾ׺��� ���� �ݾ��Դϴ�.\n");
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
	printf("������ ���ư��� ���Դϴ�......");
	Sleep(4000);
	o = rand() % 7 + 1;
	t = rand() % 7 + 1;
	th = rand() % 7 + 1;
	system("cls");
	printf("%d %d %d\n", o, t, th);
	if (o != t && t != th && th != o)
	{
		printf("��\n");
		printf("��� �ݾ��� �����̽��ϴ�. �� �ڻ� : %d", usmoney);
	}
	else if (o == t == th)
	{
		g *= 5;
		usmoney += g;
		printf("���ϵ帳�ϴ�.\n");
		printf("�ݾ��� 5�踦 �����̽��ϴ�. �� �ڻ� : %d", usmoney);
	}
	else
	{
		g *= 2;
		usmoney += g;
		printf("���ϵ帳�ϴ�.\n");
		printf("�ݾ��� 2�踦 �����̽��ϴ�. �� �ڻ� : %d", usmoney);
	}
	Sleep(4000);
	system("cls");
}
void mainpt()
{
	printf("  �� �ڻ� : %d                                        \n\n\n", usmoney);
	printf("         ****************************                                          \n");
	printf("                   ��������                                      \n");
	printf("         ****************************                                          \n");
	printf("                                                   \n");
	printf("                  1. �귿                                 \n\n");
	printf("                  2. Ȧ¦                                 \n\n");
	printf("                  3. ����                                 ");
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
	printf("������ ����Ǿ����ϴ�. �����մϴ�");
}





