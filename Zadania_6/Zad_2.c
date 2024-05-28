#include <stdio.h>
int main()
{
int intarray[10];

for( int i = 0; i < 10; i++) {
    intarray[i] = i;
}

int *intpointer = &intarray[0];

for( int i = 0; i < 10; i++) {
    printf("address: %x - has value %d\n", intpointer, *intpointer);
    intpointer++;
}

return 0;
}