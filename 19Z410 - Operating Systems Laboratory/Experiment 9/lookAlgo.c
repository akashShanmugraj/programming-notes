#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

void LOOK(int arr[], int head, char* direction) 
{ 

    printf("Queue: ");
    for(int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nInitial Head Position: %d\n", head);

	int seek_count = 0; 
	int distance, cur_track; 
	int left[MAX_SIZE], right[MAX_SIZE]; 
	int left_size = 0, right_size = 0; 
	int seek_sequence[MAX_SIZE * 2]; 
	int seek_sequence_size = 0; 

	for (int i = 0; i < MAX_SIZE; i++) { 
		if (arr[i] < head) 
			left[left_size++] = arr[i]; 
		if (arr[i] > head) 
			right[right_size++] = arr[i]; 
	} 

	for (int i = 0; i < left_size - 1; i++) { 
		for (int j = 0; j < left_size - i - 1; j++) { 
			if (left[j] < left[j + 1]) { 
				int temp = left[j]; 
				left[j] = left[j + 1]; 
				left[j + 1] = temp; 
			} 
		} 
	} 

	for (int i = 0; i < right_size - 1; i++) { 
		for (int j = 0; j < right_size - i - 1; j++) { 
			if (right[j] > right[j + 1]) { 
				int temp = right[j]; 
				right[j] = right[j + 1]; 
				right[j + 1] = temp; 
			} 
		} 
	} 

	int run = 2; 
	while (run--) { 
		if (*direction == 'l') { 
			for (int i = left_size - 1; i >= 0; i--) { 
				cur_track = left[i]; 
				seek_sequence[seek_sequence_size++] = cur_track; 
				distance = abs(cur_track - head); 
				seek_count += distance; 
				head = cur_track; 
			} 
			*direction = 'r'; 
		} 
		else if (*direction == 'r') { 
			for (int i = 0; i < right_size; i++) { 
				cur_track = right[i]; 
				seek_sequence[seek_sequence_size++] = cur_track; 
				distance = abs(cur_track - head); 
				seek_count += distance; 
				head = cur_track; 
			} 
			*direction = 'l'; 
		} 
	} 

	printf("Total head movement= %d\n", seek_count); 
	printf("Average seek time= %d\n",seek_count/MAX_SIZE); 


} 

int main() 
{ 
	int arr[MAX_SIZE] = { 98,183,37,122,14,124,65,67}; 
	int head = 53; 
	char direction = 'r'; 

	printf("Initial position of head: %d\n", head); 

	LOOK(arr, head, &direction); 

	return 0; 
}