#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int read_el_from_file(const char* fileName)
{
	FILE* fin = fopen(fileName, "r");
	if (fin)
	{
		int num = 0;
		if (fscanf(fin, "%d", &num) > 0) return num;
		fclose(fin);
		return num;
	}
	return 0;
}
void write_to_file(const char* fileName, char* arr)
{
	int size = 32;
	FILE* fout = fopen(fileName, "w");
	if (fout)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(fout, "%d ", arr[i]);
		}
		fclose(fout);
	}
}
char* get_binary_form(int x)
{
	int size = 32;
	char* arr = (char*)malloc(sizeof(char) * size);
	if (arr)
	{
		for (int i = size-1; i >= 0; i--)
		{
			arr[i] = x & 1;
			x = x >> 1;
		}
		return arr;
	}
	return NULL;
}
int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		int n = read_el_from_file(argv[1]);
		char* arr = get_binary_form(n);
		write_to_file(argv[2], arr);
		free(arr);
		return 0;
	}
}