/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squareDetect.h
 *
 * Code generation for function 'squareDetect'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "squareDetect_types.h"

/* Function Declarations */
void squareDetect(const emlrtStack *sp, const emxArray_real_T *pol, const
                  emxArray_real_T *poseW, int16_T maxlength, const real_T
                  square[3]);

/* End of code generation (squareDetect.h) */
