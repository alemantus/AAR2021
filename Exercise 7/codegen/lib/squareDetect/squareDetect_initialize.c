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
#include "rt_nonfinite.h"
#include "squareDetect.h"
#include "squareDetect_data.h"

/* Function Definitions */
void squareDetect_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_squareDetect = true;
}

/* End of code generation (squareDetect_initialize.c) */
