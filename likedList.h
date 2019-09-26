#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct aluno{
    int matricula;
    float nota;
}Aluno;

typedef struct element *List;

List *createList();
int freeList(List *li);
int insertAtBeginning(List *li, Aluno student);
int ordenar(List *li, Aluno student);
int printList(List *li);
int amountStudent(List *li);
int deleteStudent(List *li, int mat);
#endif