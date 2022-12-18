#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void write_numbers_to_file(const char* filename, int x, double arr[])
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        printf("%lf ", rand() - rand());
    }
    return 0;
} 