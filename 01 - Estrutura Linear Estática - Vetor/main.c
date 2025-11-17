#include <stdio.h>
#include <stdlib.h>

int main(){

    /// Criação de um vetor de 5 posições
    int numeros[5] = {2, 67, 34, 9, 1};
                  /// 0,  1,  2, 3, 4

    /// Acesso
    printf("\nValor : %d\n", numeros[1]);

    /// Atualização
    printf("\nValor : %d\n", numeros[2]);
    numeros[2] = 90;
    printf("\nValor : %d\n", numeros[2]);

    /// Inserção
    numeros[3] = 555;
    printf("\nValor : %d\n", numeros[3]);


    printf("\n\nVetor completo:\n");
    for(int i = 0; i < 5; i++){
        printf("\n%d", numeros[i]);
    }

    return 0;
}
