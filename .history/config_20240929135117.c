#include <stdlib.h>
#include "config.h"

Config create_config (int argc, char *argv[]) {
  Config configuration;
  configuration.tests_num = atoi(argv[1]);

  if (atoi(argv[2]) < 2) {
    configuration.min = 2;
  } else {
    configuration.min = atoi(argv[2]);
  }

  configuration.max = atoi(argv[3]);

  return configuration;
}