#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
typedef struct bucket_list sb;  
struct bucket_list {
	char who[2][20]; //누구 인지
	char wg[2][20]; //가고싶은곳
	char wb[2][20]; //사고싶은것
	int mon[2]; //재산
};
int main()
{
	sb many[2];  //목록 선언
	for (int i = 0; i < 2; i++)
	{
		printf("이름 : ");
		scanf("%s", many[i].who);
		printf("%s의 가고 싶은곳, 사고 싶은것, 재산 :", many[i].who);
		scanf("%s%s%d\n\n\n", many[i].wg, many[i].wb, many[i].mon);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("=====%s의 버킷리스트=====\n", many[i].who);
		printf("가고 싶은곳 %s\n", many[i].wg);
			printf("사고 싶은것 %s\n", many[i].wb);
			printf("미래 전재산 %d\n", many[i].mon);
			printf("===================\n");
	}
	return 0;
}





//도서대여 구조체
/*typedef struct books BB;  // typedef를 앞에 붙이면 struct books 를 그냥 BB라고 할 수 있음
struct books {
	char name[30];    //이름
	char auth[30];    //저작자 
	char publ[30];    //출판사
	int borrowed;     //대여 여부
	int amount;       //구입한 수량
};
int main() {
	// struct books book list[3];   //목록 선언
	BB book_list [3]; //목록 선언
	for (int i = 0; i < 3; i++)
	{
		printf("책 %d 정보 입력 : ",i);
		scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);   // 각각 띄어쓰기로 입력
		book_list[i].borrowed = 0;    //대출이 안된 상태로 설정
	}
	for (int i = 0; i < 3; i++)      //순회를 통해 정보 출력
	{
		printf("======================================= \n");
		printf("저자의 %s 의 정보\n", book_list[i].name);
		printf("저자 : %s \n", book_list[i].auth);
		printf("출판사 : %s \n", book_list[i].publ);
		if (book_list[i].borrowed == 0) {
			printf("안빌려짐 \n");
		}
		else printf("빌려짐 \n");
	}
	return 0;
}*/
//나에 대한 구조체
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct me      //나에대한 구조체를 생성
{
	char nam[20];    //이름
	int num;       //번호
	int age;          //나이
};                     // 구조체에 대한 p1을 만듬
int main()
{
	struct me p1;
	p1.nam[0] = "박성한";
	p1.num = 7;
	p1.age = 17;
	printf("이름 : %s, 나이 : %d, 학번 : %d", p1.nam[0], p1.age, p1.num);
}*/
/*struct Student        //학생 구조체를 만들면
{
	char name[20];       //이름
	char stu_num[10];    //학번
	int age;              //나이 를 다같이 묶어서 관리 할  수 있음
};*/
//구조체에 대해
/*define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct point  //구조체(struct) 점   구조체란 종류가 다른 데이터를 하나로 묶는 방법 배열과 비슷한데 여러 종류를 다같이 묶을 수 있음
{
	int x, y;  // x, y는 구조체 멤버라고 부름

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
//미로 탐색
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
//s : start,  출발점, e : end, 도착점, sp 스택포인터 (top)
// ri, rj : 지나간 길을 저장함 i = 행 j =
int visit(int, int);
int main()
{
	ind = 0;     //스택의 top 위치 저장
	success = 0; //미로 탈출 여부
	printf("=== 미로 탈출 경로 찾기 게임 ===\n");
	si = 1, sj = 1;    // 출발점
	ei = 7, ej = 7;    // 도착점
	if (visit(si, sj) == 0)     //(1, 1) 출발점과 같음
		printf("출구를 찾을 수 없음\n");
	else
		printf("모든 경로를 찾았음\n");
	return 0;
}
int visit(int i, int j)
{
	static int path = 1;     //path는 제대로 찾은 경로의 수 함수안에 static을 쓰면 한번만 초기화 된다 즉 바뀐수가 저장된다
	m[i][j] = 1;      //지나가는 길마다 1로 바꾸는것 (마킹)
	ri[ind] = i, rj[ind] = j;
	ind++;
	if (i == ei && j == ej) {  //도착점에 도착했을 때
		printf("찾은 경로 %d 번\n", path++);
		for (int k = 0; k < ind; k++)
		{
			printf("(%d, %d) ", ri[k], rj[k]);
		}
			printf("\n");
			success = 1;  //경로를 성공적으로 찾음
	}
		//   미로 탐색 로직 만들기@@@@

		if (m[i][j + 1] == 0)	  //right
			visit(i, j + 1);
		if (m[i + 1][j] == 0)	  //down
			visit(i, j);
		if (m[i][j - 1] == 0)     //left
			visit(i, j - 1);
		if (m[i - 1][j] == 0)     //up
			visit(i - 1, j);
		ind--;
		m[i][j] = 0;   // 다음경로를 찾기 위한 경로 원상복귀
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
//S : Start,출발점 E: End, 도착점, sp 스택포인터(top)
//ri, rj : 지나간 길을 저장함 i는 행, j는 열
int visit(int, int);
int main() {
	top = 0;//스택 포인터 초기값
	success = 0;//처음엔 성공 못했음을 저장하는 플래그
	printf("미로 탐색하기\n");
	Si = 1, Sj = 1, Ei = 7, Ej = 7;
	//출발점 (1,1) 도착점 (7,7)
	if (visit(Si, Sj) == 0)
		printf("출구를 찾을 수 없음\n");
	else
		printf("\n");
	return 0;
}
int visit(int i, int j) {
	static int path = 1;
	m[i][j] = 1;
	ri[top] = i, rj[top] = j;//지나간 행과 열 번호 저장
	top++;
	if (i == Ei && j == Ej) {//도착점에 도착했다면
		printf("찾은 길(%d)\n", path++);
		for (int k = 0; k < top; k++)
			printf("(%d,%d) ", ri[k], rj[k]);
		printf("\n");
		success = 1;
	}
	//////미로 탐색 로직////////
	if (m[i][j + 1] == 0)//오른쪽
		visit(i, j + 1);
	if (m[i + 1][j] == 0)//아래쪽
		visit(i + 1, j);
	if (m[i][j - 1] == 0)//왼쪽
		visit(i, j - 1);
	if (m[i - 1][j] == 0)//위쪽
		visit(i - 1, j);
	top--;//스택에서 하나 뺌
	m[i][j] = 0;//다른 경로 탐색을 위해
	return success;

}*/