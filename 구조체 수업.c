#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
typedef struct bucket_list sb;  
struct bucket_list {
	char who[2][20]; //���� ����
	char wg[2][20]; //���������
	char wb[2][20]; //��������
	int mon[2]; //���
};
int main()
{
	sb many[2];  //��� ����
	for (int i = 0; i < 2; i++)
	{
		printf("�̸� : ");
		scanf("%s", many[i].who);
		printf("%s�� ���� ������, ��� ������, ��� :", many[i].who);
		scanf("%s%s%d\n\n\n", many[i].wg, many[i].wb, many[i].mon);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("=====%s�� ��Ŷ����Ʈ=====\n", many[i].who);
		printf("���� ������ %s\n", many[i].wg);
			printf("��� ������ %s\n", many[i].wb);
			printf("�̷� ����� %d\n", many[i].mon);
			printf("===================\n");
	}
	return 0;
}





//�����뿩 ����ü
/*typedef struct books BB;  // typedef�� �տ� ���̸� struct books �� �׳� BB��� �� �� ����
struct books {
	char name[30];    //�̸�
	char auth[30];    //������ 
	char publ[30];    //���ǻ�
	int borrowed;     //�뿩 ����
	int amount;       //������ ����
};
int main() {
	// struct books book list[3];   //��� ����
	BB book_list [3]; //��� ����
	for (int i = 0; i < 3; i++)
	{
		printf("å %d ���� �Է� : ",i);
		scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);   // ���� ����� �Է�
		book_list[i].borrowed = 0;    //������ �ȵ� ���·� ����
	}
	for (int i = 0; i < 3; i++)      //��ȸ�� ���� ���� ���
	{
		printf("======================================= \n");
		printf("������ %s �� ����\n", book_list[i].name);
		printf("���� : %s \n", book_list[i].auth);
		printf("���ǻ� : %s \n", book_list[i].publ);
		if (book_list[i].borrowed == 0) {
			printf("�Ⱥ����� \n");
		}
		else printf("������ \n");
	}
	return 0;
}*/
//���� ���� ����ü
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct me      //�������� ����ü�� ����
{
	char nam[20];    //�̸�
	int num;       //��ȣ
	int age;          //����
};                     // ����ü�� ���� p1�� ����
int main()
{
	struct me p1;
	p1.nam[0] = "�ڼ���";
	p1.num = 7;
	p1.age = 17;
	printf("�̸� : %s, ���� : %d, �й� : %d", p1.nam[0], p1.age, p1.num);
}*/
/*struct Student        //�л� ����ü�� �����
{
	char name[20];       //�̸�
	char stu_num[10];    //�й�
	int age;              //���� �� �ٰ��� ��� ���� ��  �� ����
};*/
//����ü�� ����
/*define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct point  //����ü(struct) ��   ����ü�� ������ �ٸ� �����͸� �ϳ��� ���� ��� �迭�� ����ѵ� ���� ������ �ٰ��� ���� �� ����
{
	int x, y;  // x, y�� ����ü ������ �θ�

};
int main()
{
	struct point p = { 4,5 };
	printf("x=%d, y=%d\n", p.x, p.y);
	struct point p1;
	p1.x = 5;
	p1.y = 8;
	printf("x=%d, y=%d\n", p1.x, p1.y);
	struct point myPoint[20];
	myPoint[0].x = 1;
	myPoint[0].y = 1;
	return 0;*/
//�̷� Ž��
/*#define _CRT_SECURE_NO_WARNINGS
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
}*/
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