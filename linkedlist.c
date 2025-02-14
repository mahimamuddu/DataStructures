#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int num;
    struct Node* next;
};

void insert(struct Node* new, struct Node* place){ //the place node is the one before where u want to insert it
    if(place==NULL){return;}
    new->next = place->next;
    place->next = new;
}

void delete(struct Node* place){
    struct Node* temp = place->next;
    if(temp!=NULL){
        place->next = temp->next;
    }else{
        place->next = NULL;
    }
    free(temp);
}


int main(int argc, char *argv[]){

FILE *fole;

fole = fopen(argv[1], "r");
if (fole == NULL){
    printf("error \n");
    return -1;
}

char c;
fseek(fole, 0, SEEK_END);
long length = ftell(fole);
if(length==0){
    fclose(fole);
    printf("%d \n", 0);
    return -1;
}
rewind(fole);

int i;
struct Node* head = NULL;

while(fscanf(fole, " %c%d", &c, &i)!=EOF){


if(c == 'i'){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->num = i;
    new->next = NULL; 


    if (head == NULL || head->num > new->num) {
        new->next = head;
        head = new;

    } else{


    struct Node* temp = head;
    struct Node* before = NULL;

   

    bool duplicate = false;
    while(temp!=NULL && temp->num <= new->num){

        if(temp->num == new->num){
        duplicate = true;
        break;
        }

        before = temp;
        temp = temp->next;
    }
    

    
    if(!duplicate){
        if(before!=NULL){
            insert(new, before); //this adds the new node if its not a duplicate

        }
    }

    }


    
    } 
    
else{ //this isn't right
        struct Node* temp = head;

        if (temp != NULL && temp->num == i) {
        head = head->next;
        free(temp);
        } else{

        
    struct Node* before = NULL;

    while(temp!=NULL&&temp->num!=i){
        before = temp;
        temp = temp->next;
    }
    if(temp != NULL){//if it is found
    before->next = temp->next;
        free(temp);
    }
        }

    }
    
    
    


    }
    
    

struct Node* temp = head;
int size = 0;
while(temp!=NULL){
    size++;
    temp = temp->next;
}

printf("%d\n", size);
temp = head;

while(temp!=NULL){
    printf("%d\t", temp->num);
    temp = temp->next;
}
printf("\n");


temp = head;
while(temp!=NULL){
    struct Node* stemp = temp;
    temp = temp->next;
    free(stemp);

}

fclose(fole);
return EXIT_SUCCESS;


}
