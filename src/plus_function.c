#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>
#include <math.h>

float w = 1.0;

float plus_w(float w){

  w = w+1.0;

  return w;
}


float mul_w(float w){
  w = w*2;
  return w;
}
