#include <stdio.h>
#include <time.h>
#define TAM 10
#define troca(A, B) { int t = A; A = B; B = t; }


//recebe vetor a[p..r] com p<r.
// Rearranja os elementos do vetor e devolve i em p..r tal que 
// a[p..i-1] <= a[i] <= a[i+1..r]
// OBS: "p..r, p..i+1, etc." -> lê-se "p até r, p até i+1"
int particione(int a[], int p, int r){
	int i = p-1, j = r;
	int v = a[r];
	
	for(;;){
		while(a[++i] < v);
		while(v < a[--j]){
			if(/* X */ j == p){
				break;
			}
		}
		if(i >= j){
			break;
		}
		troca(a[i], a[j]);
	}
	troca(a[i], a[r]);
	
	return i;
}

//a função rearranja o vetor a[p..r], com p <= r+1,
// de modo que ele fique em ordem crescente
void quicksort(int a[], int p, int r){
	int i;
	
	if(p < r){
		i = particione(a, p, r);
		quicksort(a, p, i-1);
		quicksort(a, i+1, r);
	}
}

