#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <iostream>
#include <iomanip>

template <class UINT>
void prettyprintbyte(UINT b)
{
    std::cout << "0x" << std::hex << std::setw(sizeof(UINT)) << std::setfill('0') << unsigned(b) << " ";
    std::cout << std::dec;
}

#endif // __COMMON_HPP__