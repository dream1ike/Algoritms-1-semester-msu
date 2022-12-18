#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning(disable:4996)
int read_number_from_file(const char* filename)
{
    FILE* fin = fopen(filename, "r");
    int x = 0;
    if (fin)
    {
        if (fscanf(fin, "%d", &x) > 0) 
        {
            return x;
            fclose(fin);
        }
        fclose(fin);
    }
    return 0;
}
double** create_matrix(int x)
{
    double** arr = (double**)malloc(sizeof(double) * x);
    if(arr)
    {
        for (int i = 0; i < x; i++)
        {
            arr[i] = (double*)malloc(sizeof(double) * x);
        }
        return arr;
    }
    return NULL;
}
void write_matrix_to_file(const char* filename, int n)
{
    FILE* fout = fopen(filename, "w");
    if(fout)
    {
        srand(time(0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                fprintf(fout, "%g ",  pow(0.1, rand() % 2) * (rand() % 10000) * pow(-1, rand() % 2));
            }
            fprintf(fout, "\n");
        }
        fclose(fout);
    }
}
void read_matrix_from_file(const char* filename, double** arr, int size)
{
    FILE* fin = fopen(filename, "r");
    if (fin)
    {
        for (int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                fscanf(fin, "%lf ", &arr[i][j]);
            }
        }
        fclose(fin);
    }
}
int row_with_the_largest_amount(double** arr, int size)
{
    int row = 0;
    int number_row;
    int sum_of_el = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            sum_of_el += arr[i][j];
        }
        if (row < sum_of_el || i == 0) number_row = i;
    }
    return number_row;
}
void write_el_to_file(const char* filename, int el)
{
    FILE* fout = fopen(filename, "w");
    if (fout)
    {
        fprintf(fout, "%d", el);
        fclose(fout);
    }
}
int main()
{
    int size = read_number_from_file("in.txt");
    double** arr = create_matrix(size);
    write_matrix_to_file("in.txt", size);
    read_matrix_from_file("in.txt", arr, size);
    write_el_to_file("out.txt", row_with_the_largest_amount(arr, size));
    return 0;
} 