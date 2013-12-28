/*
Function cells

(c) 2010 Rudolf Kudla 
Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php


Function has reference to function type, which defines function arguments and result type.
There is a reference to code.

  mode: INSTR_FN
  type: Cell(INSTR_FN_TYPE)


  Local cells define local variables in the function.

*/

#include "language.h"

Cell * NewFn(Type * type, InstrBlock * instr)
{
	Var * var;
	var = NewCell(INSTR_FN);
	var->type  = type;
	var->instr = instr;
	return var;
}

