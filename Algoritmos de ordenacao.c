#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int length);
void quicksort(int values[], int began, int end);
void inicializarAleatoriamente(int v[], int n);
void inicializarOrdemCrescente(int v[], int n);
void inicializarOrdemDecrescente(int v[], int n);

int main(){
    
    srand(time(NULL)); // gera valores completamente aleatorios em cada execucao do programa
    int N = 100000, i;
    int v[N];
    inicializarAleatoriamente(v, N);

    for (i=0; i < N; i++)
        printf("%d  ", v[i]);

    printf("\n\n");
    double start, stop, elapsed; // variaveis para medir o tempo

    start = (double) clock() / CLOCKS_PER_SEC;

    //Cleiston, fiz todas as implementações, só não sei se tem problema ter deixado nesse método de "escolher" qual compilar.

	//quicksort(v, 0, N);//
    //bubbleSort(v, N);//
    //mergeSort(v, N);//
    //insertionSort(v, N);//
    //selectionSort(v, N);//
    heapSort(v, N);

    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    for (i=0; i < N; i++)
        printf("%d  ", v[i]);
    
    printf("\n\n\nTempo total em segundos: %f\n\n\n", elapsed);

    return 0;
}



void bubbleSort(int array[], int length)
{
    int i, j;
    for(i = length - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void quicksort(int values[], int began, int end)
{
    int i, j, pivo, aux;
    i = began;
    j = end-1;
    pivo = values[(began+end)/2];
    while(i <= j)
    {
        while(values[i] < pivo && i < end) i++;
        while(values[j] > pivo && j > began) j--;
        if(i <= j)
        {
            aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
        quicksort(values, began, j+1);
    if(i < end)
        quicksort(values, i, end);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void merge(int vec[], int vecSize) {
    int mid;
    int i, j, k;
    int* tmp;
    tmp = (int*) malloc(vecSize * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    }
    mid = vecSize / 2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < vecSize) {
        if (vec[i] < vec[j]) {
          tmp[k] = vec[i];
          ++i;
        }
        else {
          tmp[k] = vec[j];
          ++j;
        }
        ++k;
    }
    if (i == mid) {
        while (j < vecSize) {
          tmp[k] = vec[j];
          ++j;
          ++k;
        }
    }
    else {
        while (i < mid) {
          tmp[k] = vec[i];
          ++i;
          ++k;
        }
    }
    for (i = 0; i < vecSize; ++i) {
        vec[i] = tmp[i];
    } 
    free(tmp);
}

void mergeSort(int vec[], int vecSize) {
    int mid;

    if (vecSize > 1) {
        mid = vecSize / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, vecSize - mid);
        merge(vec, vecSize);
    }
}

void heapSort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		heap(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		heap(vet, 0, i-1);
	}
}

void heap(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

void inicializarAleatoriamente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = rand();
}

void inicializarOrdemCrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = i;
}


void inicializarOrdemDecrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = n-i;
}