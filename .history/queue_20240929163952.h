#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
  unsigned long long queue_list[10];

} Queue;

unsigned long long getIndex(void);

#endif