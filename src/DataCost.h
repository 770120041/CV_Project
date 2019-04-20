#ifndef __DATA_COST_UTIL_H__
#define __DATA_COST_UTIL_H__

#include "Util.h"

double data_cost_user_specify(int, int, void *);

double data_cost_max_likely(int, int, void *);

double data_cost_min_likely(int, int, void *);

double data_cost_max_lumin(int, int, void *);

double data_cost_min_lumin(int, int, void *);

double data_cost_erase(int, int, void *);

double data_cost_max_difference(int, int, void *);

double data_cost_contrast(int, int, void *);

#endif // __DATA_COST_UTIL_H__