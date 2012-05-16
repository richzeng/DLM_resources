//ExampleDLM_complex.cpp

/******************************************************************************
Copyright (c) Richie Zeng rfzeng@lbl.gov
Date: May 2012
Lawrence Berkeley National Lab


IDL wrapper to support functions from the PVCam API. Adapted from code written
by Bob Gunion in 2008.

******************************************************************************/

#include "ExampleDLM.h"


void IDL_CDECL in_place_array(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  ar = intarr(5)
  inplacearraymodification(ar)
  print, ar
  */
  int dim, len;
  int *arr;

  IDL_ENSURE_ARRAY(argv[0]);
  dim = argv[0]->value.arr->n_dim;
  len = argv[0]->value.arr->n_elts;

  //we need to convert the type elements of the array to IDL_LONG
  //IDL_LONGs are the same as C ints
  //the variable tmp is a pointer to the array of longs
  IDL_VPTR tmp = IDL_CvtLng(1, &(argv[0]));

  //grab the integer data from the tmp array
  arr = (int *)tmp->value.arr->data;
  for (int i=0; i < len; i++) {
    arr[i]++;
  }
  if (tmp != argv[0]) {
    //converts the tmp array (now containing ints) back to IDL_VPTRs and copies
    //it to the original argument passed in
    IDL_VarCopy(tmp, argv[0]);
  }
}