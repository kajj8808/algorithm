#include <stdio.h>

/* 두개의 요소의 위치를 swap 합니다. */
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int partition(int arr[], int left, int right) {
	int pivot = arr[right]; // 마지막 요소를 피봇으로 지정합니다. 값을 비교 하기 위해 사용됩니다.
	int pivotIndex = (left - 1); // 피봇의 위치 를 표시/확인 하는곳에 사용합니다. 가장 왼쪽으로 지정했습니다.

	// 마지막 pivot 이 저장된 위치(right / 배열의 마지막 위치)를 제외한 나머지 값들로 반복을 합니다.
	for (int i = left; i < right; i++) {
		if (arr[i] < pivot) {
			// 피봇이 더크다면, 피봇Index(왼쪽)의 위치에서 한칸 오른쪽의 위치와 위치를 교환합니다.
			pivotIndex++;
			swap(&arr[pivotIndex], &arr[i]);
		}
	}
	swap(&arr[pivotIndex + 1], &arr[right]);
	// pivot 을 pivotIndex 즉 반복문을 다돈후 값이 적은것을 왼쪽으로 다보낸후의 피봇의 위치에 
	// 오른쪽으로 빼놓았던 피봇의 값을 swap을 하여 넣습니다. 
	printf("partition      - ");
	printArray(arr, 12);

	return pivotIndex + 1; // pivot 의 값이 있는 현재 위치를 반환합니다. 
}

void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int pivotIndex = partition(arr, left, right);
		quickSort(arr, left, pivotIndex - 1); // 피봇보다 작은 그룹
		quickSort(arr, pivotIndex + 1, right); // 피봇보다 큰 그룹
	}
}

int main() {
	int arr[] = { 6 ,3 ,11 ,9 ,12 ,2 ,8 ,15 ,18 ,10 ,7 ,14 };
	int arrLength = (sizeof(arr) / sizeof(arr[0]));

	// quickSort 가 시작하기전 배열을 출력합니다
	printf("original array - ");
	printArray(arr, arrLength);

	quickSort(arr, 0, arrLength - 1); // 0 부터 시작해서 array 의 크기 보다 한칸 적게 사용합니다.

	// quickSort 가 끝난후 배열을 출력합니다.
	printf("sorted array   - ");
	printArray(arr, arrLength);
}