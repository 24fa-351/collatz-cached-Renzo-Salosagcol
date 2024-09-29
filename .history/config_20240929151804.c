#include "config.h"

Config configure_parameters(char *argv[]) {
  Config configuration;

  configuration.tests_num = atoi(argv[1]);

  configuration.min = atoi(argv[2]);
  configuration.max = atoi(argv[3]);

  return configuration;
}