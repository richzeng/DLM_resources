//ExampleDLM_simple.cpp

/******************************************************************************
Copyright (c) Richie Zeng rfzeng@lbl.gov
Date: May 2012
Lawrence Berkeley National Lab


IDL wrapper to support functions from the PVCam API. Adapted from code written
by Bob Gunion in 2008.

******************************************************************************/

#include "ExampleDLM.h"


void IDL_CDECL hello_proc(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  ex_hello_proc, 1
  ex_hello_proc, "pineapples"
  ex_hello_proc
  */
  IDL_Message(IDL_M_NAMED_GENERIC, IDL_MSG_INFO, "Hello world! (procedure)");
}

IDL_VPTR IDL_CDECL hello_func(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  a = ex_hello_func()
  a = ex_hello_func(1)
  print, ex_hello_func("pie")
  */
  IDL_Message(IDL_M_NAMED_GENERIC, IDL_MSG_INFO, "Hello world! (function)");
  return(IDL_GettmpLong(1));
}

IDL_VPTR IDL_CDECL simple_int(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  a = ex_simple_int(5)
  print,ex_simple_int(-3)
  print,ex_simple_int("hi")
  print,ex_simple_int(4.5)
  */
  IDL_ENSURE_SCALAR(argv[0]);
  int cInt = IDL_LongScalar(argv[0]);
  cInt++;
  return IDL_GettmpLong(cInt);
}

IDL_VPTR IDL_CDECL simple_uint(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  a = ex_simple_uint(5)
  a = ex_simple_uint(-3) ;this is pretty interesting
  */
  IDL_ENSURE_SCALAR(argv[0]);
  int cUInt = IDL_ULongScalar(argv[0]);
  cUInt++;
  return IDL_GettmpULong(cUInt);
}

void IDL_CDECL pass_scalar_by_ref(int argc, IDL_VPTR argv[], char *argk)
{
  /*
  Called in IDL as:
  a = 2
  ex_pass_scalar_by_ref, a
  */
  IDL_ENSURE_SCALAR(argv[0]);
  int var = IDL_LongScalar(argv[0]);
  var++;
  IDL_StoreScalar(argv[0], IDL_TYP_LONG, (IDL_ALLTYPES *) &var);
}