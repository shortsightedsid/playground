#include <stdlib.h>
#include "scheme.h"
#include "scheme-private.h"
#include "scheme-num.h"

#define num_ivalue(n)       (n.is_fixnum?(n).value.ivalue  : (long) (n).value.rvalue)
#define num_rvalue(n)       (!n.is_fixnum?(n).value.rvalue : (double) (n).value.ivalue)


num num_add(num a, num b)
{
     num ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue + b.value.ivalue;
     } else {
          ret.value.rvalue = num_rvalue(a) + num_rvalue(b);
     }

     return ret;
}


num num_mul(num a, num b) 
{
     num ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue * b.value.ivalue;
     } else {
          ret.value.rvalue = num_rvalue(a) * num_rvalue(b);
     }

     return ret;
}


num num_div(num a, num b)
{
     num ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum && a.value.ivalue % b.value.ivalue == 0;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue / b.value.ivalue;
     } else {
          ret.value.rvalue = num_rvalue(a) / num_rvalue(b);
     }

     return ret;
}


num num_intdiv(num a, num b) 
{
     num ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue / b.value.ivalue;
     } else {
          ret.value.rvalue = num_rvalue(a) / num_rvalue(b);
     }

     return ret;
}


num num_sub(num a, num b) 
{
     num ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue - b.value.ivalue;
     } else {
          ret.value.rvalue = num_rvalue(a) - num_rvalue(b);
     }

     return ret;
}


num num_rem(num a, num b) 
{
     num ret;
     long e1, e2, res;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     e1 = num_ivalue(a);
     e2 = num_ivalue(b);

     res = e1 % e2;

     /* modulo should have same sign as second operand */
     if (res > 0) {
          if (e1 < 0) {
               res -= labs(e2);
          }
     } else if (res < 0) {
          if (e1 > 0) {
               res += labs(e2);
          }
     }

     ret.value.ivalue=res;

     return ret;
}


num num_mod(num a, num b) 
{
     num ret;
     long e1, e2, res;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     e1 = num_ivalue(a);
     e2 = num_ivalue(b);

     res = e1 % e2;

     /* modulo should have same sign as second operand */
     if (res > 0) {
          if (e2 < 0) {
               res *= -1L;
          }
     } else {
          if (e2 > 0) {
               res *= -1L;
          }
     }

     ret.value.ivalue = res;

     return ret;
}


int num_eq(num a, num b) 
{
     int ret;
     int is_fixnum = a.is_fixnum && b.is_fixnum;

     if(is_fixnum) {
          ret = a.value.ivalue == b.value.ivalue;
     } else {
          ret = num_rvalue(a) == num_rvalue(b);
     }

     return ret;
}


int num_gt(num a, num b) 
{
     int ret;
     int is_fixnum = a.is_fixnum && b.is_fixnum;

     if(is_fixnum) {
          ret = a.value.ivalue > b.value.ivalue;
     } else {
          ret = num_rvalue(a) > num_rvalue(b);
     }

     return ret;
}


int num_ge(num a, num b)
{
     return !num_lt(a,b);
}


int num_lt(num a, num b) 
{
     int ret;
     int is_fixnum=a.is_fixnum && b.is_fixnum;

     if(is_fixnum) {
          ret = a.value.ivalue < b.value.ivalue;
     } else {
          ret = num_rvalue(a) < num_rvalue(b);
     }

     return ret;
}


int num_le(num a, num b) 
{
     return !num_gt(a,b);
}
