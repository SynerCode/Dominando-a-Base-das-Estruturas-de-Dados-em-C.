#include <stdio.h>
#include <stdlib.h>

int main(){

    /// criação de uma matriz 3x3
    int matriz[3][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };

    ///Acesso
    printf("\nElemento [1][2] : %d\n", matriz[1][2]);

    printf("\nElemento [0][0] : %d\n", matriz[0][0]);
    matriz[0][0] = 99;
    printf("\nElemento [0][0] : %d\n", matriz[0][0]);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("\n[%d][%d] : [%d]", i, j, matriz[i][j]);
        }
    }


    return 0;
}
