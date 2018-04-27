#include "BinTreeIO.hh"

void llegir_preordre(BinTree& a) {
    int k;
    cin >> k;
    if (k != 0) {
        BinTree<int> left;
        BinTree<int> right;
        left.llegir();
        right.llegir();
        a = BinTree<int>(k, left, right);
    }
}
