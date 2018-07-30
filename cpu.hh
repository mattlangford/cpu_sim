#pragma once

#include "memory.hh"

#include <memory>
#include <string>

class CPU
{
public: ///////////////////////////////////////////////////////////////////////
    ///
    ///
    ///
    CPU(std::shared_ptr<memory::Memory> m);

    ///
    ///
    ///
    ~CPU() = default;

public: ///////////////////////////////////////////////////////////////////////
    ///
    ///
    ///
    void execute_next_instruction();

private: //////////////////////////////////////////////////////////////////////
    ///
    /// A = A + B
    ///
    void add();

    ///
    /// A = -A
    ///
    void invert();

    ///
    /// reg = reg * 2
    ///
    void shift_left_a();
    void shift_left_b();

    ///
    /// reg = reg / 2
    ///
    void shift_right_a();
    void shift_right_b();

    ///
    /// A = A && B
    ///
    void logical_and();

    ///
    /// A = A || B
    ///
    void logical_or();

    ///
    /// A <-> B
    ///
    void swap();

    ///
    /// Load data at address into A/B
    ///
    void load_a(const memory::address_type addr);
    void load_b(const memory::address_type addr);

    ///
    /// Save data from A/B into address
    ///
    void save_a(const memory::address_type addr);
    void save_b(const memory::address_type addr);

    ///
    ///
    ///
    void jump(const memory::address_type addr);

    ///
    /// Jump if A == B
    ///
    void branch_eq(const memory::address_type addr);

    ///
    /// Jump if A != B
    ///
    void branch_neq(const memory::address_type addr);

private: ///////////////////////////////////////////////////////////////////////
    ///
    ///
    ///
    memory::address_type program_counter_;

    ///
    ///
    ///
    std::shared_ptr<memory::Memory> m_;

    ///
    /// Registers
    ///
    uint8_t regA_;
    uint8_t regB_;
};
