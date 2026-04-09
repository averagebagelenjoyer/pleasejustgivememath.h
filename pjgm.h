#pragma once
#ifndef PJGM_H
#define PJGM_H

/**
 * @mainpage PJGM
 *
 * Welcome to the documentation for PJGM.
 *
 * Best to begin at [PJGM.h](./pjgm_8h.html).
 *
 * Additional information about features can be found in the [README](https://github.com/averagebagelenjoyer/pleasejustgivememath.h).
 */

/** 
 * @defgroup random Random Functions
 * @brief Random functions for different types
 *
 * More detailed description if needed.
 */

int pjgm_init();
inline int pjgm_random_int(const int minimum, const int maximum);
inline float pjgm_random_float(const float minimum, const float maximum);
inline double pjgm_random_double(const double minimum, const double maximum);
inline float clamp(const float minimum, const float maximum, const float value);

#endif
