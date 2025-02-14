#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isConsonant(char a){ //need to take in multiple WORDS
    if(a == 'a'|| a =='e'|| a=='i'|| a=='o'|| a=='u' ){
        return false;
    } else{
        return true;
    }
}




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



int main(int argc, char *argv[]){   //general implementation idea: scan and print continuously
int z = 0;
char a = 'b';

char *argument = combine_args(argc, argv);



while (z<strlen(argument)){
    a = argument[z];
    z++;

    if(a==' '){
    a = argument[z];
    z++;    
    }

    if(a == 'a' || a == 'e' || a == 'i'|| a=='o'|| a=='u'||a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'){
        while(a!= '\n' && a!='\0' && a!= ' '){  //iterating through the word and printing
            printf("%c", a);
            a = argument[z];
            z++;;
        }
        printf("yay");


    } else{ //if its a consonant
        char arr[20];
         int i = 0;
       
        while(isConsonant(a)){ //another consonant
            arr[i] = a;
            i++;
            a = argument[z];
            z++;
       
        }
        arr[i] = '\0';
        
        while(a!= '\n' && a!='\0' && a!= ' '){  //iterating through the word and printing
            printf("%c", a);
            a = argument[z];
            z++;
        }
        char b =arr[0];
        i = 0;
        while(arr[i]!='\0'){
            printf("%c", b);
            i++;
            b = arr[i];
        }

        printf("ay");
    }

    if(a!= '\n' && a!='\0'){
        printf(" ");
    }



    }

    

    printf("\n");

    free(argument);
    return EXIT_SUCCESS;


} //worried about spaces bc there will be one at the end.
