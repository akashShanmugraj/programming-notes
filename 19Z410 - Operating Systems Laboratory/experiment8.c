#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int value;
    bool in_memory;
    int last_used; 
} Page;

void FIFO(int pages[], int n, int frames) {
    Page *memory = malloc(frames * sizeof(Page));
    if (memory == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < frames; ++i) {
        memory[i].value = -1;
        memory[i].in_memory = false;
        memory[i].last_used = 0; 
    }
    int hits = 0;
    int faults = 0;
    int next_in = 0; 
    for (int i = 0; i < n; ++i) {
        bool hit = false;
        for (int j = 0; j < frames; ++j) {
            if (memory[j].value == pages[i]) {
                hit = true;
                hits++;
                break;
            }
        }
        if (!hit) {
            faults++;
            if (memory[next_in].in_memory) {
                memory[next_in].value = pages[i];
                memory[next_in].last_used = i + 1; 
                next_in = (next_in + 1) % frames; 
            } else {
                for (int k = 0; k < frames; ++k) {
                    if (!memory[k].in_memory) {
                        memory[k].value = pages[i];
                        memory[k].in_memory = true;
                        memory[k].last_used = i + 1; 
                        break;
                    }
                }
            }
        }
        printf("Page %d: [", pages[i]);
        for (int k = 0; k < frames; ++k) {
            if (memory[k].in_memory) {
                printf("%d", memory[k].value);
            } else {
                printf("-");
            }
            if (k < frames - 1) {
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
    printf("\nTotal Hits: %d\n", hits);
    printf("Total Faults: %d\n", faults);
    free(memory);
}

void LRU(int pages[], int n, int frames) {
    Page *memory = malloc(frames * sizeof(Page));
    if (memory == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < frames; ++i) {
        memory[i].value = -1;
        memory[i].in_memory = false;
        memory[i].last_used = 0; 
    }
    int hits = 0;
    int faults = 0;
    int time = 1; 
    for (int i = 0; i < n; ++i) {
        bool hit = false;
        for (int j = 0; j < frames; ++j) {
            if (memory[j].value == pages[i]) {
                memory[j].last_used = time++;
                memory[j].in_memory = true; 
                hit = true;
                hits++;
                break;
            }
        }
        if (!hit) {
            faults++;
            int lru_index = 0;
            int min_time = memory[0].last_used;
            for (int j = 1; j < frames; ++j) {
                if (memory[j].last_used < min_time) {
                    min_time = memory[j].last_used;
                    lru_index = j;
                }
            }
            memory[lru_index].value = pages[i];
            memory[lru_index].last_used = time++;
            memory[lru_index].in_memory = true; 
        }
        printf("Page %d: [", pages[i]);
        for (int k = 0; k < frames; ++k) {
            if (memory[k].in_memory) {
                printf("%d", memory[k].value);
            } else {
                printf("-");
            }
            if (k < frames - 1) {
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
    printf("\nTotal Hits: %d\n", hits);
    printf("Total Faults: %d\n", faults);
    free(memory);
}


int main() {
    int n, frames;
    printf("Enter the number of frames in memory: ");
    scanf("%d", &frames);
    printf("Enter the number of page references: ");
    scanf("%d", &n);
    int *pages = malloc(n * sizeof(int));
    if (pages == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the sequence of page references:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }
    printf("Sequence of page references: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", pages[i]);
    }
    printf("\n\n");

    printf("FIFO Page Replacement:\n");
    FIFO(pages, n, frames);

    printf("\n\n");

    printf("LRU Page Replacement:\n");
    LRU(pages, n, frames);

    free(pages);
    return 0;
}