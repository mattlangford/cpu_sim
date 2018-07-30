#include "cpu.hh"
#include "instructions.hh"
#include "logging.hh"

//
// ############################################################################
//

CPU::CPU(std::shared_ptr<memory::Memory> m)
    : program_counter_(0),
      m_(m)
{
}


//
// ############################################################################
//

void CPU::execute_next_instruction()
{
    const uint8_t to_execute = static_cast<Instruction>(m_->read(program_counter_++));
    switch(to_execute)
    {
        case (Instruction::NOP): break;
        case (Instruction::ADD): add(); break;
        case (Instruction::INV): invert(); break;
        case (Instruction::SHIFTLA): shift_left_a(); break;
        case (Instruction::SHIFTLB): shift_left_b(); break;
        case (Instruction::SHIFTRA): shift_right_a(); break;
        case (Instruction::SHIFTRB): shift_right_b(); break;
        case (Instruction::AND): logical_and(); break;
        case (Instruction::OR): logical_or(); break;
        case (Instruction::SWP): swap(); break;
        case (Instruction::LOADA): load_a(m_->read(program_counter_++)); break;
        case (Instruction::LOADB): load_b(m_->read(program_counter_++)); break;
        case (Instruction::SAVEA): save_a(m_->read(program_counter_++)); break;
        case (Instruction::SAVEB): save_b(m_->read(program_counter_++)); break;
        case (Instruction::JMP): jump(m_->read(program_counter_++)); break;
        case (Instruction::BEQ): branch_eq(m_->read(program_counter_++)); break;
        case (Instruction::BNE): branch_neq(m_->read(program_counter_++)); break;
        default:
          LOG_DEBUG("Unknown instruction: " << static_cast<uint16_t>(to_execute));
    }
}

//
// ############################################################################
//

void CPU::add()
{
    regA_ = regA_ + regB_;
}

//
// ############################################################################
//

void CPU::invert()
{
    regA_ = -regA_;
}

//
// ############################################################################
//

void CPU::shift_left_a()
{
    regA_ <<= 1;
}

//
// ############################################################################
//

void CPU::shift_left_b()
{
    regB_ <<= 1;
}

//
// ############################################################################
//

void CPU::shift_right_a()
{
    regA_ >>= 1;
}

//
// ############################################################################
//

void CPU::shift_right_b()
{
    regB_ >>= 1;
}

//
// ############################################################################
//

void CPU::logical_and()
{
    regA_ = regA_ && regB_;
}

//
// ############################################################################
//

void CPU::logical_or()
{
    regA_ = regA_ || regB_;
}

//
// ############################################################################
//

void CPU::swap()
{
    std::swap(regA_, regB_);
}

//
// ############################################################################
//

void CPU::load_a(const memory::address_type addr)
{
    regA_ = m_->read(addr);
}

//
// ############################################################################
//

void CPU::load_b(const memory::address_type addr)
{
    regB_ = m_->read(addr);
}

//
// ############################################################################
//

void CPU::save_a(const memory::address_type addr)
{
    m_->write(addr, regA_);
}

//
// ############################################################################
//

void CPU::save_b(const memory::address_type addr)
{
    m_->write(addr, regB_);
}

//
// ############################################################################
//

void CPU::jump(const memory::address_type addr)
{
    program_counter_ = addr;
}

//
// ############################################################################
//

void CPU::branch_eq(const memory::address_type addr)
{
    if (regA_ == regB_)
    {
        program_counter_ = addr;
    }
}

//
// ############################################################################
//

void CPU::branch_neq(const memory::address_type addr)
{
    LOG_DEBUG("regA_: " << static_cast<uint16_t>(regA_) << " regB_: " << static_cast<uint16_t>(regB_))
    if (regA_ != regB_)
    {
        program_counter_ = addr;
    }
}
