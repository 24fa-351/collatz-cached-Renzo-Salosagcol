#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
  unsigned long long tests_num;
  unsigned long long min;
  unsigned long long max;

  struct Node {
    unsigned long long coll_num;
    unsigned long long steps;
    int util;
  };

} Config;

Config configure_parameters(char *argv[]);

#endif