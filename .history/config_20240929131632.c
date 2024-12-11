#include <stdio.h>
#include "config.h"

Config create_config (int argc, char *argv[]) {
  Config configuration;
  configuration.test_sample = atoi(argv[1]);
  configuration.min = atoi(argv[2]);
  configuration.max = atoi(argv[3]);

  return configuration;
}