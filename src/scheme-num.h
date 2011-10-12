#ifndef __SCHEME_NUM__H
#define __SCHEME_NUM__H

num num_add(num a, num b);
num num_mul(num a, num b);
num num_div(num a, num b);
num num_intdiv(num a, num b);
num num_sub(num a, num b);
num num_rem(num a, num b);
num num_mod(num a, num b);
int num_eq(num a, num b);
int num_gt(num a, num b);
int num_ge(num a, num b);
int num_lt(num a, num b);
int num_le(num a, num b);

#endif
