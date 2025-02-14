#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]){



FILE *fole;
fole = fopen(argv[1], "r");

int row1;
fscanf(fole, "%d", &row1);
int col1;
fscanf(fole, "%d", &col1);

int **arr1 = malloc(row1*sizeof(int *));  //rows

for(int i = 0; i<row1; i++){
    arr1[i] = malloc(col1*sizeof(int)); //cols
}


for(int a = 0; a<row1; a++){
    for(int j = 0; j<col1; j++){
        fscanf(fole, "%d", &arr1[a][j]); //array1 filled
    }
}



int row2;
fscanf(fole, "%d", &row2);
int col2;
fscanf(fole, "%d", &col2);

int **arr2 = malloc(row2*sizeof(int *));  //rows

for(int i = 0; i<row2; i++){
    arr2[i] = malloc(col2*sizeof(int)); //cols
}

for(int a = 0; a<row2; a++){
    for(int j = 0; j<col2; j++){
        fscanf(fole, "%d", &arr2[a][j]); //array2 filled
    }
}
if(col1 != row2){
    printf("bad-matrices");
    return EXIT_SUCCESS;
}

//new matrix has dimensions r1 x col2
int sum = 0;
for(int i = 0; i<row1; i++){
    for(int j = 0; j<col2; j++){
        sum = 0;
        for(int a = 0; a<col1; a++){
        sum+= arr1[i][a]*arr2[a][j]; //is this wrong? (maybe)
        }
        printf("%d", sum);
        if(j!=col2-1){
            printf("\t");
        }
    }
    printf("\n");

}

for(int i = 0; i<row1; i++){ //free memory
    free(arr1[i]);
}
free(arr1);

 for(int i = 0; i<row2; i++){ //free memory
    free(arr2[i]);
}
free(arr2);

fclose(fole);

return EXIT_SUCCESS;

}
