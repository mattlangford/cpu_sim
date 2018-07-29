#pragma once

#include "cpu.hh"
#include "memory.hh"


///
/// Supported Instructions
///
enum Instruction : uint8_t
{
    NOP = 0,
    ADD = 1,
    INV = 2,
    SHIFTLA = 3,
    SHIFTLB = 4,
    SHIFTRA = 5,
    SHIFTRB = 6,
    AND = 7,
    OR = 8,
    SWP = 9,
    LOADA = 10,
    LOADB = 11,
    SAVEA = 12,
    SAVEB = 13,
    JMP = 14,
    BEQ = 15,
    BNE = 16,
};
