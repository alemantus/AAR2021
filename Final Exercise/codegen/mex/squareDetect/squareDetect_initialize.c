/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squareDetect_initialize.c
 *
 * Code generation for function 'squareDetect_initialize'
 *
 */

/* Include files */
#include "squareDetect_initialize.h"
#include "_coder_squareDetect_mex.h"
#include "rt_nonfinite.h"
#include "squareDetect.h"
#include "squareDetect_data.h"

/* Function Declarations */
static void squareDetect_once(void);

/* Function Definitions */
static void squareDetect_once(void)
{
  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\alema\\Downloads\\AAR2021-master(1)\\AAR2021-master\\Exercise 7\\squareDetect.m",
                  0U, 1U, 7U, 3U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "squareDetect", 0, -1, 1186);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 1067, -1, 1179);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1033, -1, 1054);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 991, -1, 1012);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 383, -1, 959);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 334, -1, 361);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 218, -1, 247);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 55, -1, 153);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 187, 209, 262, 265);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 303, 325, 376, 379);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 962, 982, 1024, 1064);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 155, 178, 265);
  covrtForInit(&emlrtCoverageInstance, 0U, 1U, 268, 294, 379);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\alema\\Downloads\\AAR2021-master\\AAR2021-master\\Exercise 7\\lsqline.m",
                  1U, 1U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "lsqline", 0, -1, 544);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 521, -1, 537);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 489, -1, 505);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 454, -1, 470);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 421, -1, 427);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 113, -1, 405);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 408, 416, -1, 518);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 433, 445, 476, 514);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
}

void squareDetect_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Image_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    squareDetect_once();
  }
}

/* End of code generation (squareDetect_initialize.c) */
