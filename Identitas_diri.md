Praktikum 1 - Struktur Data Linked List (Aplikasi MyTelu)
Identitas Pengumpul

Nama: [Putra Anugrah pamungkas]

NIM: [103122400007]

Kelas: [Struktur Data SE-08-01]

1. Kode Program
Berikut adalah kode program C++ untuk mengelola daftar postingan media sosial (Aplikasi MyTelu) menggunakan implementasi Single Linked List (SLL).

Header (sll.h)

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
address findMostPopular(List a);
void updateLikes(List &a, int postID, bool isLike);

sll.cpp

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

//tidak terpakai
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

address findMostPopular(List a) {
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

void updateLikes(List &a, int postID, bool isLike) {
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

main.cpp

#include <iostream>
#include <stdlib.h>
#include "sll.h"

using namespace std;

int main() {
    List a;
    createNewList(a);
    cout << "Nama: Putra Anugrah Pamungkas" << endl;
    cout << "NIM: 103122400007" << endl;
    cout << "Kelas: SE-08-01\n" << endl;
    cout << "===== Aplikasi MyTelu  =====" << endl;

    infotype post1 = {103, "Jangan Lupa Makan Siang.", 15, "ulung"};
    infotype post2 = {101, "Selamat pagi dunia!", 25, "sadewo"};
    infotype post3 = {105, "Indonesia Emas 2045.", 50, "putra"};
    infotype post4 = {102, "Assalamualaikum wr.wb!", 5, "ulung"};
    infotype post5 = {104, "Ujang Kretek Makan Nasi.", 30, "susan"};

    insertSorted(a, allocate(post1));
    insertSorted(a, allocate(post2));
    insertSorted(a, allocate(post3));
    insertSorted(a, allocate(post4));
    insertSorted(a, allocate(post5));

    cout << "\n--- Daftar Postingan Saat Ini ---" << endl;
    printList(a);
    cout << "\n" << endl;

    cout << "--- Postingan oleh 'ulung' ---" << endl;
    printByUsername(a, "ulung");
    cout << "\n" << endl;

    cout << "\n   Mencari postingan dari username 'rudi' ..." << endl;
    cout << "--- Postingan oleh 'rudi' ---" << endl;
    printByUsername(a, "rudi");
    cout << "\n" << endl;

    address popularPost = findMostPopular(a);
    if (popularPost != NIL) {
        cout << "--- Postingan Terpopuler ---" << endl;
        cout << "ID: " << info(popularPost).ID
             << ", Konten: " << info(popularPost).konten
             << ", Likes: " << info(popularPost).like
             << ", User: " << info(popularPost).username << endl;
        cout << "\n" << endl;
    } else {
        cout << "Tidak ada postingan untuk ditampilkan." << endl;
    }


    updateLikes(a, 102, true);
    cout << "\n--- Setelah +1 Like pada ID 102 ---" << endl;
    printList(a);

    updateLikes(a, 103, false);
    cout << "\n--- Setelah -1 Unlike pada ID 103 ---" << endl;
    printList(a);
    cout << "\n" << endl;
    
    return 0;
}

2. Penjelasan Kode
sll.h (Header File)
File ini berisi definisi tipe data dan deklarasi subprogram untuk Single Linked List:
-Mendefinisikan first, next, info, dan NIL (NULL) untuk memudahkan akses elemen list.
-infotype: Struktur data untuk menyimpan informasi sebuah postingan, yaitu ID (int), konten (string), like (int), dan username (string).
-element & List: Struktur dasar Linked List. element adalah node yang berisi infotype dan pointer next ke elemen berikutnya. List berisi pointer first ke elemen pertama.
-Deklarasi Fungsi: Deklarasi semua fungsi standar SLL (allocate, createNewList, isEmpty, insertFirst, printList, dll.) dan fungsi khusus yang diminta (insertSorted, printByUsername, findMostPopular, updateLikes).

sll.cpp (Implementasi Fungsi SLL)
File ini berisi implementasi dari semua fungsi yang dideklarasikan di sll.h:
-allocate(infotype data): Membuat node baru (elemen list), mengisinya dengan data, mengatur next menjadi NIL, dan mengembalikan alamat node tersebut.
-createNewList(List &a): Menginisialisasi list baru dengan mengatur first(a) menjadi NIL (list kosong).
-isEmpty(List a): Mengembalikan true jika list kosong (first adalah NIL).

insertFirst(List &a, address p): Menyisipkan node p sebagai elemen pertama list. Dalam kodingan ini menyisipkan data berupa ID post, username, like, dll

printList(List a): Mencetak semua data postingan dalam list secara berurutan.

Fungsi Khusus yang Diimplementasikan:
-insertSorted(List &a, address p): Menyisipkan node p ke dalam list sambil menjaga agar list tetap terurut berdasarkan ID postingan dari kecil ke besar.
Jika list kosong atau ID lebih kecil dari elemen pertama, sisip di awal (insertFirst).
Jika tidak, cari posisi penyisipan (q) di mana ID node berikutnya lebih besar dari ID node p.
-printByUsername(List a, string username): Melakukan traversal pada list dan mencetak hanya postingan yang memiliki username sesuai dengan input.
-findMostPopular(List a): Mencari dan mengembalikan address dari postingan yang memiliki jumlah like paling banyak di seluruh list.
-updateLikes(List &a, int postID, bool isLike): Mencari postingan berdasarkan postID. Jika ditemukan:
Jika isLike adalah true, jumlah like ditambah 1.
Jika isLike adalah false, jumlah like dikurangi 1 (tetapi tidak kurang dari 0).

main.cpp (Program Utama)
File ini berisi logika program utama yang mendemonstrasikan penggunaan fungsi SLL:
Membuat list kosong (a) dan menampilkan identitas.
-Pembuatan Data: Mendeklarasikan 5 variabel infotype (post1 hingga post5) sebagai data awal postingan.
-Penyisipan Terurut: Memanggil allocate untuk setiap data dan menyisipkannya ke list a menggunakan insertSorted. Urutan ID yang terbentuk adalah 101, 102, 103, 104, 105.
-printList: Mencetak seluruh daftar postingan.
-printByUsername:
Mencetak postingan milik 'ulung'.
Mencoba mencari postingan dari 'rudi' (yang tidak ada).
-findMostPopular: Mencari dan mencetak postingan dengan likes terbanyak. Awalnya adalah ID 105 (50 likes).
-updateLikes:
Menambah 1 like pada ID 102.
Mengurangi 1 like pada ID 103.
Mencetak list kembali untuk melihat perubahan