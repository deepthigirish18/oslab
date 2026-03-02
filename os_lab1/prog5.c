#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Array should contain at least two elements.\n");
        return 0;
    }
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int largest = arr[0];
    int secondLargest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    if (largest == secondLargest) {
        printf("No second largest element found (all elements may be equal).\n");
    } else {
        printf("Second largest element = %d\n", secondLargest);
    }
    return 0;
}
