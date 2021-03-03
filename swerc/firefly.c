#include <stdio.h>
#include <string.h>

int main() {
    int n, h;
    scanf("%i %i", &n, &h);
    
    int bottomHeights[h], topHeights[h];
    memset(bottomHeights, 0, sizeof(bottomHeights));
    memset(topHeights, 0, sizeof(topHeights));

    for (int i = 0; i < n; i++) {
        int item;
        scanf("%i", &item);

        if (i % 2 == 0) {
            // Bottom
            bottomHeights[item-1] += 1;
        } else {
            // Top
            topHeights[h-item] += 1;
        }
    }

    // Sum bottom heights
    for (int i = h-2; i >= 0; i--) {
        bottomHeights[i] += bottomHeights[i+1];
    }

    // Sum top heights
    for (int i = 1; i < h; i++) {
        topHeights[i] += topHeights[i-1];
    }

    // Sum them together
    int* heights = bottomHeights;
    for (int i = 0; i < h; i++) {
        heights[i] += topHeights[i];
    }

    int minHeight = heights[0];
    int minHeightTimes = 1;
    for (int i = 1; i < h; i++) {
        if (heights[i] < minHeight) {
            minHeight = heights[i];
            minHeightTimes = 1;
        } else if (heights[i] == minHeight) {
            minHeightTimes += 1;
        }
    }

    printf("%i %i\n", minHeight, minHeightTimes);
}