#include <stdlib.h>
#include "scheme-num.h"

#define SCM_NUM_IVALUE(n)       (n.is_fixnum?(n).value.ivalue  : (long) (n).value.rvalue)
#define SCM_NUM_RVALUE(n)       (!n.is_fixnum?(n).value.rvalue : (double) (n).value.ivalue)


SCM_NUM num_add(SCM_NUM a, SCM_NUM b)
{
     SCM_NUM ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue + b.value.ivalue;
     } else {
          ret.value.rvalue = SCM_NUM_RVALUE(a) + SCM_NUM_RVALUE(b);
     }

     return ret;
}


SCM_NUM num_mul(SCM_NUM a, SCM_NUM b) 
{
     SCM_NUM ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue * b.value.ivalue;
     } else {
          ret.value.rvalue = SCM_NUM_RVALUE(a) * SCM_NUM_RVALUE(b);
     }

     return ret;
}


SCM_NUM num_div(SCM_NUM a, SCM_NUM b)
{
     SCM_NUM ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum && a.value.ivalue % b.value.ivalue == 0;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue / b.value.ivalue;
     } else {
          ret.value.rvalue = SCM_NUM_RVALUE(a) / SCM_NUM_RVALUE(b);
     }

     return ret;
}


SCM_NUM num_intdiv(SCM_NUM a, SCM_NUM b) 
{
     SCM_NUM ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue / b.value.ivalue;
     } else {
          ret.value.rvalue = SCM_NUM_RVALUE(a) / SCM_NUM_RVALUE(b);
     }

     return ret;
}


SCM_NUM num_sub(SCM_NUM a, SCM_NUM b) 
{
     SCM_NUM ret;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     if(ret.is_fixnum) {
          ret.value.ivalue = a.value.ivalue - b.value.ivalue;
     } else {
          ret.value.rvalue = SCM_NUM_RVALUE(a) - SCM_NUM_RVALUE(b);
     }

     return ret;
}


SCM_NUM num_rem(SCM_NUM a, SCM_NUM b) 
{
     SCM_NUM ret;
     long e1, e2, res;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     e1 = SCM_NUM_IVALUE(a);
     e2 = SCM_NUM_IVALUE(b);

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


SCM_NUM num_mod(SCM_NUM a, SCM_NUM b) 
{
     SCM_NUM ret;
     long e1, e2, res;

     ret.is_fixnum = a.is_fixnum && b.is_fixnum;

     e1 = SCM_NUM_IVALUE(a);
     e2 = SCM_NUM_IVALUE(b);

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


int num_eq(SCM_NUM a, SCM_NUM b) 
{
     int ret;
     int is_fixnum = a.is_fixnum && b.is_fixnum;

     if(is_fixnum) {
          ret = a.value.ivalue == b.value.ivalue;
     } else {
          ret = SCM_NUM_RVALUE(a) == SCM_NUM_RVALUE(b);
     }

     return ret;
}


int num_gt(SCM_NUM a, SCM_NUM b) 
{
     int ret;
     int is_fixnum = a.is_fixnum && b.is_fixnum;

     if(is_fixnum) {
          ret = a.value.ivalue > b.value.ivalue;
     } else {
          ret = SCM_NUM_RVALUE(a) > SCM_NUM_RVALUE(b);
     }

     return ret;
}


int num_ge(SCM_NUM a, SCM_NUM b)
{
     return !num_lt(a,b);
}


int num_lt(SCM_NUM a, SCM_NUM b) 
{
     int ret;
     int is_fixnum=a.is_fixnum && b.is_fixnum;

     if(is_fixnum) {
          ret = a.value.ivalue < b.value.ivalue;
     } else {
          ret = SCM_NUM_RVALUE(a) < SCM_NUM_RVALUE(b);
     }

     return ret;
}


int num_le(SCM_NUM a, SCM_NUM b) 
{
     return !num_gt(a,b);
}


INLINE SCM_NUM nvalue(pointer p)
{ 
     return ((p)->_object._number); 
}
