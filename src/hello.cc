#include "hello.h"

// Returns 1 if given year is a leap year, 0 other wise, 
// Returns -1 if input is negative
int IsLeapYear(int yy) {
  if(yy < 0) return -1;
  if(yy % 400 == 0 || (yy % 100 != 0 && yy % 4 == 0)) 
    return 1;
  else
    return 0;
}