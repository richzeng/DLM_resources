//DLM_Skeleton.cpp

/******************************************************************************
Copyright (c) Richie Zeng rfzeng@lbl.gov
Date: May 2012
Lawrence Berkeley National Lab

A skeleton DLM to provide a reference for other developers.
******************************************************************************/

#include "ExampleDLM.h"


int IDL_Load(void)
{
  /* Call the startup function to add the routines to IDL. */

	/* Functions names in the strings are recognized by IDL and must be in all caps */
  /* NOTE: Make sure to rename the placeholder functions so they don't pollute the namespace. */
	static IDL_SYSFUN_DEF2 ex_functions[] = {
    {(IDL_FUN_RET)hello_func, "EX_HELLO_FUNC", 0, 1, 0, 0},
    {(IDL_FUN_RET)simple_int, "EX_SIMPLE_INT", 1, 1, 0, 0},
    {(IDL_FUN_RET)simple_uint, "EX_SIMPLE_UINT", 1, 1, 0, 0},
    {(IDL_FUN_RET)copy_array, "EX_COPY_ARRAY", 1, 1, 0, 0},
  };

  static IDL_SYSFUN_DEF2 ex_procedures[] = {
    {(IDL_SYSRTN_GENERIC)hello_proc, "EX_HELLO_PROC", 0, 1, 0, 0},
    {(IDL_SYSRTN_GENERIC)pass_scalar_by_ref, "EX_PASS_SCALAR_BY_REF", 1, 1, 0, 0},
    {(IDL_SYSRTN_GENERIC)inplace_array, "EX_INPLACE_ARRAY", 1, 1, 0, 0},
    {(IDL_SYSRTN_GENERIC)is_even, "EX_IS_EVEN", 1, 1, IDL_SYSFUN_DEF_F_KEYWORDS, 0},
	};

	return IDL_SysRtnAdd(ex_functions, IDL_TRUE, ARRLEN(ex_functions)) &&
		IDL_SysRtnAdd(ex_procedures, IDL_FALSE, ARRLEN(ex_procedures));
}
