#include <stdio.h>
#include <limits.h>

int main(void) 
{
    /*printf("CHAR_MIN=%d, CHAR_MAX=%d, SHORT_MIN=%d, SHORT_MAX=%d, INT_MIN=%d, INT_MAX=%d, LONG_MIN=%d, LONG_MAX=%d", CHAR_MIN, CHAR_MAX, SHO, SHORT_MAX, INT_MIN, INT_MAX, LONG_MIN, LONG_MAX)*/
    printf("SIGNED:\nCHAR_MIN=%d, CHAR_MAX=%d, SHRT_MIN=%d, SHRT_MAX=%d, INT_MIN=%d, INT_MAX=%d, LONG_MIN=%ld, LONG_MAX=%ld\n", CHAR_MIN, CHAR_MAX, SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN, LONG_MAX);
    printf("UNSIGNED:\nUCHAR_MIN=%u, UCHAR_MAX=%u, USHRT_MIN=%u, USHRT_MAX=%u, UINT_MIN=%u, UINT_MAX=%u, ULONG_MIN=%lu, ULONG_MAX=%lu\n", 0, UCHAR_MAX, 0, SHRT_MAX, 0, UINT_MAX, 0L, ULONG_MAX);
    return 0;
}
