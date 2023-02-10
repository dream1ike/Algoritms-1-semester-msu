#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
char* read_double_str(const char* filename, char** substr, int* size_str, int* size_substr)
{
    FILE* fin = fopen(filename, "r");
    *size_str = 0;
    *size_substr = 0;
    char* str = NULL;
    if(fin)
    {
        {
                str = (char*)malloc(sizeof(char) * (50));
                if (str)
                {
                    char symb = 'a';
                    while ((*size_str) < 50 && fscanf(fin, "%c", &symb) > 0 && symb != '\n')
                    {
                        str[(*size_str)] = symb;
                        (*size_str)++;
                    }
                    if (50 < (*size_str))
                    {
                        char* temp = (char*)realloc(str, sizeof(temp) * (*size_str));
                        if (temp)
                        {
                            str = temp;
                            free(temp);
                        }
                    }
                    {
                        *substr = (char*)malloc(sizeof(char) * (50));
                        if (*substr)
                        {
                            symb = 'a';
                            while((*size_substr) < (50) && fscanf(fin, "%c", &symb) > 0 && symb != '\n')
                            {
                            str[(*size_substr)] = symb;
                            (*size_substr)++;
                            }
                            if (50 < (*size_substr));
                        }
                    }
                }
        
        }
        fclose(fin);
    }
    return str;
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
int number_of_occurrences(char* str, char* substr, int size_str, int size_substr)
{
    int answer = 0;

    return answer;
}
int main()
{
    FILE* fout = fopen("out.txt", "w");
    if (fout)
    {
        char* substr = NULL;
        int size_str, size_substr;
        char* str = read_double_str("in.txt", &substr, &size_str, &size_substr);
        for (int i = 0; i < size_str; i++) fprintf(fout, "%c", str[i]);
        fprintf(fout, "\n");
        for (int i = 0; i < size_substr; i++) fprintf(fout, "%c", substr[i]);
        fclose(fout);
    }
    return 0;
}
//Programmer 1 
