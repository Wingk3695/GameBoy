#include "CPU.h"
#include <iostream>

int main()
{
    using namespace std;
    CPU cpu;
    cpu.regs.AF = 0x1234;
    cout << "AF Register: " << hex << cpu.regs.AF << endl;
    cout << "A Register: " << hex << static_cast<int>(cpu.regs.A) << endl;
    cout << "F Register: " << hex << static_cast<int>(cpu.regs.F) << endl;
    return 0;
}