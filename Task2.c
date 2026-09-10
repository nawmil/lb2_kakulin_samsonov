#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void shell(int *items, int count)
{
    int i, j, gap, k;
    int x, a[5];
    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
    for(k = 0; k < 5; k++) {
        gap = a[k];
        for(i = gap; i < count; ++i) {
            x = items[i];
            for(j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int *items, int left, int right)
{
    int i, j;
    int x, y;
    i = left; j = right;
    x = items[(left + right) / 2];
    do {
        while((items[i] < x) && (i < right)) i++;
        while((x < items[j]) && (j > left)) j--;
        if(i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while(i <= j);
    if(left < j) qs(items, left, j);
    if(i < right) qs(items, i, right);
}

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void copy(int *src, int *dest, int n)
{
    for(int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void fill_rnd(int *arr, int n)
{
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void fill_asc(int *arr, int n)
{
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void fill_desc(int *arr, int n)
{
    for(int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void fill_half(int *arr, int n)
{
    int half = n / 2;
    for(int i = 0; i < half; i++) {
        arr[i] = i;
    }
    for(int i = half; i < n; i++) {
        arr[i] = n - i;
    }
}

int main(void)
{
    srand(time(NULL));
    int *base = (int *)malloc(SIZE * sizeof(int));
    int *work = (int *)malloc(SIZE * sizeof(int));

    clock_t start, end;
    double t_shell, t_qs, t_qsort;

    // 1. Случайный набор значений
    fill_rnd(base, SIZE);

    copy(base, work, SIZE);
    start = clock();
    shell(work, SIZE);
    end = clock();
    t_shell = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qs(work, 0, SIZE - 1);
    end = clock();
    t_qs = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qsort(work, SIZE, sizeof(int), cmp);
    end = clock();
    t_qsort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("1. Случайный набор:\n");
    printf("   Сортировка Шелла:  %.4f сек.\n", t_shell);
    printf("   Быстрая сортировка: %.4f сек.\n", t_qs);
    printf("   Стандартная сортировки: %.4f сек.\n\n", t_qsort);

    // 2. Возрастающая последовательность
    fill_asc(base, SIZE);

    copy(base, work, SIZE);
    start = clock();
    shell(work, SIZE);
    end = clock();
    t_shell = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qs(work, 0, SIZE - 1);
    end = clock();
    t_qs = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qsort(work, SIZE, sizeof(int), cmp);
    end = clock();
    t_qsort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("2. Возрастающая последовательность:\n");
    printf("   Сортировка Шелла:  %.4f сек.\n", t_shell);
    printf("   Быстрая сортировка: %.4f сек.\n", t_qs);
    printf("   Стандартная сортировки: %.4f сек.\n\n", t_qsort);

    // 3. Убывающая последовательность
    fill_desc(base, SIZE);

    copy(base, work, SIZE);
    start = clock();
    shell(work, SIZE);
    end = clock();
    t_shell = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qs(work, 0, SIZE - 1);
    end = clock();
    t_qs = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qsort(work, SIZE, sizeof(int), cmp);
    end = clock();
    t_qsort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("3. Убывающая последовательность:\n");
    printf("   Сортировка Шелла:  %.4f сек.\n", t_shell);
    printf("   Быстрая сортировка: %.4f сек.\n", t_qs);
    printf("   Стандартная сортировки: %.4f сек.\n\n", t_qsort);

    // 4. Комбинированная последовательность
    fill_half(base, SIZE);

    copy(base, work, SIZE);
    start = clock();
    shell(work, SIZE);
    end = clock();
    t_shell = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qs(work, 0, SIZE - 1);
    end = clock();
    t_qs = (double)(end - start) / CLOCKS_PER_SEC;

    copy(base, work, SIZE);
    start = clock();
    qsort(work, SIZE, sizeof(int), cmp);
    end = clock();
    t_qsort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("4. Комбинированная последовательность:\n");
    printf("   Сортировка Шелла:  %.4f сек.\n", t_shell);
    printf("   Быстрая сортировка: %.4f сек.\n", t_qs);
    printf("   Стандартная сортировки: %.4f сек.\n\n", t_qsort);

    free(base);
    free(work);

    return 0;
}