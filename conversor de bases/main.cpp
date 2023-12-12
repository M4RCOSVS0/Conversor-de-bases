#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
using namespace std;


int* converteParaBinario(unsigned long int n, int* size = nullptr) {
    //coverte decimal para binario
    cout << "O valor " << n << " em binario eh ";
    int i = 1, c = 0;
    while (i) {
        if (n >= pow(2, c)) {
            c++;
        } else {
            i = 0;
        }
    }

    int* vet = new int[c]();  // Inicializa com zeros

    for (int i = 0; i < c; i++) {
        if (n >= pow(2, (c - 1 - i))) {
            n -= pow(2, (c - 1 - i));
            vet[i] = 1;
        }
    }

    if (size != nullptr) {
        *size = c;
        return vet;
    }else{
        for (int i = 0; i < c; i++) {
        cout << vet[i];
        }
    }

    delete[] vet;  // Libera a memória alocada dinamicamente

    return 0;
    
}




int converteParaDecimal(int n,int b) {
    //converte qualquer base para decimal
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

unsigned long int convertehexa(char *a){
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
    int c = -1, k = 0;
    int vetor[3] = {1,2,4};
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

int converteParaHexa(unsigned long int n){
    int size;
    int *binarioBruto = converteParaBinario(n, &size);
    
    int recuo = size % 4;
    size += recuo;
    //cout << endl << size;
    int *binarionovo = new int[size]();
    for (int i = 0; i < size-recuo; i++){
        binarionovo[i+recuo] = binarioBruto[i];
    }
    recuo = size/4;
    for (int i = 0; i < size; i++){
        cout << binarionovo[i];
    }
    delete[] binarioBruto;
    binarioBruto = new int[recuo];
    int c = 0;
    int indice = 1;
    for (int i = 0; i < size; i++){
        for (int j = 0; i < 4; j++){
            binarioBruto[i] += binarionovo[j] * i;
            i += i;
        }
        i = 0;
    }

    for (int i = 0; i < recuo; i++){
        binarioBruto[i];
    }
    
    
    

    

}

int main() {
    //unsigned long int value = 7589;
    //printBinary(value);
    converteParaHexa(47);
    return 0;
}

