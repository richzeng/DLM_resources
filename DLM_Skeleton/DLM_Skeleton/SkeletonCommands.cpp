//SkeletonCommands.cpp

/******************************************************************************
Copyright (c) Richie Zeng rfzeng@lbl.gov
Date: May 2012
Lawrence Berkeley National Lab


IDL wrapper to support functions from the PVCam API. Adapted from code written
by Bob Gunion in 2008.

******************************************************************************/

#include "DLM_Skeleton.h"


void IDL_CDECL hello_proc(int argc, IDL_VPTR argv[], char *argk) {
  IDL_Message(IDL_M_NAMED_GENERIC, IDL_MSG_INFO, "Hello world! (procedure)");
}

IDL_VPTR IDL_CDECL hello_func(int argc, IDL_VPTR argv[], char *argk) {
  IDL_Message(IDL_M_NAMED_GENERIC, IDL_MSG_INFO, "Hello world! (function)");
  return(IDL_GettmpLong(1));
}
