//ExampleDLM_complex.cpp

/******************************************************************************
Copyright (c) Richie Zeng rfzeng@lbl.gov
Date: May 2012
Lawrence Berkeley National Lab


IDL wrapper to support functions from the PVCam API. Adapted from code written
by Bob Gunion in 2008.

******************************************************************************/

#include "ExampleDLM.h"


void IDL_CDECL inplace_array(int argc, IDL_VPTR argv[], char *argk)
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

IDL_VPTR IDL_CDECL copy_array(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  Called in IDL as:
  print, ex_copy_array(indgen(3,3))
  */
  IDL_ENSURE_ARRAY(argv[0]);
  IDL_VPTR returnedArray;
  short *inputArray = (short *) argv[0]->value.arr->data; //pointer to the array
  int nDim = argv[0]->value.arr->n_dim; //dimensions
  int nElts = argv[0]->value.arr->n_elts; //elements

  //outputArray becomes a pointer to the array to be returned
  short *outputArray = (short *) IDL_MakeTempArray((int) IDL_TYP_INT,
                                                   nDim,
                                                   argv[0]->value.arr->dim,
                                                   IDL_ARR_INI_ZERO,
                                                   &returnedArray);
  
  for(int i=0; i<nElts; i++) {
    outputArray[i]++;
  }
  return returnedArray;
}

void IDL_CDECL is_even(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  Called in IDL as:
  ex_is_even, 2, answer=answer
  ex_is_even, 1, answer=answer
  print,answer
  */
  IDL_ENSURE_SCALAR(argv[0]);
  int var = IDL_LongScalar(argv[0]);
  int result;

  if (var%2==0)
    result=1;
  else
    result=0;


  /* Structure for IDL keywords. Allows IDL to use the error keyword */
  typedef struct{
  	IDL_KW_RESULT_FIRST_FIELD; /* Must be first entry in structure */
    IDL_VPTR	iAnswer;
  } KW_RESULT;

  static IDL_KW_PAR kw_pars[] = { IDL_KW_FAST_SCAN,
	  {"ANSWER",IDL_TYP_UNDEF,1,IDL_KW_OUT|IDL_KW_ZERO,0,(char *)IDL_KW_OFFSETOF(iAnswer)},
	  {NULL}
  };
  //NOTE: THE STRUCTURE AND THE KW_PARS CAN BOTH BE PUT IN THE HEADER FILE
  //THIS WAS DONE IN THE PVCAM LIBRARY BECAUSE THEY EACH HAD THE ERROR KEYWORD

  /* Handling the answer keyword */
  KW_RESULT kw;
  argc = IDL_KWProcessByOffset(argc,argv,argk,kw_pars,(IDL_VPTR *)0,1,&kw);
  if (kw.iAnswer) {
    IDL_StoreScalar(kw.iAnswer, IDL_TYP_BYTE, (IDL_ALLTYPES*) &result);
  }
  IDL_KW_FREE;

}