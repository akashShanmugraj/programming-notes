#include<stdio.h>
#include<stdlib.h>

int hash(char *key, int keysize, int tablesize){
    int sum = 0;
    for(int i = 0; i < keysize; i++){
        sum += ((int) key[i] * (i + 1))%tablesize;
    }
    return sum % tablesize;
}

int main(){
    char samplestring[20] = "AASSDDFFGGHHJJKKLPP";
    printf("%d", hash(samplestring, 20, 10));
    int table;
    printf("\nEnter the size of the hash table: ");
    scanf("%d", &table);
    
}