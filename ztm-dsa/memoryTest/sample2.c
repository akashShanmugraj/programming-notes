#include<stdio.h>

int main(){
    long double mainaddress;
    printf("Enter addresss: ");
    scanf("%Lf", &mainaddress);
    printf("Address: %Lf\n", mainaddress);
    long double *mainaddresspointer = &mainaddress;
    printf("Value at address: %Lf\n", *mainaddresspointer);

}