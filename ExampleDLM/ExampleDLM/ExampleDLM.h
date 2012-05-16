//DLM_Skeleton.h

/******************************************************************************
Copyright (c) Richie Zeng rfzeng@lbl.gov
Date: May 2012
Lawrence Berkeley National Lab

A skeleton DLM to provide a reference for other developers.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "export.h"


#ifndef DLM_SKELETON
#define DLM_SKELETON

/* Handy macro to find the size of an array */
#define ARRLEN(arr) (sizeof(arr)/sizeof(arr[0]))


/* Structure for IDL keywords. Allows IDL to use the error keyword */
typedef struct{
	IDL_KW_RESULT_FIRST_FIELD; /* Must be first entry in structure */
  IDL_VPTR	iError;
} KW_RESULT;

static IDL_KW_PAR kw_pars[] = { IDL_KW_FAST_SCAN,
	{"ERROR",IDL_TYP_UNDEF,1,IDL_KW_OUT|IDL_KW_ZERO,0,(char *)IDL_KW_OFFSETOF(iError)},
	{NULL}
};


extern "C" {
  void IDL_CDECL hello_proc(int argc, IDL_VPTR argv[], char *argk);
  IDL_VPTR IDL_CDECL hello_func(int argc, IDL_VPTR argv[], char *argk);
  IDL_VPTR IDL_CDECL simple_int(int argc, IDL_VPTR argv[], char *argk);
  IDL_VPTR IDL_CDECL simple_uint(int argc, IDL_VPTR argv[], char *argk);

  void IDL_CDECL in_place_array(int argc, IDL_VPTR argv[], char *argk);
}

#endif