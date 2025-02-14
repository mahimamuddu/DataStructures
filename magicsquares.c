#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>

bool allDifferent(int **arr, int n){
    int number = n*n;
    int *compare = malloc(number*sizeof(int));  //array
    int a = 0;
    for(int b = 0; b<number; b++){
        compare[b]=-1;
            
    }


    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            
            for(int z = 0; z<number; z++){
                if(arr[i][j]==compare[z]){
                    return false;
                }
            }
            compare[a] = arr[i][j];
            a++;

        }
    }
    free(compare);
    return true;


}



int main(int argc, char *argv[]){

FILE *fole;
fole = fopen(argv[1], "r");


int n;
fscanf(fole, "%d", &n);


int **square = malloc(n*sizeof(int *));  //rows

for(int i = 0; i<n; i++){
    square[i] = malloc(n*sizeof(int)); //cols
}

for(int a = 0; a<n; a++){
    for(int j = 0; j<n; j++){
        fscanf(fole, "%d", &square[a][j]); //array filled
    }
}




bool magic = true;
int compare = 0;
for(int i = 0; i<n; i++){
    compare+=square[0][i];
}

int sum = 0;
if(!allDifferent(square, n)){
    magic = false;
}

for(int i = 0; i<n; i++){  //rows added up
    sum = 0;
    for(int j = 0; j<n; j++){
        sum+=square[i][j];
    }
    if(sum!=compare){
        magic = false;
        break;
    }

}
if(magic==true){
for(int i = 0; i<n; i++){  //cols added up
    sum = 0;
    for(int j = 0; j<n; j++){
        sum+=square[j][i];
    }
    if(sum!=compare){
        magic = false;
        break;
    }

}
}

//now diagonals

if(magic==true){
    sum = 0;
    for(int i = 0; i<n; i++){
        sum+=square[i][i];
    }
    if(sum!=compare){
        magic = false;
    }

    sum = 0;
    for(int i = 0; i<n; i++){
        sum+=square[i][n-1-i];
    }
    if(sum!=compare){
        magic = false;
    }
    
}

if(magic == false){
    printf("not-magic\n");
} else if(magic == true){
    printf("magic\n");
}

for(int i = 0; i<n; i++){ //free memory
    free(square[i]);
}
free(square);

fclose(fole);

}




