#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_CITIES 10
int n; 
int graph[MAX_CITIES][MAX_CITIES]; 
int dp[MAX_CITIES][1 << MAX_CITIES]; 
int path[MAX_CITIES][1 << MAX_CITIES]; 
int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int mask, int current) {
    if (mask == (1 << n) - 1) {
        path[current][mask] = 0;
        return graph[current][0];
    }
    if (dp[current][mask] != -1) {
        return dp[current][mask];
    }
    int ans = INT_MAX;
    int nextCity = -1;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) { 
            int newMask = mask | (1 << i);
            int temp = graph[current][i] + tsp(newMask, i);
            if (temp < ans) {
                ans = temp;
                nextCity = i;
            }
        }
    }
    path[current][mask] = nextCity;
    return dp[current][mask] = ans;
}
void printPath() {
    int mask = 1;
    int current = 0;
    printf("Path: 1 -> "); 

    for (int step = 0; step < n - 1; step++) {
        int nextCity = path[current][mask];
        printf("%d -> ", nextCity + 1);
        mask |= (1 << nextCity);
        current = nextCity;
    }

    printf("1\n"); 
}

int main() {
    printf("Enter the number of cities (<= %d): ", MAX_CITIES);
    scanf("%d", &n);
    if (n > MAX_CITIES) {
        printf("Number of cities exceeds the maximum limit.");
        return 1;
    }
    printf("Enter the adjacency matrix for the cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }
    int ans = tsp(1, 0); 
    printf("Minimum cost of visiting all cities: %d\n", ans);
    printf("Path: ");
    printPath();
    return 0;
}

