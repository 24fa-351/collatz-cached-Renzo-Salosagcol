#include <stdbool.h>
#include <stdint.h>
#include "config.h"

#ifndef COLLATZ_H
#define COLLATZ_H

typedef unsigned long long ull;

ull collatz (ull current_value);

#endif