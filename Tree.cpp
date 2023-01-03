#include "Tree.h"

adrNode newNode_1301213115(infotype x){
/* mengembalikan alamat dari suatu node hasil alokasi, dengan info adalah x
dan left dan right adalah NULL */
    adrNode p = new Node;
    info(p) = x;
    left(p) = nil;
    right(p) = nil;
    return p;
}

adrNode findNode_1301213115(adrNode root, infotype x){
/* mengembalikan alamat dari node yang memiliki info sama dengan x, atau NULL
apabila tidak ditemukan, Catatan: implementasikan secara REKURSIF */
    if(root == nil){
        return nil;
    }else if(info(root) == x){
        return root;
    }else if(x < info(root)){
        return findNode_1301213115(left(root), x);
    }else if(x > info(root)){
        return findNode_1301213115(right(root), x);
    }
}

void insertNode_1301213115(adrNode &root, adrNode p){
/* I.S. terdefinisi root dari BST (mungkin NULL), dan pointer p yang berisi
alamat node yang mau ditambahkan pada BST
 F.S. elemen yang ditunjuk oleh p ditambahkan sebagai node dari BST
Catatan: implementasikan secara REKURSIF */
    if(root == nil){
        root = newNode_1301213115(info(p));
    }else if(info(p) < info(root)){
        insertNode_1301213115(left(root), p);
    }else{
        insertNode_1301213115(right(root), p);
    }
}

void printPreOrder_1301213115(adrNode root){
/* I.S. terdefinisi root dari BST (mungkin NULL)
 F.S. menampilkan node dari BST secara Preorder atau dengan urutan root, left
dan right
Catatan: implementasikan secara REKURSIF */
    if(root != nil){
        cout << info(root) << " ";
        printPreOrder_1301213115(left(root));
        printPreOrder_1301213115(right(root));
    }
}

void printDescendant_1301213115(adrNode root, infotype x){
/* I.S. terdefinisi suatu root dari BST (mungkin NULL), dan infotype x
 F.S. menampilkan subtree atau keturunan dari node yang memiliki info x
Catatan: implementasikan secara REKURSIF */
    if(root == nil){
        cout << "";
    }else if(info(root) == x){
        printPreOrder_1301213115(left(root));
        printPreOrder_1301213115(right(root));

    }else{
        printDescendant_1301213115(left(root), x);
        printDescendant_1301213115(right(root), x);
    }
}

int sumNode_1301213115(adrNode root){
/* mengembalikan hasil penjumlahan semua info node yang terdapat pada BST
Catatan: implementasikan secara REKURSIF */
    int sum;

    if(root == nil){
        return 0;
    }else{
        int sum = sumNode_1301213115(left(root)) + info(root) + sumNode_1301213115(right(root));
        return sum;
    }
}

int countLeaves_1301213115(adrNode root){
/* mengembalikan banyaknya daun atau node yang tidak memiliki anak dari BST
Catatan: implementasikan secara REKURSIF */
    int jumDaun;

    if(root == nil){
        return 0;
    }else if((left(root) == nil) && (right(root) == nil)){
        return 1;
    }else{
        jumDaun = countLeaves_1301213115(left(root)) + countLeaves_1301213115(right(root));
        return jumDaun;
    }
}

int heightTree_1301213115(adrNode root){
/* mengembalikan banyaknya edge dari suatu root menuju daun yang terjauh.
Catatan: implementasikan secara REKURSIF */
    int leftHeight, rightHeight;

    if(root == nil){
        return 0;
    }else{
        leftHeight = heightTree_1301213115(left(root));
        rightHeight = heightTree_1301213115(right(root));
        if(leftHeight > rightHeight){
            return leftHeight;
        }else{
            return rightHeight + 1;
        }
    }
}
