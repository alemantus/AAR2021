/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_squareDetect_mex.c
 *
 * Code generation for function '_coder_squareDetect_mex'
 *
 */

/* Include files */
#include "_coder_squareDetect_mex.h"
#include "_coder_squareDetect_api.h"
#include "squareDetect.h"
#include "squareDetect_data.h"
#include "squareDetect_initialize.h"
#include "squareDetect_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void squareDetect_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
void squareDetect_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        12, "squareDetect");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "squareDetect");
  }

  /* Call the function. */
  squareDetect_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&squareDetect_atexit);

  /* Module initialization. */
  squareDetect_initialize();

  /* Dispatch the entry-point. */
  squareDetect_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  squareDetect_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_squareDetect_mex.c) */
