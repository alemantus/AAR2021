/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squareDetect.c
 *
 * Code generation for function 'squareDetect'
 *
 */

/* Include files */
#include "squareDetect.h"
#include "libmwippfilter.h"
#include "rt_nonfinite.h"
#include "squareDetect_data.h"
#include "squareDetect_emxutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 37,    /* lineNo */
  "squareDetect",                      /* fcnName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 40,  /* lineNo */
  "squareDetect",                      /* fcnName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 14,  /* lineNo */
  "imgaussfilt",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 24,  /* lineNo */
  "spatialGaussianFilter",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 106, /* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 110, /* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 857, /* lineNo */
  "padImage",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 20,  /* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 80,  /* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 736, /* lineNo */
  "getPaddingIndices",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 931, /* lineNo */
  "filterPartOrWhole",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 1005,/* lineNo */
  "imfiltercore",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 16,  /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 38,  /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 77,  /* lineNo */
  "maximum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  1,                                   /* iLast */
  100,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  846,                                 /* lineNo */
  9,                                   /* colNo */
  "ReplicatePad",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  846,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "ReplicatePad",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  13,                                  /* colNo */
  "dist",                              /* aName */
  "squareDetect",                      /* fName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 22,  /* lineNo */
  9,                                   /* colNo */
  "squareDetect",                      /* fName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m"/* pName */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  13,                                  /* colNo */
  "dist",                              /* aName */
  "squareDetect",                      /* fName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  3,                                   /* colNo */
  "x",                                 /* aName */
  "squareDetect",                      /* fName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  3,                                   /* colNo */
  "y",                                 /* aName */
  "squareDetect",                      /* fName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 95,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  1,                                   /* colNo */
  "dist",                              /* aName */
  "squareDetect",                      /* fName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 830,   /* lineNo */
  33,                                  /* colNo */
  "ReplicatePad",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 83,  /* lineNo */
  56,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = { 7, /* lineNo */
  1,                                   /* colNo */
  "squareDetect",                      /* fName */
  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 736,/* lineNo */
  12,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 845,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 857,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1005,/* lineNo */
  11,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 839,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 845,/* lineNo */
  30,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

/* Function Definitions */
void squareDetect(const emlrtStack *sp, const emxArray_real_T *pol, const
                  emxArray_real_T *poseW, int16_T maxlength, const real_T
                  square[3])
{
  emxArray_real_T *dist;
  int32_T loop_ub;
  int32_T i;
  int32_T b_i;
  int32_T exitg1;
  real_T outSizeT[2];
  uint32_T u;
  uint32_T maxval;
  emxArray_int32_T *idxA;
  emxArray_uint32_T *idxDir;
  int32_T b_idxDir[1];
  emxArray_uint32_T *y;
  real_T d;
  emxArray_real_T *a;
  int32_T j;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  real_T padSizeT[2];
  real_T sizeA[2];
  static const real_T kernel[25] = { 0.0029690167439504968, 0.013306209891013651,
    0.021938231279714643, 0.013306209891013651, 0.0029690167439504968,
    0.013306209891013651, 0.059634295436180138, 0.098320331348845769,
    0.059634295436180138, 0.013306209891013651, 0.021938231279714643,
    0.098320331348845769, 0.16210282163712664, 0.098320331348845769,
    0.021938231279714643, 0.013306209891013651, 0.059634295436180138,
    0.098320331348845769, 0.059634295436180138, 0.013306209891013651,
    0.0029690167439504968, 0.013306209891013651, 0.021938231279714643,
    0.013306209891013651, 0.0029690167439504968 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  (void)square;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &dist, 2, &c_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /* maxlength = 4; */
  loop_ub = pol->size[1];
  i = dist->size[0] * dist->size[1];
  dist->size[0] = 1;
  dist->size[1] = pol->size[1];
  emxEnsureCapacity_real_T(sp, dist, i, &c_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    dist->data[i] = pol->data[2 * i + 1];
  }

  b_i = 0;
  do {
    exitg1 = 0;
    if (b_i <= pol->size[1] - 1) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      i = b_i + 1;
      if ((i < 1) || (i > pol->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, pol->size[1], &c_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, pol->data[2 * b_i + 1] <
                     maxlength)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
        exitg1 = 1;
      } else {
        b_i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  i = (int32_T)(((-1.0 - (real_T)pol->size[1]) + 1.0) / -1.0);
  emlrtForLoopVectorCheckR2012b(pol->size[1], -1.0, 1.0, mxDOUBLE_CLASS, i,
    &emlrtRTEI, sp);
  b_i = 0;
  do {
    exitg1 = 0;
    if (b_i <= i - 1) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 1);
      loop_ub = pol->size[1] - b_i;
      if ((loop_ub < 1) || (loop_ub > pol->size[1])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, pol->size[1], &d_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, pol->data[2 * (loop_ub -
            1) + 1] < maxlength)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
        exitg1 = 1;
      } else {
        b_i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
  loop_ub = pol->size[1] - 1;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (pol->data[2 * b_i + 1] >= maxlength) {
      i = b_i + 1;
      if ((i < 1) || (i > poseW->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, poseW->size[1], &e_emlrtBCI, sp);
      }
    }
  }

  loop_ub = pol->size[1] - 1;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (pol->data[2 * b_i + 1] >= maxlength) {
      i = b_i + 1;
      if ((i < 1) || (i > poseW->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, poseW->size[1], &f_emlrtBCI, sp);
      }
    }
  }

  loop_ub = pol->size[1] - 1;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (dist->data[b_i] >= maxlength) {
      i = b_i + 1;
      if ((i < 1) || (i > dist->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, dist->size[1], &g_emlrtBCI, sp);
      }

      dist->data[i - 1] = rtNaN;
    }
  }

  st.site = &emlrtRSI;
  b_st.site = &c_emlrtRSI;
  c_st.site = &d_emlrtRSI;
  outSizeT[0] = 1.0;
  outSizeT[1] = dist->size[1];
  if (dist->size[1] != 0) {
    d_st.site = &e_emlrtRSI;
    e_st.site = &g_emlrtRSI;
    f_st.site = &h_emlrtRSI;
    f_st.site = &i_emlrtRSI;
    g_st.site = &k_emlrtRSI;
    u = (uint32_T)dist->size[1];
    maxval = u + 4U;
    if (5U >= maxval) {
      maxval = 5U;
    }

    if ((real_T)maxval != (int32_T)maxval) {
      emlrtIntegerCheckR2012b(maxval, &emlrtDCI, &g_st);
    }

    emxInit_int32_T(&g_st, &idxA, 2, &j_emlrtRTEI, true);
    emxInit_uint32_T(&g_st, &idxDir, 2, &k_emlrtRTEI, true);
    i = idxA->size[0] * idxA->size[1];
    idxA->size[0] = (int32_T)maxval;
    idxA->size[1] = 2;
    emxEnsureCapacity_int32_T(&g_st, idxA, i, &d_emlrtRTEI);
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = 5;
    emxEnsureCapacity_uint32_T(&g_st, idxDir, i, &e_emlrtRTEI);
    idxDir->data[2] = 1U;
    idxDir->data[0] = 1U;
    idxDir->data[3] = 1U;
    idxDir->data[1] = 1U;
    idxDir->data[4] = 1U;
    i = (int32_T)maxval;
    if (5 > i) {
      emlrtDynamicBoundsCheckR2012b(5, 1, i, &b_emlrtBCI, &g_st);
    }

    b_idxDir[0] = 5;
    emlrtSubAssignSizeCheckR2012b(&b_idxDir[0], 1, &idxDir->size[0], 2,
      &emlrtECI, &g_st);
    for (i = 0; i < 5; i++) {
      idxA->data[i] = (int32_T)idxDir->data[i];
    }

    emxInit_uint32_T(&g_st, &y, 2, &l_emlrtRTEI, true);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = dist->size[1];
    y->size[1] = loop_ub;
    emxEnsureCapacity_uint32_T(&g_st, y, i, &f_emlrtRTEI);
    loop_ub--;
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = i + 1U;
    }

    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1] + 4;
    emxEnsureCapacity_uint32_T(&g_st, idxDir, i, &e_emlrtRTEI);
    idxDir->data[0] = 1U;
    idxDir->data[1] = 1U;
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxDir->data[i + 2] = y->data[i];
    }

    idxDir->data[y->size[1] + 2] = u;
    idxDir->data[y->size[1] + 3] = u;
    emxFree_uint32_T(&y);
    if ((idxDir->size[1] < 1) || (idxDir->size[1] > idxA->size[0])) {
      emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, idxA->size[0],
        &b_emlrtBCI, &g_st);
    }

    emlrtSubAssignSizeCheckR2012b(&idxDir->size[1], 1, &idxDir->size[0], 2,
      &emlrtECI, &g_st);
    loop_ub = idxDir->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxA->data[i + idxA->size[0]] = (int32_T)idxDir->data[i];
    }

    emxFree_uint32_T(&idxDir);
    d = (real_T)dist->size[0] + 4.0;
    if (d != (int32_T)d) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &e_st);
    }

    d = (real_T)dist->size[1] + 4.0;
    i = (int32_T)d;
    if (d != i) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &e_st);
    }

    emxInit_real_T(&e_st, &a, 2, &i_emlrtRTEI, true);
    loop_ub = a->size[0] * a->size[1];
    a->size[0] = 5;
    a->size[1] = i;
    emxEnsureCapacity_real_T(&e_st, a, loop_ub, &g_emlrtRTEI);
    for (j = 0; j < i; j++) {
      loop_ub = j + 1;
      i1 = idxA->data[(loop_ub + idxA->size[0]) - 1];
      i2 = j + 1;
      for (b_i = 0; b_i < 5; b_i++) {
        i3 = b_i + 1;
        if (i3 > idxA->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, idxA->size[0], &h_emlrtBCI, &e_st);
        }

        i3 = idxA->data[i3 - 1];
        if ((i3 < 1) || (i3 > 1)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 1, &emlrtBCI, &e_st);
        }

        if ((loop_ub < 1) || (loop_ub > idxA->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, idxA->size[0], &i_emlrtBCI,
            &e_st);
        }

        if ((i1 < 1) || (i1 > dist->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, dist->size[1], &i_emlrtBCI, &e_st);
        }

        if ((i2 < 1) || (i2 > a->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, a->size[1], &j_emlrtBCI, &e_st);
        }

        a->data[b_i + 5 * (i2 - 1)] = dist->data[i1 - 1];
      }
    }

    emxFree_int32_T(&idxA);
    d_st.site = &f_emlrtRSI;
    e_st.site = &l_emlrtRSI;
    f_st.site = &m_emlrtRSI;
    i = dist->size[0] * dist->size[1];
    dist->size[0] = 1;
    dist->size[1] = (int32_T)outSizeT[1];
    emxEnsureCapacity_real_T(&f_st, dist, i, &h_emlrtRTEI);
    padSizeT[0] = a->size[0];
    sizeA[0] = 5.0;
    padSizeT[1] = a->size[1];
    sizeA[1] = 5.0;
    ippfilter_real64(&a->data[0], &dist->data[0], outSizeT, 2.0, padSizeT,
                     kernel, sizeA, false);
    emxFree_real_T(&a);
  }

  emxFree_real_T(&dist);
  st.site = &b_emlrtRSI;
  b_st.site = &o_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  d_st.site = &q_emlrtRSI;
  emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
    "Coder:toolbox:eml_min_or_max_varDimZero",
    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
}

/* End of code generation (squareDetect.c) */
