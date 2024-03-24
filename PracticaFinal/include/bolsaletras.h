/**
 * @file bolsaletras.h
 * @author Torres Ramos, Juan Luis
 * @brief TDA Bolsa Letra
 * @version 0.1
 * @date 2021-12-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdlib.h>
#include <vector>


#include "../src/conjuntoletras.cpp"

using namespace std;

class bolsaletras {
private:
  vector<letra> bolsa; // vector de char

public:
  bolsaletras() : bolsa(vector<letra>(26)) {}

  void creabolsa(conjuntoletras conjunto);

  int size() const;


  class iterator {
  private:
    typename vector<letra>::iterator it;

  public:
    bool operator==(const iterator &i) { return i.it == it; }

    bool operator!=(const iterator &i) { return i.it != it; }

    letra &operator*() { return *it; }

    iterator &operator++() {
      ++it;
      return *this;
    }

    iterator &operator=(const iterator &i) {
      it = i.it;
      return *this;
    }

    iterator &operator+(const int &n) {
      for (int i = 0; i < n; i++) {
        ++it;
      }

      return *this;
    }

    friend class bolsaletras;
  };

  iterator begin() {
    iterator i;
    i.it = bolsa.begin();
    return i;
  }

  iterator end() {
    iterator i;
    i.it = bolsa.begin();
    return i;
  }
};