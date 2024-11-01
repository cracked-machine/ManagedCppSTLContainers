#include <iostream>
#include <cstdarg>
#include <enums.hpp>


// test helper function
void validate(EncapsulatedEnum::KeyIter foundkey)
{
    // deref the iterator back to enum type, it is impossible
    // to omit a case providing 'default' is not used.
    switch(*foundkey)
    {
        case EncapsulatedEnum::Key::ONE:
            std::cout << "Found Key::ONE\n";
            return;
        case EncapsulatedEnum::Key::THREE:
            std::cout << "Found Key::THREE\n";
            return;
        case EncapsulatedEnum::Key::FIVE:
            std::cout << "Found Key::FIVE\n";
            return;
        case EncapsulatedEnum::Key::SIX:
            std::cout << "Found Key::SIX\n";
            return;
        case EncapsulatedEnum::Key::TEN:
            std::cout << "Found Key::TEN\n";
            return;
        // case EncapsulatedEnum::Key::FIFTY:
        //     std::cout << "Foudn Key::FIFTY\n";
        //     return;
        // default: do not uncomment, catch missing enum cases at compile time.
    };
    // foundkey == 'end()'
    std::cout << "Key not found\n";
}


int main()
{
    // Get the value mapped to a specific Enum type (key)
    std::cout << EncapsulatedEnum::getval(EncapsulatedEnum::Key::ONE).to_uint16() << std::endl;
    //std::cout << EncapsulatedEnum::getval(EncapsulatedEnum::Key::FOUR).to_uint16() << std::endl;  // compiler error
    std::cout << EncapsulatedEnum::getval(EncapsulatedEnum::Key::FIVE).to_uint16() << std::endl;

    // Get the Enum type (key) mapped to specific value
    validate(EncapsulatedEnum::getkey(U16{0x00, 0x01}));
    validate(EncapsulatedEnum::getkey(3));
    validate(EncapsulatedEnum::getkey(U16{0x00, 0x50}));

    std::cout << std::endl << sizeof(EncapsulatedEnum::Key) << std::endl;
    return 0;
}