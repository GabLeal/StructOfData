#include <stdio.h>
#include <stdlib.h>
#include "likedList.h"

void addStudent(Aluno *student);

int main(){
    List *li = NULL;
    Aluno student;
    int ok,choice,mat;

    do{
        printf("1 - Create list\n");
        printf("2 - Free list\n");
        printf("3 - Add new student at beginning of the list\n");
        printf("4 - Inserir ordenado - crescente\n");
        printf("5 - Print List l1\n");
        printf("6 - Total de alunos cadastrados\n");
        printf("7 - Deletar uma matricula\n");
        printf("10 - Exit\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        { 
        case 1:
            li = createList();

            if (li!=NULL)
            {
                printf("Lista encadeada criada com sucesso\n");
            }else{
                printf("Erro ao criar lista\n");
            }
            break;
        case 2:
            ok = freeList(li);
            if (ok){
                printf("Lista deletada com sucesso\n");
            }else{
                printf("Erro ao excluir lista\n");
            }
            break;
        case 3:
            addStudent(&student);
            ok = insertAtBeginning(li,student);
            if (ok)
            {
                printf("Aluno cadastrado\n");
            }else{
                printf("ERRO ao cadastrar aluno\n");
            }
            break;
        case 4:
            addStudent(&student);
            ok = ordenar(li,student);
            if(ok){
                printf("Aluno cadastrado\n");
            }else{
                printf("ERRO ao cadastrar aluno\n");
            }
            break;
        case 5:
            ok = printList(li);
            if (ok == 0) printf("Lista não existe\n");
            break;
        case 6:
            ok = amountStudent(li);
            if (ok == 0)
            {
               printf("Lista não foi alocada\n");
            }
            break;

        case 7:
            printf("\n\nMatricula a ser deletada: ");
            scanf("%d",&mat);
            ok = deleteStudent(li,mat);
            if (ok)
            {
                printf("Deletado com sucesso");
            }else{
                printf("Deu bosta\n");
            }
            

            break;
        default:
            break;
        }

    }while(choice != 10);

    return 0;
}

void addStudent(Aluno *student){
    printf("Numero de matrciula: ");
    scanf("%d",&student->matricula);
    printf("Nota:");
    scanf("%f",&student->nota);

}