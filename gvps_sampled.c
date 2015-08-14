#include "gvps.h"
#include <malloc.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : (- (x)))
#define nprestore 15

#define SAMPLED

#undef STATIC
#include "gvps_sampled.hc"

#define STATIC
#include "gvps_sampled.hc"

