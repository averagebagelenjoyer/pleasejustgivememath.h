/* TODO LIST:
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
*/

/**
 * @mainpage PJGM
 *
 * Welcome to the documentation for PJGM.
 *
 * Best to begin at [PJGM.h](./pjgm_8h.html).
 *
 * Additional information about features can be found in the [README](https://github.com/averagebagelenjoyer/pleasejustgivememath.h/blob/documentation/README.md).
 */


/**
 * @file pjgm.h
 * @brief The main library
 * @warning `pjgm_init()` must be ran first, or else undefined behavior may occur
 */

#include "pjgm.h"
#include <stdlib.h>
#include <time.h>

static unsigned int rng_state = 0;

/**
 * @brief Initalizes the library
 * @return Status, 0 if successful, -1 if unsuccessful
 */
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

/**
 * @brief Generates a random integer (pseudorandom)
 * @param minimum Minimum value (exclusive)
 * @param maximum Maximum value (inclusive)
 * @return A random integer between the minimum and maximum
 */
inline int pjgm_random_int(const int minimum, const int maximum)
{
    return minimum + (xorshift32() % (maximum - minimum + 1));
}

/**
 * @brief Generates a random float (pseudorandom)
 * @param minimum Minimum value (exclusive)
 * @param maximum Maximum value (inclusive)
 * @return A random float between the minimum and maximum
 */
inline float pjgm_random_float(const float minimum, const float maximum)
{
    return minimum + (xorshift32() * (1.0f / (1ull << 32))) * (maximum - minimum);
}

/**
 * @brief Clamps a value between two other values
 * @param minimum Minimum value (exclusive)
 * @param maximum Maximum value (inclusive)
 * @param value The value to be clamped
 * @return The clamped value
 */
inline float clamp(const float minimum, const float maximum, const float value)
{
    if (value < minimum)
        return minimum;
    if (value > maximum)
        return maximum;
    return value;
}
