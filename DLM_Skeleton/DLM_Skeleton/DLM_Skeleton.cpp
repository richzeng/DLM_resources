//DLM_Skeleton.cpp

/******************************************************************************
Copyright (c) Richie Zeng rfzeng@lbl.gov
Date: May 2012
Lawrence Berkeley National Lab

A skeleton DLM to provide a reference for other developers.
******************************************************************************/

#include "DLM_Skeleton.h"


int IDL_Load(void)
{
  /* Call the startup function to add the routines to IDL. */

	/* Functions in the strings are recognized by IDL and must be in all caps */
  /* NOTE: Make sure to rename the placeholder functions so they don't pollute the namespace. */
	static IDL_SYSFUN_DEF2 skel_functions[] = {
    {(IDL_FUN_RET)hello_func, "HELLO_FUNC", 0, 1, 0, 0},
  };

  static IDL_SYSFUN_DEF2 skel_procedures[] = {
		{(IDL_SYSRTN_GENERIC)hello_proc, "HELLO_PROC", 0, 1, 0, 0},
	};

	return IDL_SysRtnAdd(skel_functions, IDL_TRUE, ARRLEN(skel_functions)) &&
		IDL_SysRtnAdd(skel_procedures, IDL_FALSE, ARRLEN(skel_procedures));
}
