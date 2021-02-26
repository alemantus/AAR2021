/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_squareDetect_api.c
 *
 * Code generation for function '_coder_squareDetect_api'
 *
 */

/* Include files */
#include "_coder_squareDetect_api.h"
#include "rt_nonfinite.h"
#include "squareDetect.h"
#include "squareDetect_data.h"
#include "squareDetect_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo m_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_squareDetect_api",           /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static int16_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *maxlength,
  const char_T *identifier);
static int16_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *pol, const
  char_T *identifier, emxArray_real_T *y);
static int16_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static int16_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *maxlength,
  const char_T *identifier)
{
  int16_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(maxlength), &thisId);
  emlrtDestroyArray(&maxlength);
  return y;
}

static int16_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int16_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 2, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *pol, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(pol), &thisId, y);
  emlrtDestroyArray(&pol);
}

static int16_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int16_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int16", false, 0U, &dims);
  ret = *(int16_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void squareDetect_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                      * const plhs[1])
{
  emxArray_real_T *pol;
  emxArray_real_T *poseW;
  int16_T maxlength;
  real_T unusedExpr[3];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  (void)plhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &pol, 2, &m_emlrtRTEI, true);
  emxInit_real_T(&st, &poseW, 2, &m_emlrtRTEI, true);

  /* Marshall function inputs */
  pol->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "pol", pol);
  poseW->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "poseW", poseW);
  maxlength = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "maxlength");

  /* Invoke the target function */
  squareDetect(&st, pol, poseW, maxlength, unusedExpr);
}

/* End of code generation (_coder_squareDetect_api.c) */
