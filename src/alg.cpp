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
  while (file >> word) {
    std::string formatted_word = "";
    for (int i = 0; i < word.length(); i++) {
      if (isalpha(word[i])) {
        formatted_word += tolower(word[i]);
      }
    }
    if (formatted_word != "") {
      tree.add(formatted_word);
    }
  }
  fin.close();
  return tree;
}
