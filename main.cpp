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