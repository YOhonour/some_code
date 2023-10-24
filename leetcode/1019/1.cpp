#include <stddef.h>

void* mymemmove(void* dest, const void* source, size_t count) {
    unsigned char* destPtr = (unsigned char*) dest;
    const unsigned char* srcPtr = (const unsigned char*) source;

    // 如果源和目的地址有重叠，并且源地址在目的地址之后，从后往前拷贝
    if (srcPtr < destPtr && destPtr < srcPtr + count) {
        for (size_t i = count; i > 0; i--) {
            destPtr[i-1] = srcPtr[i-1];
        }
    }
    // 如果没有重叠，或者源地址在目的地址之前，从前往后拷贝
    else {
        for (size_t i = 0; i < count; i++) {
            destPtr[i] = srcPtr[i];
        }
    }

    return dest;
}
