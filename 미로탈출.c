#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int m[9][9] =
	{    {2,2,2,2,2,2,2,2,2},//maze
		 {2,0,0,0,0,0,0,0,2},
		 {2,0,2,2,0,2,2,0,2},
		 {2,0,2,0,0,2,0,0,2},
		 {2,0,2,0,2,0,2,0,2},
		 {2.0,0,0,0,0,2,0,2},
		 {2,2,0,2,2,0,2,2,2},
		 {2,0,0,0,0,0,0,0,2},
		 {2,2,2,2,2,2,2,2,2} };
int si, sj, ei, ej, success, ind;
int ri[100], rj[100];
//s : start,  �����, e : end, ������, sp ���������� (top)
// ri, rj : ������ ���� ������ i = �� j =  
int visit(int, int);
int main()
{
	ind = 0;     //������ top ��ġ ����
	success = 0; //�̷� Ż�� ����
	printf("=== �̷� Ż�� ��� ã�� ���� ===\n");
	si = 1, sj = 1;    // ����� 
	ei = 7, ej = 7;    // ������
	if (visit(si, sj) == 0)     //(1, 1) ������� ����
		printf("�ⱸ�� ã�� �� ����\n");
	else
		printf("��� ��θ� ã����\n");
	return 0;
}
int visit(int i, int j) 
{
	static int path = 1;     //path�� ����� ã�� ����� �� �Լ��ȿ� static�� ���� �ѹ��� �ʱ�ȭ �ȴ� �� �ٲ���� ����ȴ�
	m[i][j] = 1;      //�������� �渶�� 1�� �ٲٴ°� (��ŷ)
	ri[ind] = i, rj[ind] = j;
	ind++;
	if (i == ei && j == ej) {  //�������� �������� ��
		printf("ã�� ��� %d ��\n", path++);
		for (int k = 0; k < ind; k++)
		{
			printf("(%d, %d) ", ri[k], rj[k]);
		}
			printf("\n");
			success = 1;  //��θ� ���������� ã��
	}
		//   �̷� Ž�� ���� �����@@@@

		if (m[i][j + 1] == 0)	  //right
			visit(i, j + 1);
		if (m[i + 1][j] == 0)	  //down
			visit(i, j);
		if (m[i][j - 1] == 0)     //left
			visit(i, j - 1);
		if (m[i - 1][j] == 0)     //up
			visit(i - 1, j);
		ind--;
		m[i][j] = 0;   // ������θ� ã�� ���� ��� ���󺹱� 
		return success;
}
/*#include <stdio.h>
int m[9][9] =
{	 {2,2,2,2,2,2,2,2,2},//maze
	 {2,0,0,0,0,0,0,0,2},
	 {2,0,2,2,0,2,2,0,2},
	 {2,0,2,0,0,2,0,0,2},
	 {2,0,2,0,2,0,2,0,2},
	 {2.0,0,0,0,0,2,0,2},
	 {2,2,0,2,2,0,2,2,2},
	 {2,0,0,0,0,0,0,0,2},
	 {2,2,2,2,2,2,2,2,2} };
int Si, Sj, Ei, Ej, success, top, ri[100], rj[100];
//S : Start,����� E: End, ������, sp ����������(top)
//ri, rj : ������ ���� ������ i�� ��, j�� ��
int visit(int, int);
int main() {
	top = 0;//���� ������ �ʱⰪ
	success = 0;//ó���� ���� �������� �����ϴ� �÷���
	printf("�̷� Ž���ϱ�\n");
	Si = 1, Sj = 1, Ei = 7, Ej = 7;
	//����� (1,1) ������ (7,7)
	if (visit(Si, Sj) == 0)
		printf("�ⱸ�� ã�� �� ����\n");
	else
		printf("\n");
	return 0;
}
int visit(int i, int j) {
	static int path = 1;
	m[i][j] = 1;
	ri[top] = i, rj[top] = j;//������ ��� �� ��ȣ ����
	top++;
	if (i == Ei && j == Ej) {//�������� �����ߴٸ�
		printf("ã�� ��(%d)\n", path++);
		for (int k = 0; k < top; k++)
			printf("(%d,%d) ", ri[k], rj[k]);
		printf("\n");
		success = 1;
	}
	//////�̷� Ž�� ����////////
	if (m[i][j + 1] == 0)//������
		visit(i, j + 1);
	if (m[i + 1][j] == 0)//�Ʒ���
		visit(i + 1, j);
	if (m[i][j - 1] == 0)//����
		visit(i, j - 1);
	if (m[i - 1][j] == 0)//����
		visit(i - 1, j);
	top--;//���ÿ��� �ϳ� ��
	m[i][j] = 0;//�ٸ� ��� Ž���� ����
	return success;

}*/