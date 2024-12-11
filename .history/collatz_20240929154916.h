#ifndef COLLATZ_H
#define COLLATZ_H

typedef struct {
  unsigned long long tests_num;
  unsigned long long min;
  unsigned long long max;
} Config;

Config configure_parameters(char *argv[]);

#endif