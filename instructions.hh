#pragma once

#include "logging.hh"

#include <string>
#include <ostream>

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

///
///
///
Instruction match(const std::string& str)
{
    if (str == "NOP")
        return Instruction::NOP;
    else if (str == "ADD")
        return Instruction::ADD;
    else if (str == "INV")
        return Instruction::INV;
    else if (str == "SHIFTLA")
        return Instruction::SHIFTLA;
    else if (str == "SHIFTLB")
        return Instruction::SHIFTLB;
    else if (str == "SHIFTRA")
        return Instruction::SHIFTRA;
    else if (str == "SHIFTRB")
        return Instruction::SHIFTRB;
    else if (str == "AND")
        return Instruction::AND;
    else if (str == "OR")
        return Instruction::OR;
    else if (str == "SWP")
        return Instruction::SWP;
    else if (str == "LOADA")
        return Instruction::LOADA;
    else if (str == "LOADB")
        return Instruction::LOADB;
    else if (str == "SAVEA")
        return Instruction::SAVEA;
    else if (str == "SAVEB")
        return Instruction::SAVEB;
    else if (str == "JMP")
        return Instruction::JMP;
    else if (str == "BEQ")
        return Instruction::BEQ;
    else if (str == "BNE")
        return Instruction::BNE;

    LOG_ERROR("Unknown instruction: " << str);
    throw;
}

std::ostream& operator<<(std::ostream& os, Instruction i)
{
    switch(i)
    {
        case (Instruction::NOP): os << "NOP"; break;
        case (Instruction::ADD): os << "ADD"; break;
        case (Instruction::INV): os << "INV"; break;
        case (Instruction::SHIFTLA): os << "SHIFTLA"; break;
        case (Instruction::SHIFTLB): os << "SHIFTLB"; break;
        case (Instruction::SHIFTRA): os << "SHIFTRA"; break;
        case (Instruction::SHIFTRB): os << "SHIFTRB"; break;
        case (Instruction::AND): os << "AND"; break;
        case (Instruction::OR): os << "OR"; break;
        case (Instruction::SWP): os << "SWP"; break;
        case (Instruction::LOADA): os << "LOADA"; break;
        case (Instruction::LOADB): os << "LOADB"; break;
        case (Instruction::SAVEA): os << "SAVEA"; break;
        case (Instruction::SAVEB): os << "SAVEB"; break;
        case (Instruction::JMP): os << "JMP"; break;
        case (Instruction::BEQ): os << "BEQ"; break;
        case (Instruction::BNE): os << "BNE"; break;
        default:
          LOG_DEBUG("Unknown instruction: " << static_cast<uint16_t>(i));
    }

    return os;
}
