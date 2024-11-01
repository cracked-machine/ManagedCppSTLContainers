#ifndef __ENUMS_HPP__
#define __ENUMS_HPP__

#include <iostream>
#include <cstdint>
#include <array>
#include <iomanip>
#include <type_traits>

// The unsigned 16bit value type used by EncapsulatedEnum class, 
// includes serialization ctor and deserialize function (to_uint16)
class U16
{
public:
    U16() = default;
    U16(uint8_t b1, uint8_t b2) { m_data[0] = b1; m_data[1] = b2; }
    U16(uint16_t s2) { m_data[0] = s2 >> 8; m_data[1] = s2; }
    uint16_t to_uint16() const { return (m_data[0] << 8 | m_data[1]); }
    bool operator==(U16 const& rhs)  { return (this->to_uint16() == rhs.to_uint16()) ? true : false; }
private:
    std::array<uint8_t, 2> m_data{0x00, 0x00};
};

// iterator for use with enums
template < typename ENUM, ENUM beginVal, ENUM endVal>
class EnumIterator {
  typedef typename std::underlying_type<ENUM>::type val_t;
  int val;
public:
  EnumIterator(const ENUM &f) : val(static_cast<val_t>(f)) {}
  EnumIterator() : val(static_cast<val_t>(beginVal)) {}
  EnumIterator operator++() {
    ++val;
    return *this;
  }
  ENUM operator*() { return static_cast<ENUM>(val); }
  EnumIterator begin() { return *this; } //default ctor is good
  EnumIterator end() {
      static const EnumIterator endIter = ++EnumIterator(endVal); // cache it
      return endIter;
  }
  bool operator!=(const EnumIterator& i) { return val != i.val; }
};

// Singleton class provides forward/reverse lookup
// on member enum key/value
class EncapsulatedEnum
{
public:
    // The list of keys
    enum class Key 
    { 
        ONE, 
        THREE, 
        FIVE, 
        SIX, 
        TEN
    };
    // Iterator needs to be given begin/end points, so you have to 
    // sync this end limit with the last entry in EncapsulatedEnum::Key
    typedef EnumIterator<Key, static_cast<Key>(0), Key::TEN> KeyIter;
    // Return a U16 value depending on the key given
    static U16 getval(Key k) 
    { 
        // guarantee singleton creation
        [[maybe_unused]] static EncapsulatedEnum instance;

        switch(k)
        {
            case Key::ONE:
                return U16{0x00, 0x01};
            case Key::THREE:
                return U16{0x00, 0x03};
            case Key::FIVE:
                return U16{0x00, 0x05};
            case Key::SIX:
                return U16{0x00, 0x06};      
            case Key::TEN:
                return U16{0x00, 0x10};    
            // case Key::FIFTY:
            //     return U16{0x00, 0x50};    
            // default: do not uncomment, catch missing enum cases at compile time.
        } 
        // this line can never be called but keeps compiler warning quiet
        __builtin_unreachable();
    } 
    // Return a key depending on the U16 value given
    static KeyIter getkey(U16 val)
    {
        // iterate the enum and check values against the arg
        for (auto k: KeyIter())  { if (getval(k) == val) { return k; } }
        return KeyIter().end();
    }

private:
    EncapsulatedEnum() {}
};

#endif // __ENUMS_HPP__