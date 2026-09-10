#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2500

int main(void)
{
    clock_t start, end;
    int i, j, r;
    
    int **a = (int **)malloc(N * sizeof(int *));
    int **b = (int **)malloc(N * sizeof(int *));
    int **c = (int **)malloc(N * sizeof(int *));
    
    for(i = 0; i < N; i++)
    {
        a[i] = (int *)malloc(N * sizeof(int));
        b[i] = (int *)malloc(N * sizeof(int));
        c[i] = (int *)malloc(N * sizeof(int));
    }
    
    srand(time(NULL));
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            a[i][j] = rand() % 100 + 1;
        }
    }
    
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            b[i][j] = rand() % 100 + 1;
        }
    }
    
    start = clock();

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            int elem_c = 0;
            for(r = 0; r < N; r++)
            {
                elem_c = elem_c + a[i][r] * b[r][j];
            }
            c[i][j] = elem_c;
        }
    }
    
    end = clock();
    double seconds = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Время перемножения матрицы для N = %d: %.4f сек.\n", N, seconds);

    for(i = 0; i < N; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}