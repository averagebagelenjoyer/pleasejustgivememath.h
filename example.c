#include "pjgm.h"
#include "stdio.h"

int main(void)
{
    (void)pjgm_init();
    (void)printf("RANDOM NUMBERS:\n");

    for (int index = 0; index < 10; index++)
    {
        float randomFloat = pjgm_random_float(5, 10);
        int randomInt = pjgm_random_int(5, 10);

        (void)printf("Integer #%i: %i\n", index + 1, randomInt);
        (void)printf("Float #%i:   %f\n", index + 1, randomFloat);
    }

    return 0;
}
