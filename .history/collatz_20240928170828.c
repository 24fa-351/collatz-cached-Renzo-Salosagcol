#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

   const unsigned long long int INFORMATION_NUMBER = atoi(argv[1]);
   const char INFORMATION_TYPE = argv[2][0];
   const char *FILE_NAME = argv[3];

   FILE *file_pointer = fopen(FILE_NAME, "r");
   char file_text[256];
   fgets(file_text, sizeof(file_text), file_pointer);
   const int FILE_NUMBER = atoi(file_text);

   const unsigned long long int TARGET_FIB_INDEX = INFORMATION_NUMBER + FILE_NUMBER;

   unsigned long long int fib_series[TARGET_FIB_INDEX + 1];
   for (unsigned long long int index = 0; index < TARGET_FIB_INDEX + 1; index++) {
      fib_series[index] = 0;
   }
   fib_series[1] = 1;
   unsigned long long int result = 0;

   if (INFORMATION_TYPE == 'r') {
      result = fib_r(TARGET_FIB_INDEX, fib_series);
   }
   else if (INFORMATION_TYPE == 'i') {
      result = fib_i(TARGET_FIB_INDEX, fib_series);
   }

   printf("%llu\n", result);
   
   fclose(file_pointer);
   return 0;
}