//*******************************//
//
// Name:			exception.h
// Description:		Includes exception header file.
//
// Author:			Edwin Chen
// Created:			Jan 31, 2016
// Last updated:	Jan 31, 2016
//
//*******************************//

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#ifndef _EXCEPTION
	#include <exception>
	#include "iostream.h"
#endif

namespace CORE {

	class Exception : public _exception {

		// I don't need to put this here 
		// It's just here for reference 
#ifndef _EXCEPTION_DEFINED
		struct _exception {
			int type;       /* exception type - see below */
			char *name;     /* name of function where error occured */
			double arg1;    /* first argument to function */
			double arg2;    /* second argument (if any) to function */
			double retval;  /* value to be returned by function */
		};

#define _EXCEPTION_DEFINED
#endif  /* _EXCEPTION_DEFINED */
	};


	// This is a static exception variable in "GLOBAL" scope of namespace Core outside of the Exception class
	// Everybody in the Core namespace can use this
	static Exception exc;
}


#endif