#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

//converte decimal em binário
int* converteParaBinario(unsigned long int n, int* size = nullptr) {
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

//converte qualquer base para decimal
int converteParaDecimal(int n,int b) {
    
    char numeroString[20];
    sprintf(numeroString, "%d", n);//formata e salva a string em um array de caracteres
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

//função para coverter hexadecimal em decimal
unsigned long int convertehexa(char *a){
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int valor[] = {10,11,12,13,14,15};
    int i = 0;
    strrev(a); //inverter uma string
    for (; i < 60 && a[i] != '\0'; i++);
    int vet[i];
    memset(vet, 0, sizeof(vet));//preenche o vetor com 0
    
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

//função para converter decimal para octal
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

        if(c >= 2) {
            c = 0;
        }else{
            ++c;
        }

        binaryArray[i] = binaryArray[i] * vetor[c];

        if (c > 1){
            p[k] = (binaryArray[i] + binaryArray[i + 1] + binaryArray[i + 2] ) ;
            k++;
        }else if (c > 0 && abs(size - (3 * (int) ceil((double)size/3))) == 1 && i == 0){
            p[k] = (binaryArray[i] + binaryArray[i + 1]) ;
            k++;
        }else if (c == 0 && abs(size - (3 * (int) ceil((double)size/3))) == 2 && i == 0){
            p[k] = (binaryArray[i]) ;
            k++;
        }
    }
    printf("O valor %lu em octal eh ", n);
    for (int i = (int) ceil((double)size/3) - 1; i >= 0; i--) {
        printf("%d", p[i]);
    }

    free(binaryArray); // Não esqueça de liberar a memória alocada
}

// Função para converter decimal para hexadecimal
void decToHexa(int n) {
    char hexaDeciNum[100];
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        } else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    
    for (int j = i - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
}

//função para mostrar as opções
void carregar(int x){
    vector<string> bases = {"Binario","Octal","Decimal","Hexadecimal"};

    for (int i = 0; i < 4; i++)
    {
        if (x == i+1)
            continue;
        cout << i + 1 << " - " << bases[i]<< endl; 
    }
}

int main() {
    int x,y;
    char r = 'n';
    unsigned long int num;
    char hexa[60];
    do{
        cout << "Digite qual a base do seu numero" << endl;
        carregar(-1);
        cin >> x;
        cout << "Digite para qual base deseja converter" << endl;
        carregar(x);
        cin >> y;
        cout << "Digite seu numero " << endl;

        if (x == 4){
            scanf("%s",hexa);
            for (int i = 0; hexa[i] != '\0'; i++) {
                hexa[i] = toupper(hexa[i]);
            }
        }else{
            cin >> num;
        }

        switch (x){
        case 1://binário para
            switch (y){
            case 2://octal
                printBinary(converteParaDecimal(num,2));
                break;
            case 3://decimal
                cout << "O valor em decimal eh "<< converteParaDecimal(num,2);
                break;
            case 4://hexadecimal
                decToHexa(converteParaDecimal(num,2));
                break;
            default:
                cout << "ERRO! Valor invalido" << endl;
                break;
            }
            break;
        case 2://octal para
            switch (y){
            case 1://binario
                converteParaBinario(converteParaDecimal(num,8));
                break;
            case 3://decimal
                cout << "O valor em decimal eh "<< converteParaDecimal(num,8);
                break;
            case 4://hexadecimal
                decToHexa(converteParaDecimal(num,8));
                break;
            default:
                cout << "ERRO! Valor invalido" << endl;
                break;
            }
            break;
        case 3://decimal para
            switch (y){
            case 1://binario
                cout << "O valor em binario eh ";
                converteParaBinario(num);
                break;
            case 2://octal
                printBinary(num);
                break;
            case 4://hexadecimal
                cout << "O valor em hexadecimal eh ";
                decToHexa(num);
                break;
            default:
                cout << "ERRO! Valor invalido" << endl;
                break;
            }
            break;
        case 4://hexadecimal para
            switch (y){
            case 1://binario
                cout << "O valor em binario eh " << converteParaBinario(convertehexa(hexa));
                break;
            case 2://octa
                printBinary(convertehexa(hexa));
                break;
            case 3://decimal
                cout << "O valor em decimal eh "<< convertehexa(hexa);
                break;
            default:
                cout << "ERRO! Valor invalido" << endl;
                break;
            }
            break;
        default:            
            cout << "ERRO! Valor invalido" << endl;
            break;
        }

    cout << endl << "Continuar?[S/N] ";
    cin >> r;

    system("cls");//limpa tela

    }while (towlower(r) != 'n');
    
    
    return 0;
}




