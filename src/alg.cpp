// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string word;
  std::ifstream fin;
  fin.open(filename);
  if (!fin.is_open()) {
    throw std::string("file opening error!");
  }
  while (!fin.eof()) {
    char sym = fin.get();
    if (sym != ' ' && isalpha(sym)) {
      sym = tolower(sym);
      word += sym;
    } else {
      tree.add(word);
      word = "";
    }
  }
  fin.close();
  return tree;
}
