#include <stdint.h>

#ifndef CONFIG_H
#define CONFIG_H

typedef unsigned long long ull;

typedef struct {
  ull test_sample;
  ull min;
  ull max;

} Config;

Config create_config (int argc, char *argv[]);

#endif