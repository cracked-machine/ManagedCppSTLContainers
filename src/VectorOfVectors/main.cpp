#include <VectorOfVectors.hpp>

#include <random>
#include <common.hpp>

int main() {

  std::random_device rd;
  std::mt19937 eng{rd()};
  std::uniform_int_distribution<uint8_t> rng{0, 255};

  using U8VectorOfVectors = VectorOfVectors<uint8_t>;

  {
      U8VectorOfVectors v2;
      for (int c = 0; c < 4; c++) { v2.push_back(0, rng(eng)); }
      for (int c = 0; c < 3; c++) { v2.push_back(1, rng(eng)); }
      for (int c = 0; c < 2; c++) { v2.push_back(2, rng(eng)); }
      for (int c = 0; c < 6; c++) { v2.push_back(3, rng(eng)); }

      std::cout << "=======================" << std::endl;
      v2.print();
      std::cout << "=======================" << std::endl;
      std::cout << "rows: " << v2.rowsize() << std::endl;
      std::cout << "row[1] size: " << v2.colsize(1) << std::endl;
      std::cout << "cells: " << v2.size() << std::endl;

      std::cout << "[3][4] = ";
      prettyprintbyte(v2.get(3, 4));
      std::cout << std::endl << "[5][5] = "<< (v2.get(5, 5)) << std::endl;

      U8VectorOfVectors::ColIter col_iters;
      U8VectorOfVectors::RowIter row_iters;

      // for(int i = 0; i < v2.rowsize(); i++)
      v2.get_row_iters(row_iters);
      for(auto rowit = row_iters.begin; rowit != row_iters.end; rowit++)
      {
          v2.get_column_iters(rowit, col_iters);
          // get some useful index info for demo purposes
          std::size_t rowpos = std::distance(row_iters.begin, rowit);
          std::cout << "row[" << rowpos << "] iterator: ";

          for(auto colit = col_iters.begin; colit != col_iters.end; colit++)
          {
              prettyprintbyte(*colit);
          }
          std::cout << std::endl;
      }
  }
  return 0;

}