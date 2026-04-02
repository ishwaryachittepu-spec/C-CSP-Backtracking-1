//Australia map colouring
#include <stdio.h>
#include <stdbool.h>

#define N 7
#define COLORS 3

char *regions[] = {"WA","NT","SA","Q","NSW","V","T"};

int graph[N][N] = {
    // WA NT SA Q NSW V T
    {0, 1, 1, 0, 0, 0, 0}, // WA
    {1, 0, 1, 1, 0, 0, 0}, // NT
    {1, 1, 0, 1, 1, 1, 0}, // SA
    {0, 1, 1, 0, 1, 0, 0}, // Q
    {0, 0, 1, 1, 0, 1, 0}, // NSW
    {0, 0, 1, 0, 1, 0, 0}, // V
    {0, 0, 0, 0, 0, 0, 0}  // T
};

int colorNames[] = {1,2,3};

bool isSafe(int node, int color[], int c) {
    for(int i=0;i<N;i++) {
        if(graph[node][i] && color[i] == c)
            return false;
    }
    return true;
}

bool solve(int node, int color[]) {
    if(node == N)
        return true;

    for(int c=1;c<=COLORS;c++) {
        if(isSafe(node, color, c)) {
            color[node] = c;
            if(solve(node+1, color))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    int color[N] = {0};

    if(solve(0, color)) {
        printf("Australia Map Coloring:\n");
        for(int i=0;i<N;i++) {
            printf("%s -> Color %d\n", regions[i], color[i]);
        }
    } else {
        printf("No solution\n");
    }
}
