#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* converteParaBinario(unsigned long int n,int *size){
    printf("O valor %lu em binario eh ",n);
    int i = 1,c=0;
    while (i){
        if (n >= pow(2,c)){
            c++;    
        }else{
            i = 0;
        }
    }
    int *vet = (int *)calloc(c, sizeof(int));

    if (vet == NULL) {
        *size = 0;
        return NULL;
    }

    //return pow(2,c-1);
    for (int i = 0; i < c; i++){
        if(n >= pow(2,(c-1-i))){
            n -= pow(2,(c-1-i));
            vet[i]=1;
        }
    }
    for (int i = 0; i < c; i++)
    {
        printf("%d", vet[i]);
    }
    *size = c;
    return vet;
    //return c;
}

int converteParaDecimal(int n,int b) {
    char numeroString[20];
    sprintf(numeroString, "%d", n);
    int tamanho = strlen(numeroString);
    int vet[tamanho],soma=0;
    for (int i = 0; i < tamanho; i++) {
        vet[i] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < tamanho ; i++) {
        soma += vet[i]*pow(b,i);
    }
    return soma;
    
}

unsigned long int convertehexa(char *a, int b){
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int valor[] = {10,11,12,13,14,15};
    int i = 0;
    strrev(a);
    for (; i < 60 && a[i] != '\0'; i++);
    int vet[i];
    memset(vet, 0, sizeof(vet));
    
    for (int c = 0; c < i; c++) {
        for (int j = 0; j < 6; j++) {
            if (a[c] == letras[j]){
                vet[c] = valor[j];
            } 
        }
        if (!(vet[c] >= 10 && vet[c] <= 15)){
                vet[c] =  a[c] - '0';
        }   
    }
    int tamanho = sizeof(vet) / sizeof(vet[0]);
    int resultado = 0;
    for (int k = 0; k < tamanho; k++) {
        resultado += vet[k] * pow(16,k);
      
    }
    
   return resultado;
}

void printBinary(unsigned long int n) {
    int size;
    int *binaryArray = converteParaBinario(n, &size);


    int *p = (int *) calloc((int) ceil((double)size/3),sizeof(int));
    
    
    if (binaryArray == NULL) {
        printf("Erro na alocação de memória.\n");
        return;
    }
    printf("\n");
    int c = -1,soma=0, k = 0;
    int vetor[3] = {1,2,4};
    int ver[30];
    for (int i = size - 1; i >= 0; i--) {
        c = ( c >= 2 ) ? 0 : ++c ;   
        binaryArray[i] = binaryArray[i] * vetor[c];
        //printf("\nNa posicao %d esta %d ",i,binaryArray[i]);
        if (c > 1){
            p[k] = (binaryArray[i] + binaryArray[i + 1] + binaryArray[i + 2] ) ;
            //printf("\n%d %d %d\n",binaryArray[i] , binaryArray[i + 1] , binaryArray[i + 2]);
            k++;
        }else if (c > 0 && abs(size - (3 * (int) ceil((double)size/3))) == 1 && i == 0){
            p[k] = (binaryArray[i] + binaryArray[i + 1]) ;
            //printf("\n%d %d %d\n",binaryArray[i] , binaryArray[i + 1] , binaryArray[i + 2]);
            k++;
        }else if (c == 0 && abs(size - (3 * (int) ceil((double)size/3))) == 2 && i == 0){
            p[k] = (binaryArray[i]) ;
            //printf("\n%d %d %d\n",binaryArray[i] , binaryArray[i + 1] , binaryArray[i + 2]);
            k++;
        }
        
        
        
        
    }
    printf("O valor %d em octal eh ",n);
    for (int i = (int) ceil((double)size/3) - 1; i >= 0; i--) {
    printf("%d", p[i]);
    }

    

    free(binaryArray); // Não esqueça de liberar a memória alocada
}


int main() {
    unsigned long int value = 7589;
    printBinary(value);
    return 0;
}