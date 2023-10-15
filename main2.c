#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// J'ajoute ce commentaire pour ma formation en git
#define Pmax 10
typedef int Prio;
typedef struct Cellule
{
    char Car;
    struct Cellule *Next;
} *Node;
typedef struct
{
    struct Cellule *head;
} FaP[Pmax];

void initilizationAll(FaP F)
{
    int i;
    for (i = 0; i < Pmax; i++)
    {
        F[i].head = NULL;
    }
}

void Inserer(FaP F, char x, Prio p)
{
    Node Nv;
    Nv = (Node)malloc(sizeof(Node));
    Nv->Car = x;
    Nv->Next = NULL;
    if (F[p].head)
    {
        Nv->Next = F[p].head;
        F[p].head = Nv;
    }
    else
    {
        F[p].head = Nv;
    }
}

void AfficherUnit(Node N)
{
    Node cp;
    if (!N)
    {
        puts("La liste est vide");
        return;
    }
    for (cp = N; cp; cp = cp->Next)
        printf("[%c] ->", cp->Car);
    puts("NULL\n");
}

void Afficher(FaP F)
{
    int i;
    for (i = 0; i < Pmax; i++)
    {
        printf("%d", i + 1);
        AfficherUnit(F[i].head);
    }
}

int main(int argc, char const *argv[])
{
    FaP F;
    int i;
    initilizationAll(F);
    Inserer(F, 'a', 1);
    Inserer(F, 'a', 2);
    Inserer(F, 'a', 3);
    Inserer(F, 'a', 1);
    Afficher(F);

    return 0;
}