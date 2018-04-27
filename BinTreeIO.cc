#include "BinTreeIO.hh"
#include <iostream>

void llegir_preordre(BinTree<int>& a) {
    int k;
    cin >> k;
    if (k != 0) {
        BinTree<int> left;
        BinTree<int> right;
        llegir_preordre(left);
        llegir_preordre(right);
        a = BinTree<int>(k, left, right);
    }
}
