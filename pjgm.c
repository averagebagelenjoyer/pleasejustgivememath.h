/* TODO LIST:
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
*/

#include "pjgm.h"
#include <stdlib.h>
#include <time.h>

static unsigned int rng_state = 0;

int pjgm_init()
{
    rng_state = time(NULL);

    return 0;
}

static inline unsigned int xorshift32(void)
{
    unsigned int x = rng_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    rng_state = x;
    return x;
}

inline int pjgm_random_int(const int minimum, const int maximum)
{
    return minimum + (xorshift32() % (maximum - minimum + 1));
}

inline float pjgm_random_float(const float minimum, const float maximum)
{
    return minimum + (xorshift32() * (1.0f / (1ull << 32))) * (maximum - minimum);
}

inline float clamp(const float minimum, const float maximum, const float value)
{
    if (value < minimum)
        return minimum;
    if (value > maximum)
        return maximum;
    return value;
}
