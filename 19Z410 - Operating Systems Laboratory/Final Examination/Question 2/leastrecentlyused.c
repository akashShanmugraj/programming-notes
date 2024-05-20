#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int identifier;
    bool isinmemory;
    int lastaccessedcycle; 
} Page;

void LRU(int pagereferences[], int numberofpagereferences, int availableframes) {
    Page *memory = malloc(availableframes * sizeof(Page));

    for (int i = 0; i < availableframes; ++i) {
        memory[i].identifier = -1;
        memory[i].isinmemory = false;
        memory[i].lastaccessedcycle = 0; 
    }
    int totalhits = 0;
    int totalfaults = 0;
    int time = 1; 
    for (int pagereference = 0; pagereference < numberofpagereferences; ++pagereference) {
        bool hit = false;
        for (int frameindex = 0; frameindex < availableframes; ++frameindex) {
            if (memory[frameindex].identifier == pagereferences[pagereference]) {
                memory[frameindex].lastaccessedcycle = time++;
                memory[frameindex].isinmemory = true; 
                hit = true;
                totalhits++;
                break;
            }
        }
        if (!hit) {
            totalfaults++;
            int lru_index = 0;
            int min_time = memory[0].lastaccessedcycle;
            for (int frameindex = 1; frameindex < availableframes; ++frameindex) {
                if (memory[frameindex].lastaccessedcycle < min_time) {
                    min_time = memory[frameindex].lastaccessedcycle;
                    lru_index = frameindex;
                }
            }
            memory[lru_index].identifier = pagereferences[pagereference];
            memory[lru_index].lastaccessedcycle = time++;
            memory[lru_index].isinmemory = true; 
        }
        printf("Page %d: [", pagereferences[pagereference]);
        for (int k = 0; k < availableframes; ++k) {
            if (memory[k].isinmemory) {
                printf("%d", memory[k].identifier);
            } else {
                printf("-");
            }
            if (k < availableframes - 1) {
                printf(", ");
            }
        }
        printf("] - ");
        if (hit) {
            printf("Hit\n");
        } else {
            printf("Fault\n");
        }
    }
    printf("\nTotal Hits: %d\n", totalhits);
    printf("Total Faults: %d\n", totalfaults);
    free(memory);
}


int main() {
    int pagereferences[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    int availableframes = 3;

    LRU(pagereferences, sizeof(pagereferences) / sizeof(pagereferences[0]), availableframes);

    return 0;
}