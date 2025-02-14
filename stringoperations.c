#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char* combine_args(int argc, char *argv[]) {
    int length = 0;
    for(int i = 1; i < argc; i++){
        length+=strlen(argv[i]);
    }
    char *argument = malloc(length + argc);
    for (int i = 1; i < argc; i++) {
        strcat(argument, argv[i]);
        if(i<argc-1){
            strcat(argument, " ");
        }

    }
    return argument;
}



int main(int argc, char *argv[]){

    char *argument = combine_args(argc, argv);
    int a = 0;
    char *answer = malloc(50*sizeof(char));
    int size = 0;


    while(argument[a]!= '\n' && argument[a]!='\0'){
        size++;
        a++;
    }

    a= 0;

    for(int i = 0; i<size; i++){
        if(argument[i]==' '){
            answer[a] = argument[i-1];
            a++;
        }
    }

    answer[a] = argument[size-1];
    answer[a+1] = '\0';

    printf("%s\n", answer);
    free(argument);
    free(answer);
    return EXIT_SUCCESS;

}
