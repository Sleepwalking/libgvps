#ifndef GVPS
#define GVPS

#define FP_TYPE double

typedef struct
{
    FP_TYPE p;
    int state;
    void* ptr;
} gvps_pair;

typedef struct
{
    gvps_pair* pair;
    int N;
} gvps_obsrv_slice;

typedef struct
{
    gvps_obsrv_slice** slice;
    int T;
} gvps_obsrv;

gvps_obsrv* gvps_obsrv_create(int T);
gvps_obsrv* gvps_obsrv_create_full(int T, int nstate);
gvps_obsrv_slice* gvps_obsrv_slice_create(int nstate);
int gvps_obsrv_slice_free(gvps_obsrv_slice* slice);
int gvps_obsrv_free(gvps_obsrv* seq);

typedef FP_TYPE (* gvps_fobsrv)(void* context, int t, int n);
typedef int (* gvps_fnobsrv)(void* context, int t);
typedef FP_TYPE (* gvps_ftran_sampled)(void* context, int ds, int t);
typedef FP_TYPE (* gvps_ftran)(void* context, int s1, int s2, int t2);
typedef int (* gvps_ftrexist)(void* context, int s1, int s2, int t2);
typedef int (* gvps_fntran)(void* context, int t);

#define GVPS_ARG_SPSAMPHIDDEN (int* dst, void* context, int nstate, gvps_obsrv* obsrv, \
    gvps_ftran_sampled ftransame, gvps_ftran_sampled ftrandiff, gvps_fntran fntran, int nhiddenprune)

#define GVPS_ARG_SPSAMP (int* dst, void* context, int nstate, gvps_obsrv* obsrv, \
    gvps_ftran_sampled ftran, gvps_fntran fntran)

#define GVPS_ARG_FULLSAMPHIDDEN (int* dst, void* context, gvps_obsrv* obsrv, \
    gvps_ftran_sampled ftransame, gvps_ftran_sampled ftrandiff, gvps_fntran fntran, int nhiddenprune)

#define GVPS_ARG_FULLSAMP (int* dst, void* context, gvps_obsrv* obsrv, \
    gvps_ftran_sampled ftran, gvps_fntran fntran)

FP_TYPE gvps_sparse_sampled_hidden GVPS_ARG_SPSAMPHIDDEN;
FP_TYPE gvps_sparse_sampled GVPS_ARG_SPSAMP;

FP_TYPE gvps_sparse_circular_hidden GVPS_ARG_SPSAMPHIDDEN;
FP_TYPE gvps_sparse_circular GVPS_ARG_SPSAMP;

FP_TYPE gvps_full_sampled_hidden GVPS_ARG_FULLSAMPHIDDEN;
FP_TYPE gvps_full_sampled GVPS_ARG_FULLSAMP;

FP_TYPE gvps_full_circular_hidden GVPS_ARG_FULLSAMPHIDDEN;
FP_TYPE gvps_full_circular GVPS_ARG_FULLSAMP;

FP_TYPE gvps_sparse_sampled_hidden_static GVPS_ARG_SPSAMPHIDDEN;
FP_TYPE gvps_sparse_sampled_static GVPS_ARG_SPSAMP;

FP_TYPE gvps_sparse_circular_hidden_static GVPS_ARG_SPSAMPHIDDEN;
FP_TYPE gvps_sparse_circular_static GVPS_ARG_SPSAMP;

FP_TYPE gvps_full_sampled_hidden_static GVPS_ARG_FULLSAMPHIDDEN;
FP_TYPE gvps_full_sampled_static GVPS_ARG_FULLSAMP;

FP_TYPE gvps_full_circular_hidden_static GVPS_ARG_FULLSAMPHIDDEN;
FP_TYPE gvps_full_circular_static GVPS_ARG_FULLSAMP;

/* not implemented due to tractability/performance issues
FP_TYPE gvps_full_hidden(int* dst, void* context, gvps_obsrv* obsrv,
    gvps_ftran ftransame, gvps_ftran ftrandiff, gvps_ftrexist ftrexist);
*/
FP_TYPE gvps_full(int* dst, void* context, gvps_obsrv* obsrv,
    gvps_ftran ftran, gvps_ftrexist ftrexist);
FP_TYPE gvps_full_static(int* dst, void* context, gvps_obsrv* obsrv,
    gvps_ftran ftran);

FP_TYPE gvps_variable(int* dst, void* context, gvps_obsrv* obsrv,
    gvps_ftran ftran, gvps_ftrexist ftrexist);

#endif

