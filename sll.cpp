#include "sll.h"

address allocate(infotype data) {
    address p = new element;
    info(p) = data;
    next(p) = NIL;
    return p;
}

void createNewList(List &a) {
    first(a) = NIL;
}

bool isEmpty(List a) {
    return first(a) == NIL;
}

void insertFirst(List &a, address p) {
    next(p) = first(a);
    first(a) = p;
}

void insertAfter(List &a, infotype x, address p){
    //tidak wajib diisi
}

//tidak  terpakai
void deleteFirst(List &a, address p){
    p = first(a);
    first(a) = next(p);
    next(p) = NIL;
}

//tidak terpakai
void deleteLast(List &a, address p){
    address q = first(a);
    while (next(next(q))!= NIL){
        q = next(q);
    }
    p = next(q);
    next(q) = NIL;
}

int length(List a){
    int jml = 1;
    address p = first(a);
    if (p == NIL){
        return 0;
    } else{
        while (next(p)!=NIL){
            jml++;
            p = next(p);
        }
        return jml;
    }
}

address findElement(List a, infotype x){
    address p = first(a);
    while(info(p).ID != x.ID){
        p = next(p);
    }
    return p;
}

void printList(List a) {
    if (isEmpty(a)) {
        cout << "List Kosong." << endl;
    } else {
        address p = first(a);
        while (p != NIL) {
            cout << "ID: " << info(p).ID << ", Konten: " << info(p).konten << ", Likes: " << info(p).like << ", User: " << info(p).username << endl;
            p = next(p);
        }
    }
}
//Buatkan subprogram pemisah list
// Implementasi subprogram yang diminta

void insertSorted(List &a, address p) {
    if (isEmpty(a) || info(p).ID < info(first(a)).ID) {
        insertFirst(a, p);
    } else {
        address q = first(a);
        while (next(q) != NIL && info(next(q)).ID < info(p).ID) {
            q = next(q);
        }
        next(p) = next(q);
        next(q) = p;
    }
}

void printByUsername(List a, string username) {
    address p = first(a);
    bool found = false;
    while (p != NIL) {
        if (info(p).username == username) {
            cout << "ID: " << info(p).ID << ", Konten: " << info(p).konten << ", Likes: " << info(p).like << ", User: " << info(p).username << endl;
            found = true;
        }
        p = next(p);
    }
    if (!found) {
        cout << "Tidak ada postingan dari user '" << username << "'." << endl;
    }
}

address popular(List a) {
    if (isEmpty(a)) {
        return NIL;
    }

    address p = first(a);
    address mostPopularPost = p;
    int maxLikes = info(p).like;

    p = next(p);
    while (p != NIL) {
        if (info(p).like > maxLikes) {
            maxLikes = info(p).like;
            mostPopularPost = p;
        }
        p = next(p);
    }
    return mostPopularPost;
}

void likes(List &a, int postID, bool isLike) {
    address p = first(a);
    while (p != NIL && info(p).ID != postID) {
        p = next(p);
    }

    if (p != NIL) {
        if (isLike) {
            info(p).like++;
        } else if (info(p).like > 0) {
            info(p).like--;
        }
    }
}
