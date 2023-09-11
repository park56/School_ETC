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