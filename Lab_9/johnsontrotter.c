#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to find mobile integer
int getMobile(int a[], int dir[], int n) {
    int mobile = 0, mobileIndex = -1;

    for(int i = 0; i < n; i++) {

        // Moving left
        if(dir[a[i]-1] == LEFT && i != 0) {
            if(a[i] > a[i-1] && a[i] > mobile) {
                mobile = a[i];
                mobileIndex = i;
            }
        }

        // Moving right
        if(dir[a[i]-1] == RIGHT && i != n-1) {
            if(a[i] > a[i+1] && a[i] > mobile) {
                mobile = a[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

// Print permutation
void printPermutation(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {

    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    // Initialize permutation and directions
    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    int total = 1;

    // Calculate n!
    for(int i = 2; i <= n; i++) {
        total *= i;
    }

    // Generate permutations
    for(int count = 1; count < total; count++) {

        int mobileIndex = getMobile(a, dir, n);

        int mobile = a[mobileIndex];

        // Swap mobile element
        if(dir[mobile-1] == LEFT) {
            int temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex - 1];
            a[mobileIndex - 1] = temp;

            mobileIndex--;
        }
        else {
            int temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex + 1];
            a[mobileIndex + 1] = temp;

            mobileIndex++;
        }

        // Reverse direction of elements greater than mobile
        for(int i = 0; i < n; i++) {
            if(a[i] > mobile) {
                dir[a[i]-1] *= -1;
            }
        }

        printPermutation(a, n);
    }

    return 0;
}
