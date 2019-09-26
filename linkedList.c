#include <stdio.h>
#include <stdlib.h>
#include "likedList.h"

typedef struct element{
    Aluno data;
    struct element *next;
}Element;

List *createList(){
    List* li = (List*)malloc(sizeof(List));
    if (li != NULL)
    {
        *li = NULL;
        return li;
    }
}

int freeList(List *li){
    if(li!=NULL){
        
        Element *node;
        while ((*li)!=NULL){
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        //free(li);
        return 1;   
    }

    return 0;

}

int insertAtBeginning(List *li, Aluno student){
    if(li==NULL) return 0;
    
    //Caso não seja nula
    Element *node = (Element*)malloc(sizeof(Element));
    if(node==NULL) return 0;

    node->data = student;
    node->next = (*li);
    *li = node;

    return 1;
}

int ordenar(List *li, Aluno student){
    if (li == NULL){
        return 0;
    }


    Element *node = (Element*)malloc(sizeof(Element));
    
    Element *percorrer = (*li);
    Element *anterior = NULL;

    while (percorrer!=NULL && student.matricula > percorrer->data.matricula){
        anterior = percorrer;
        percorrer = percorrer->next;
    }

    
    node->data = student;
    
    if (anterior==NULL){
        node->next = (*li);
        *li = node;
    }else{
        node->next = percorrer;
        anterior->next = node;
    }

    return 1;

}

int printList(List *li){
    if(li == NULL) return 0;
    if(*li == NULL) printf("Lista vazia\n");

    Element *node = *li;

    while (node != NULL){
        printf("--------------------------\n\n");
        printf("Matricula do aluno: %d\n",node->data.matricula);
        printf("Nota do aluno: %.2f\n\n",node->data.nota);

        node = node->next;
    }
    
    return 1;
}

int amountStudent(List *li){
    int amount = 0;

    if(li == NULL) return 0;
    if(*li == NULL){
        printf("Lista vazia\n");
    }
    Element *percorrer = *li;

    while(percorrer!=NULL){
        amount++;
        percorrer = percorrer->next;
    }

    printf("Existem %d alunos cadastrados no sistemas\n",amount);
    
}

int deleteStudent(List *li, int mat){

    if(li == NULL || *li == NULL) return 0;

    Element *percorrer = (*li);
    Element *atual = NULL;

    while (percorrer != NULL && percorrer->data.matricula != mat){
        atual = percorrer;
        percorrer = percorrer->next;
    }

    if (percorrer == NULL) return 0;

    
    if(atual == NULL){
        (*li) = percorrer->next;
        free(percorrer);        
    }else{

        atual->next = percorrer->next;
        free(percorrer);
    }
    return 1;
    
}