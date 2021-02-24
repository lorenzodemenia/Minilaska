#include "create.c"

/**
 * @brief questa struttura creare une cella dove il parametro type definisce il tipo di cella (cella nera , pedina nera ,ecc)
 * invece il parametro number definisce il numero di pedine sulla torre: la pedina (type : null e number : 0 ) è la cella normale 
 * 
 * 
 */
struct pawn{
    char code;
    int number;

};
typedef struct pawn *pawn;
struct cell{
    char name;
    pawn type;
};
typedef struct cell *cell;

struct square{
    cell **arr;
};
typedef struct square *square;

square create(int rows, int cols){
    square a;

    a=(square)malloc(sizeof(square));
    assert(a!=NULL);

    a->arr=(cell**)malloc(sizeof(cell*)*rows);
    assert(a->arr!=NULL);

    for (int  i = 0; i < rows; i++)
    {
        a->arr[i]=(cell*)malloc(sizeof(cell)*cols);
        assert(a->arr[i]!=NULL);
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                a->arr[i][j]->name = 'B';
                a->arr[i][j]->type=(pawn)malloc(sizeof(pawn));
                a->arr[i][j]->type->code='N';
                a->arr[i][j]->type->number=0;
            } else if (i % 2 != 0 && j % 2 != 0) {
                a->arr[i][j]->name = 'B';
                a->arr[i][j]->type=(pawn)malloc(sizeof(pawn));
                a->arr[i][j]->type->code='N';
                a->arr[i][j]->type->number=0;
            } else {
                a->arr[i][j]->name = 'W';
                a->arr[i][j]->type=(pawn)malloc(sizeof(pawn));
                a->arr[i][j]->type->code='N';
                a->arr[i][j]->type->number=0;
            }
        }

    }
    
}
void print(square a, int rows , int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%c ",a->arr[i][j]->name);
        }
        printf("\n");
    }
}

int main(){

    square arr=create(7,7);
    print(arr,7,7);




    

    return 0;
}