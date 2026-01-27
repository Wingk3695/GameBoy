// Definitions of GameBoy CPU.
// SM83 CPU Core.
#include <cstdint>

// SM83 CPU interprets registers as two 8-bit registers or one 16-bit register.
// Note the order of the registers is important.
// 目前的存储顺序基本是小端序。所以先定义低位的寄存器。

constexpr uint8_t FLAG_Z = 0x80; // 1000 0000
constexpr uint8_t FLAG_N = 0x40; // 0100 0000
constexpr uint8_t FLAG_H = 0x20; // 0010 0000
constexpr uint8_t FLAG_C = 0x10; // 0001 0000
struct Registers {
    // AF 寄存器 (A是高位, F是低位)
    union {
        struct { uint8_t F; uint8_t A; }; // 注意顺序：低位在前，高位在后
        uint16_t AF;
    };

    // BC 寄存器 (B是高位, C是低位)
    union {
        struct { uint8_t C; uint8_t B; }; // 注意顺序：C是低位
        uint16_t BC;
    };

    // DE 寄存器 (D是高位, E是低位)
    union {
        struct { uint8_t E; uint8_t D; };
        uint16_t DE;
    };

    // HL 寄存器 (H是高位, L是低位)
    union {
        struct { uint8_t L; uint8_t H; };
        uint16_t HL;
    };

    uint16_t SP; // 栈指针 (Stack Pointer)
    uint16_t PC; // 程序计数器 (Program Counter)

    // --- 辅助函数区 ---

    // 读标志位 (就像读变量一样简单)
    bool getZ() const { return (F & FLAG_Z) != 0; }
    bool getN() const { return (F & FLAG_N) != 0; }
    bool getH() const { return (F & FLAG_H) != 0; }
    bool getC() const { return (F & FLAG_C) != 0; }

    // 写标志位 (封装了麻烦的位运算)
    void setZ(bool val) { if (val) F |= FLAG_Z; else F &= ~FLAG_Z; }
    void setN(bool val) { if (val) F |= FLAG_N; else F &= ~FLAG_N; }
    void setH(bool val) { if (val) F |= FLAG_H; else F &= ~FLAG_H; }
    void setC(bool val) { if (val) F |= FLAG_C; else F &= ~FLAG_C; }
};


class CPU
{
public:
    Registers regs;

    //ALU?
};

