#include <stdio.h>
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if(n < 2) {
        printf("Array must have at least 2 elements.\n");
        return 0;
    }
    int arr[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int smallest = arr[0];
    int secondSmallest = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    for(i = 0; i < n; i++) {
        if(arr[i] > smallest) {
            secondSmallest = arr[i];
            break;
        }
    }
    for(i = 0; i < n; i++) {
        if(arr[i] > smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }
    if(smallest == secondSmallest)
        printf("No second smallest element.\n");
    else
        printf("Second smallest element is: %d\n", secondSmallest);
    return 0;
}
