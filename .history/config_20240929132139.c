#include "config.h"

Config create_config (int argc, char *argv[]) {
  Config configuration;
  if (atoi(argv[1]) < 2) {
    configuration.tests_num = 2;
  }
  configuration.min = atoi(argv[2]);
  configuration.max = atoi(argv[3]);

  return configuration;
}