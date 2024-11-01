#include <iostream> 
#include <vector>
#include <cstdint>
#include <iomanip>
#include <random>

std::random_device rd;
std::mt19937 eng{rd()};
std::uniform_int_distribution<uint8_t> rng{0, 255};

void prettyprintbyte(uint8_t b)
{
    std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << unsigned(b) << " ";
    std::cout << std::dec;
}

