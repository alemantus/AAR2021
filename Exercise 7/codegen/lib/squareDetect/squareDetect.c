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
#include "squareDetect_initialize.h"

/* Function Definitions */
void squareDetect(const emxArray_real_T *pol, const emxArray_real_T *poseW,
                  short maxlength, const double square[3])
{
  emxArray_real_T *dist;
  int loop_ub;
  int j;
  int i;
  double outSizeT[2];
  emxArray_int32_T *idxA;
  emxArray_uint32_T *y;
  emxArray_int32_T *r;
  unsigned int u;
  emxArray_uint32_T *idxDir;
  emxArray_real_T *a;
  double padSizeT[2];
  double sizeA[2];
  static const double kernel[25] = { 0.0029690167439504968, 0.013306209891013651,
    0.021938231279714643, 0.013306209891013651, 0.0029690167439504968,
    0.013306209891013651, 0.059634295436180138, 0.098320331348845769,
    0.059634295436180138, 0.013306209891013651, 0.021938231279714643,
    0.098320331348845769, 0.16210282163712664, 0.098320331348845769,
    0.021938231279714643, 0.013306209891013651, 0.059634295436180138,
    0.098320331348845769, 0.059634295436180138, 0.013306209891013651,
    0.0029690167439504968, 0.013306209891013651, 0.021938231279714643,
    0.013306209891013651, 0.0029690167439504968 };

  (void)poseW;
  (void)square;
  if (!isInitialized_squareDetect) {
    squareDetect_initialize();
  }

  emxInit_real_T(&dist, 2);

  /* maxlength = 4; */
  loop_ub = pol->size[1];
  j = dist->size[0] * dist->size[1];
  dist->size[0] = 1;
  dist->size[1] = pol->size[1];
  emxEnsureCapacity_real_T(dist, j);
  for (j = 0; j < loop_ub; j++) {
    dist->data[j] = pol->data[2 * j + 1];
  }

  loop_ub = pol->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    if (dist->data[i] >= maxlength) {
      dist->data[i] = rtNaN;
    }
  }

  outSizeT[0] = 1.0;
  outSizeT[1] = dist->size[1];
  if (dist->size[1] != 0) {
    emxInit_int32_T(&idxA, 2);
    emxInit_uint32_T(&y, 2);
    emxInit_int32_T(&r, 2);
    j = idxA->size[0] * idxA->size[1];
    if (5U < dist->size[1] + 4U) {
      idxA->size[0] = (int)(dist->size[1] + 4U);
    } else {
      idxA->size[0] = 5;
    }

    idxA->size[1] = 2;
    emxEnsureCapacity_int32_T(idxA, j);
    j = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 1;
    emxEnsureCapacity_int32_T(r, j);
    r->data[0] = 1;
    idxA->data[2] = r->data[0];
    idxA->data[0] = 1;
    idxA->data[3] = 1;
    idxA->data[1] = 1;
    idxA->data[4] = 1;
    j = y->size[0] * y->size[1];
    y->size[0] = 1;
    u = (unsigned int)dist->size[1];
    loop_ub = (int)u;
    y->size[1] = loop_ub;
    emxEnsureCapacity_uint32_T(y, j);
    loop_ub--;
    emxFree_int32_T(&r);
    for (j = 0; j <= loop_ub; j++) {
      y->data[j] = j + 1U;
    }

    emxInit_uint32_T(&idxDir, 2);
    j = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1] + 4;
    emxEnsureCapacity_uint32_T(idxDir, j);
    idxDir->data[0] = 1U;
    idxDir->data[1] = 1U;
    loop_ub = y->size[1];
    for (j = 0; j < loop_ub; j++) {
      idxDir->data[j + 2] = y->data[j];
    }

    idxDir->data[y->size[1] + 2] = u;
    idxDir->data[y->size[1] + 3] = u;
    loop_ub = idxDir->size[1];
    emxFree_uint32_T(&y);
    for (j = 0; j < loop_ub; j++) {
      idxA->data[j + idxA->size[0]] = (int)idxDir->data[j];
    }

    emxFree_uint32_T(&idxDir);
    emxInit_real_T(&a, 2);
    j = a->size[0] * a->size[1];
    a->size[0] = 5;
    loop_ub = dist->size[1] + 4;
    a->size[1] = loop_ub;
    emxEnsureCapacity_real_T(a, j);
    for (j = 0; j < loop_ub; j++) {
      for (i = 0; i < 5; i++) {
        a->data[i + 5 * j] = dist->data[idxA->data[j + idxA->size[0]] - 1];
      }
    }

    emxFree_int32_T(&idxA);
    j = dist->size[0] * dist->size[1];
    dist->size[0] = 1;
    dist->size[1] = (int)outSizeT[1];
    emxEnsureCapacity_real_T(dist, j);
    padSizeT[0] = a->size[0];
    sizeA[0] = 5.0;
    padSizeT[1] = a->size[1];
    sizeA[1] = 5.0;
    ippfilter_real64(&a->data[0], &dist->data[0], outSizeT, 2.0, padSizeT,
                     kernel, sizeA, false);
    emxFree_real_T(&a);
  }

  emxFree_real_T(&dist);
}

/* End of code generation (squareDetect.c) */
