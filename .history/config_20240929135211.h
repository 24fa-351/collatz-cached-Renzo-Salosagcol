#include <stdint.h>

#ifndef CONFIG_H
#define CONFIG_H

typedef unsigned long long ull;

typedef struct {
  ull tests_num;
  ull min;
  ull max;

} Config;

Config create_config (char *argv[]);

#endif