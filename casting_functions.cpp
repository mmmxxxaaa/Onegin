#include "casting_functions.h"
#include <assert.h>
#include <limits.h>

unsigned long int I64ToU64SafeCast(long int val)
{
    assert(val >= 0);

    return (unsigned long int) val;
}


unsigned long int I32ToU64SafeCast(int val)
{
    assert(val >= 0);

    return (unsigned long int) val;
}


//СИГМА СКИБИДИ
long int U64ToI64SafeCast(unsigned long int val)
{
    assert(val <= LONG_MAX);

    return (long int) val;
}
