#include "assemble.hh"
#include "instructions.hh"

void assemble_program(const std::string& program, memory::Memory& m)
{
    size_t current_pos = 0;
    size_t next_pos = 0;

    memory::address_type program_writer = 0;

    while (current_pos != std::string::npos)
    {
        next_pos = program.find('\n', current_pos);
        std::string this_line = program.substr(current_pos, next_pos);

        //
        // If there is a comment, we should remove it from the line to help parsing
        //
        const size_t comment_start = this_line.find(';');
        if (comment_start != std::string::npos)
        {
            this_line = this_line.substr(0, comment_start);
        }

        const size_t first_space = this_line.find(' ');
        const size_t newline = this_line.find('\n');
        const size_t end_instruction = std::min(first_space, newline);

        const std::string instruction_str = this_line.substr(0, end_instruction);
        if (instruction_str == "")
        {
            return;
        }

        LOG_DEBUG("Instruction: \"" << instruction_str << "\"");
        Instruction this_instruction = match(instruction_str);

        m.write(program_writer++, static_cast<uint8_t>(this_instruction));

        switch(this_instruction)
        {
        case Instruction::LOADA:
        case Instruction::LOADB:
        case Instruction::SAVEA:
        case Instruction::SAVEB:
        case Instruction::JMP:
        case Instruction::BEQ:
        case Instruction::BNE:
        {
            memory::address_type addr = std::stoi(this_line.substr(first_space));
            LOG_DEBUG("  Address: \"" << addr << "\"");
            m.write(program_writer++, addr);
            break;
        }
        default:
            break;
        }

        current_pos = next_pos + 1;
    }
}
