#include <stdio.h>

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float wt[n], val[n], ratio[n];

    printf("Enter weights:\n");
    for(int i = 0; i < n; i++)
        scanf("%f", &wt[i]);

    printf("Enter profits:\n");
    for(int i = 0; i < n; i++)
        scanf("%f", &val[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    // Calculate Pi/Wi ratio
    for(int i = 0; i < n; i++) {
        ratio[i] = val[i] / wt[i];
    }

    // Sort items based on ratio (descending)
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                // swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap weights
                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;

                // swap profits
                temp = val[i];
                val[i] = val[j];
                val[j] = temp;
            }
        }
    }

    // Print Pi/Wi Table
    printf("\nItem\tWeight\tProfit\tP/W\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i+1, wt[i], val[i], ratio[i]);
    }

    float totalProfit = 0, totalWeight = 0;
    int count = 0;

    // Fractional Knapsack logic
    for(int i = 0; i < n; i++) {
        if(totalWeight + wt[i] <= W) {
            totalWeight += wt[i];
            totalProfit += val[i];
            count++;
        } else {
            float remain = W - totalWeight;
            totalProfit += ratio[i] * remain;
            totalWeight += remain;
            count++;
            break;
        }
    }

    printf("\nTotal Weight Used = %.2f\n", totalWeight);
    printf("Remaining Weight = %.2f\n", W - totalWeight);
    printf("Total Profit = %.2f\n", totalProfit);

    if(count > 0)
        printf("Average Profit = %.2f\n", totalProfit / count);
    else
        printf("Average Profit = 0\n");

    return 0;
}

