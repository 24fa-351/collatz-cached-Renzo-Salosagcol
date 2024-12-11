#include "config.h"

Config create_config (int argc, char *argv[]) {
  Config configuration;
  if (atoi(argv[1]) < 2) {
    configuration.tests_num = 2;
  } else {
    configuration.tests_num = atoi(argv[1]);
  }
  configuration.min = atoi(argv[2]);
  configuration.max = atoi(argv[3]);

  return configuration;
}