//퀵정렬(quick sort)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t)) // swap 매크로 ()가 있어야 -도 처리됨

int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
int n = 10;

void quicksort(int arr[], int left, int right) {
	if (left >= right) {   //정렬할 데이터 수가 1인 경우
		return;
	}

	int pivot = left;    //피봇을 맨 왼쪽으로 선택
	int i = left + 1;
	int j = right;
	int temp;

	while (i <= j) {    //i가 j이하일 때까지 빠져 나왔을 땐 배열이 쪼개진 상태
		while (arr[i] <= arr[pivot])   //i위치의 값이 pivot위치의 값 이하일때
		i++;
		while (arr[j] >= arr[pivot] && j > left)
			j--; 
		if (i > j)             //i와 j가 크로스 되었을 경우
			swap(arr[j], arr[pivot], temp);
		else      //i가 j보다 작은 경우는 피봇과 교체하지 않음
			swap(arr[i], arr[j], temp);
	}

	quicksort(arr, left, j - 1);   //피봇으로 뽀개어진 왼쪽부분 호출
	quicksort(arr, j + 1, right);  //오른쪽호출
}

int main() {
	quicksort(arr, 0, n - 1); //left 0 right n-1 (배열 인덱스)

	//정렬된 결과가 출력되도록 반복문을 사용하여 배열 내용 보여주기
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}

	//퀵정렬 시간복잡도 o(nlogn), 평균속도
	//퀵정렬 시간복잡도 o(n^2)인 경우, 최악의 경우
	return 0;
}