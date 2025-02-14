#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>

bool prime(int x){
    if(x<2){
        return false;
    }
    for(int i = 2; i*i <= x; i++){
        if (x%i ==0 ){
            return false;
        }
    }
    return true;
}


int main(int argc, char *argv[]){

FILE *fole;
fole = fopen(argv[1], "r");

int total;
fscanf(fole, "%d", &total);

int *arr = (int*) malloc(total*sizeof(int));

for(int i = 0; i< total; i++) {
    int temp;
    fscanf(fole, "%d", &temp);
    arr[i] = temp;     //this should make an integer array
}

bool rtp = true;

for(int j = 0; j<total; j++){
    int s = arr[j];
    if(s<=0){
        rtp = false;
    }
    while(s>0){
        if(prime(s)){
            s/=10;
        } else{
            rtp = false;
            break;
        }
    }
    
    if(rtp == true){
        printf("%s", "yes \n");
    } else {
        printf( "%s", "no \n");
    }
    rtp = true;
}
    free(arr);
    fclose(fole);
    return EXIT_SUCCESS;

}
