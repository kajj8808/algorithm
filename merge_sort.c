#include <stdio.h>
/** merge 정렬을 하기위해 사용합니다.
 * arr => 원본 배열
 * left=>첫 번째 배열의 시작 index
 * center=> 첫 번째 배열의 끝 index
 * right => 두번째 배열의 끝 index
 */
void merge(int arr[], int left, int center, int right)
{
    int i, j, k;

    // 결과 값을 임시로 저장하기 위해 사용합니다.
    int temp[right - left + 1];

    i = left;       // 첫번쨰 배열의 index
    j = center + 1; // 두번째 배열의 index // center 이후의 즉 반으로 자른 두번째 배열 시작하는 index
    k = 0;          // 결과 배열(temp)의 index

    /*
        분할 된(재귀) 를 합치기(합병) 위해 루프를 돕니다.
        즉 첫번째 벼왈과 두 번째 배열을 동시에 루프합니다.
    */
    while (i <= center && j <= right)
    {
        /* code */
        if (arr[i] <= arr[j]) // 첫번째 배열의 값과 두번째 배열의 값을 비교합니다..
        {
            temp[k] = arr[i]; // 첫번째 배열의 크기가 더 작을경우 배열의 k 위치에 저장합니다.
            // k 와 i 를 증가시켜 다음 인덱스를 탐색합니다.
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j]; // 두번째 배열의 크기가 더 작을경우 배열의 k 위치에 저장합니다.
            // k 와 j 를 증가시켜 다음 인덱스를 탐색합니다.
            k++;
            j++;
        }
    }

    // 첫번째 배열에 값이 남아있으면 결과 배열에 저장/옮겨 담습니다.
    while (i <= center)
    {
        temp[k] = arr[i];
        // 옮긴 다음 증감시켜 남은 값들을 모두 결과 배열에 넣습니다.
        k++;
        i++;
    }

    // 마찬가지로 두번쨰 배열에 값이 남아있으면 결과 배열에 저장/옮겨 담습니다.
    while (j <= right)
    {
        temp[k] = arr[j];
        // 옮긴 다음 증감시켜 남은 값들을 모두 결과 배열에 넣습니다.
        k++;
        j++;
    }

    // 결과 배열의 값을 arr 원본 배열에 넣습니다.
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }
}

//
void mergeSort(int arr[], int left, int right)
{
    int center;

    /*
        배열의 원소의 수가 2개 이상일떄
        재귀 호출을 하여 하나하나 쌓아두고 실행합니다.
    */
    if (left < right)
    {
        // arr 를 반으로 나누기 위한 중간 인덱스
        center = (left + right) / 2; // center 으로 잘라 더 안잘라 질떄까지 돕니다.
        // 중간값 center 를 기준으로 앞부분 을 잘라내 다시 호출(재귀호출)합니다.
        mergeSort(arr, left, center);
        // 중간값 center 를 기준으로 뒷부분 을 잘라내 다시 호출(재귀호출)합니다.
        mergeSort(arr, center + 1, right);
        merge(arr, left, center, right);
    }
}

int main()
{
    int a[10] = {37, 10, 22, 30, 35, 13, 25, 24};

    printf("margeSort 를 진행 하기 전 배열의 값입니다. \n");
    for (int i = 0; i <= 7; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    mergeSort(a, 0, 7);

    printf("margeSort 를 진행한 후 배열의 값입니다. \n");
    for (int i = 0; i <= 7; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
