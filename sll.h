#include <iostream>
#include <stdlib.h>

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info
#define NIL NULL

using namespace std;

//deklarasi struct infotype
struct infotype
{
    int ID;
    string konten;
    int like;
    string username;
};

struct element;
typedef element *address;

//deklarasi struct linked list
struct element
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

//deklarasi subprogram
address allocate(infotype data);
void createNewList(List &a);
bool isEmpty(List a);
void insertFirst(List &a, address p);
void insertAfter(List &a, infotype x, address p);
address findElement(List a, infotype x);
void printList(List a);

// Deklarasi subprogram yang diminta
void insertSorted(List &a, address p);
void printByUsername(List a, string username);
address Popular(List a);
void likes(List &a, int postID, bool isLike);


