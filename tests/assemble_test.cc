#include "assemble.hh"
#include "memory.hh"
#include "cpu.hh"
#include "logging.hh"

#include <assert.h>
#include <memory>

void test1()
{
    constexpr auto program =
        "LOADA 100\n"
        "LOADB 101\n"
        "ADD\n"
        "BNE 8\n"
        "ADD\n"
        "LOADB 100\n"
        "ADD\n"
        "SAVEA 100\n"
        "SWP\n"
        "LOADA 100\n"
        "BEQ 16\n";

    std::shared_ptr<memory::Memory> m = std::make_shared<memory::Memory>(200);
    m->write(100, 69);
    m->write(101, 10);

    assemble_program(program, *m);

    CPU c(m);

    LOG_DEBUG(static_cast<uint16_t>(m->read(100)));
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    c.execute_next_instruction();
    LOG_DEBUG(static_cast<uint16_t>(m->read(100)));
}

int main()
{
    test1();
}
