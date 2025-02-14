#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int key;
    struct Node* next;
};

void hash(int key, int* index){
    if(key>0){ 
    *index = key%1000;
    } else{
        *index = (-1)*key%1000;
    }
}

void initialize(struct Node **table){
    for (int i = 0; i < 1000; i++) {
    table[i] = NULL;
    }
}

int main(int argc, char *argv[]){

FILE *fole;
fole = fopen(argv[1], "r");

struct Node **table = malloc(1000*sizeof(struct Node*)); 
initialize(table);

char a = ' ';
int x = 0;

while(fscanf(fole, " %c%d", &a, &x)!=EOF){ //need to find a new way to do this
    if(a == '\n'){
    fscanf(fole, "%c", &a);
    }



    int index = 0;
    hash(x, &index);
    if(a=='i'){
        if(table[index]==NULL){
            struct Node* new = malloc(sizeof(struct Node));
            new->key = x;
            new->next = NULL;
            table[index] = new;
            printf("inserted\n");
        }else{ //check for duplicates or insert
            struct Node* temp = table[index];
            struct Node* prev = NULL;

            bool duplicate = false;
            while(temp!=NULL){
                if(temp->key==x){
                    duplicate = true;
                    printf("duplicate\n");
                    break; //necessary?
                }
                prev = temp;
                temp = temp-> next;
            }

            if(duplicate!=true){
                struct Node* new = malloc(sizeof(struct Node));
                new->key = x;
                new->next = NULL;


                if(prev == NULL){
                    table[index] = new;
                }
                else{
                prev->next = new;
                }
                printf("inserted\n");
            }

        }


    }else if(a=='s'){
        struct Node* temp = table[index];
        bool present = false;

        while(temp!=NULL){
            if(temp->key==x){
                present = true;
                printf("present\n");
                break; //necessary?
            }
            temp = temp-> next;
        }
        if(!present){
        printf("absent\n");
        }


    }

}


//free memory
for (int i = 0; i < 1000; i++) {
    struct Node* temp = table[i];
    while(temp!=NULL){
        struct Node *tofree = temp;
        temp = temp->next;
        free(tofree);
    }
}
free(table);

fclose(fole);



return EXIT_SUCCESS;




}
