#include "gvps.h"
#include <malloc.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : (- (x)))

#define FULL
#define FULLTRAN
FP_TYPE gvps_full(int* dst, void* context, gvps_obsrv* obsrv,
    gvps_ftran ftran, gvps_ftrexist ftrexist)
{
    #define FTREXIST
    #include "gvps_viterbi.hc"
}
#undef FTREXIST

FP_TYPE gvps_full_static(int* dst, void* context, gvps_obsrv* obsrv,
    gvps_ftran ftran)
{
    #define STATIC
    #include "gvps_viterbi.hc"
}

