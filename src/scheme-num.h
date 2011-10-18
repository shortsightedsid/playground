#ifndef __SCHEME_NUM__H
#define __SCHEME_NUM__H

#include "scheme.h"
#include "scheme-private.h"

SCM_NUM num_add(SCM_NUM a, SCM_NUM b);
SCM_NUM num_mul(SCM_NUM a, SCM_NUM b);
SCM_NUM num_div(SCM_NUM a, SCM_NUM b);
SCM_NUM num_intdiv(SCM_NUM a, SCM_NUM b);
SCM_NUM num_sub(SCM_NUM a, SCM_NUM b);
SCM_NUM num_rem(SCM_NUM a, SCM_NUM b);
SCM_NUM num_mod(SCM_NUM a, SCM_NUM b);
int num_eq(SCM_NUM a, SCM_NUM b);
int num_gt(SCM_NUM a, SCM_NUM b);
int num_ge(SCM_NUM a, SCM_NUM b);
int num_lt(SCM_NUM a, SCM_NUM b);
int num_le(SCM_NUM a, SCM_NUM b);

#endif
