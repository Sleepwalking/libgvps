#include "gvps.h"
#include <malloc.h>
#include <string.h>

gvps_obsrv* gvps_obsrv_create(int T)
{
    gvps_obsrv* ret = malloc(sizeof(gvps_obsrv));
    ret -> slice = calloc(T, sizeof(gvps_obsrv_slice*));
    ret -> T = T;
    memset(ret -> slice, 0, T * sizeof(gvps_obsrv_slice*));
    return ret;
}

gvps_obsrv_slice* gvps_obsrv_slice_create(int nstate)
{
    gvps_obsrv_slice* ret = malloc(sizeof(gvps_obsrv_slice));
    ret -> pair = calloc(nstate, sizeof(gvps_pair));
    ret -> N = nstate;
    return ret;
}

gvps_obsrv* gvps_obsrv_create_full(int T, int nstate)
{
    int t;
    gvps_obsrv* ret = gvps_obsrv_create(T);
    for(t = 0; t < T; t ++)
        ret -> slice[t] = gvps_obsrv_slice_create(nstate);
    return ret;
}

int gvps_obsrv_slice_free(gvps_obsrv_slice* slice)
{
    free(slice -> pair);
    free(slice);
    return 1;
}

int gvps_obsrv_free(gvps_obsrv* seq)
{
    int t;
    for(t = 0; t < seq -> T; t ++)
        if(seq -> slice[t] != 0)
            gvps_obsrv_slice_free(seq -> slice[t]);
    free(seq -> slice);
    free(seq);
    return 1;
}

