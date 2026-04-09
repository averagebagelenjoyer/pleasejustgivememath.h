/* TODO LIST:
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
- rewrite, everything
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

static inline unsigned int xorshift32(void)
{
    unsigned int x = rng_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    rng_state = x;
    return x;
}

static int cmp_double(const void *a, const void *b) {
    double x = *(const double*)a;
    double y = *(const double*)b;
    return (x > y) - (x < y);
}

/**
 * @brief Initalizes the PJGM library. Should be used before any other functions are
 * @return Status, 0 if successful, -1 if unsuccessful
 */
int pjgm_init()
{
    rng_state = time(NULL);

    return 0;
}

/**
 * @brief Generates a pseudorandom integer
 * @param minimum Minimum value (inclusive)
 * @param maximum Maximum value (inclusive)
 * @return A pseudorandom integer in the range of [minimum, maximum]
 *
 * @note This function is not thread-safe due to shared RNG state
 * @warning Behavior is undefined if minimum > maximum
 * @ingroup random
 */
inline int pjgm_random_int(const int minimum, const int maximum)
{
    return minimum + (xorshift32() % (maximum - minimum + 1));
}

/**
 * @brief Generates a pseudorandom float
 * @param minimum Minimum value (inclusive)
 * @param maximum Maximum value (exclusive)
 * @return A pseudorandom float in the range of [minimum, maximum)
 *
 * @note This function is not thread-safe due to shared RNG state
 * @warning Behavior is undefined if minimum > maximum
 * @ingroup random
 */
inline float pjgm_random_float(const float minimum, const float maximum)
{
    return minimum + (xorshift32() * (1.0f / (1ull << 32))) * (maximum - minimum);
}

/**
 * @brief Generates a pseudorandom float
 * @param minimum Minimum value (inclusive)
 * @param maximum Maximum value (exclusive)
 * @return A pseudorandom float in the range of [minimum, maximum)
 *
 * @note This function is not thread-safe due to shared RNG state
 * @warning Behavior is undefined if minimum > maximum
 * @ingroup random
 */
inline double pjgm_random_double(const double minimum, const double maximum)
{
    return minimum + (xorshift32() * (1.0f / (1ull << 32))) * (maximum - minimum);
}

/**
 * @brief Clamps a value between two other values
 * @param minimum Lower bound
 * @param maximum Upper bound
 * @param value The value to clamp
 * @return The clamped value
 *
 * @warning Behavior is undefined if minimum > maximum
 */
inline float clamp(const float minimum, const float maximum, const float value)
{
    if (value < minimum)
        return minimum;
    if (value > maximum)
        return maximum;
    return value;
}
