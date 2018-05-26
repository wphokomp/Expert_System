#include "../inc/exp_sys.h"

bool calculate(bool op1, bool op2, char _operator) {
    if (_operator == '+') {
        return (op1 && op2);
    } else if (_operator == '|') {
        return (op1 || op2);
    } else if (_operator == '^') {
        return (op1 ^ op2);
    } else if (_operator == '!') {
        return !(op1);
    }
    return false;
}
