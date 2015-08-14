#undef FULL
#ifdef STATIC
FP_TYPE gvps_sparse_sampled_hidden_static
#else
FP_TYPE gvps_sparse_sampled_hidden
#endif
   (int* dst, void* context, int nstate,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftransame, gvps_ftran_sampled ftrandiff, gvps_fntran fntran, int nhiddenprune)
{
    #define HIDDEN
    #include "gvps_viterbi.hc"
}

#ifdef STATIC
FP_TYPE gvps_sparse_sampled_static
#else
FP_TYPE gvps_sparse_sampled
#endif
   (int* dst, void* context, int nstate,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftran, gvps_fntran fntran)
{
    #undef HIDDEN
    #include "gvps_viterbi.hc"
}

#define CIRCULAR
#ifdef STATIC
FP_TYPE gvps_sparse_circular_hidden_static
#else
FP_TYPE gvps_sparse_circular_hidden
#endif
   (int* dst, void* context, int nstate,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftransame, gvps_ftran_sampled ftrandiff, gvps_fntran fntran, int nhiddenprune)
{
    #define HIDDEN
    #include "gvps_viterbi.hc"
}

#ifdef STATIC
FP_TYPE gvps_sparse_circular_static
#else
FP_TYPE gvps_sparse_circular
#endif
   (int* dst, void* context, int nstate,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftran, gvps_fntran fntran)
{
    #undef HIDDEN
    #include "gvps_viterbi.hc"
}
#undef CIRCULAR

#define FULL
#ifdef STATIC
FP_TYPE gvps_full_sampled_hidden_static
#else
FP_TYPE gvps_full_sampled_hidden
#endif
   (int* dst, void* context,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftransame, gvps_ftran_sampled ftrandiff, gvps_fntran fntran, int nhiddenprune)
{
    #define HIDDEN
    #include "gvps_viterbi.hc"
}

#ifdef STATIC
FP_TYPE gvps_full_sampled_static
#else
FP_TYPE gvps_full_sampled
#endif
   (int* dst, void* context,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftran, gvps_fntran fntran)
{
    #undef HIDDEN
    #include "gvps_viterbi.hc"
}

#define CIRCULAR
#ifdef STATIC
FP_TYPE gvps_full_circular_hidden_static
#else
FP_TYPE gvps_full_circular_hidden
#endif
   (int* dst, void* context,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftransame, gvps_ftran_sampled ftrandiff, gvps_fntran fntran, int nhiddenprune)
{
    #define HIDDEN
    #include "gvps_viterbi.hc"
}

#ifdef STATIC
FP_TYPE gvps_full_circular_static
#else
FP_TYPE gvps_full_circular
#endif
   (int* dst, void* context,
    gvps_obsrv* obsrv,
    gvps_ftran_sampled ftran, gvps_fntran fntran)
{
    #undef HIDDEN
    #include "gvps_viterbi.hc"
}
#undef CIRCULAR

