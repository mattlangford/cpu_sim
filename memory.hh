#pragma once

#include <cstdint>
#include <vector>

namespace memory
{

using address_type = uint32_t;

class Memory
{
public: ///////////////////////////////////////////////////////////////////////
    ///
    ///
    ///
    Memory(const address_type bytes);

    ///
    ///
    ///
    ~Memory() = default;

public: ///////////////////////////////////////////////////////////////////////
    ///
    ///
    ///
    void write(const address_type address, const uint8_t data);

    ///
    ///
    ///
    uint8_t read(const address_type address);

private: /////////////////////////////////////////////////////////////////////
    std::vector<uint8_t> backing_;
};

}
