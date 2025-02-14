#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int info;
    struct Node* left;
    struct Node* right;
};

void freeing(struct Node* root){
    if(root!=NULL){
        freeing(root->left);
        freeing(root->right);
        free(root);
    }
}



int main(int argc, char *argv[]){

FILE *fole;
fole = fopen(argv[1], "r");

if (fole == NULL){
    printf("error \n");
    return -1;
}

char a = ' ';
int x = 0;
struct Node* root = NULL;  //root made

char line[50];

while(fgets(line, sizeof(line), fole) != NULL){ //need to find a new way to do this
    sscanf(line, " %c %d", &a, &x);

    if(a=='i'){ //insertion or duplicate?
        if(root==NULL){
            root = malloc(sizeof(struct Node));  //new made
            root->info =x;
            root->left = NULL;
            root->right = NULL;
            printf("inserted 1\n");
        } else{
            struct Node* temp = root;
            int height = 1;


            while(temp!=NULL){    
                if(temp->info == x){
                    printf("duplicate\n");
                    break;
                }else if(x>temp->info){
                     if(temp->right == NULL){
                        struct Node* new = malloc(sizeof(struct Node));  //new made
                        new->info = x;
                        new->left = NULL;
                        new->right = NULL;
                        temp->right = new;
                        height++;
                        printf("inserted ");
                        printf("%d\n", height);
                        break;
                    }else{
                        temp = temp->right;
                        height++;
                    }
                }else if(x<temp->info){
                    if(temp->left == NULL){
                        struct Node* new = malloc(sizeof(struct Node));  //new made
                        new->info = x;
                        new->left = NULL;
                        new->right = NULL;
                        temp->left = new;
                        height++;
                        printf("inserted ");
                        printf("%d\n", height);
                        break;
                    }else{
                        temp = temp->left;
                        height++;
                    }
                }  
            }


        }




    } else if(a == 's'){ //search is done
    struct Node* temp = root;
    bool found = false;
    int height = 1;
    while(temp!=NULL){
        if(x<temp->info){
            temp = temp->left;
            height++;
        } else if(x>temp->info){
            temp = temp->right;
            height++;
        }else if(temp->info == x){
            found = true;
            printf("present ");
            printf("%d\n", height);
            break;
        }
    }
    if(!found){
        printf("absent\n");
    }
        

    }



}


//need to free and return

freeing(root);
return EXIT_SUCCESS;





}
