#include <VectorOfVectors.hpp>
#include <string_view>

void test(std::string_view data)
{
    VectorOfVectors<uint8_t> v1;
    for(auto d: data)
        v1.push_back(0, d);

}


extern "C" int LLVMFuzzerTestOneInput([[maybe_unused]] const uint8_t *Data, [[maybe_unused]] size_t Size) {

    std::string_view data{reinterpret_cast<const char*>(Data), Size};
    
    return 0;  // Values other than 0 and -1 are reserved for future use.
}