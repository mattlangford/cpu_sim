#include "memory.hh"

namespace memory
{

//
// ############################################################################
//

Memory::Memory(const address_type bytes)
    : backing_(bytes)
{
}

//
// ############################################################################
//

void Memory::write(const address_type address, const uint8_t data)
{
    backing_.at(address) = data;
}

//
// ############################################################################
//

uint8_t Memory::read(const address_type address)
{
    return backing_.at(address);
}

}
