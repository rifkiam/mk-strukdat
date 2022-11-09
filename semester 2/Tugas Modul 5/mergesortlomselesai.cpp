#include <stdio.h>
#include <stdlib.h>

/*
void mergeSort(int arr[], int s, int t, int u) {

    int i;
    int j;

    //for indexing
    int index1 =  - ;
    int index2 =  - ;
    printf("%d %d", index1, index2);

    int part1[index1];
    int part2[index2];

}
*/

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int s = sizeof(arr)/sizeof(arr[0]);
    int t = (sizeof(arr)/2)/sizeof(arr[0]);
    int u = 0;

    //mergeSort(arr, s, t, u);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}