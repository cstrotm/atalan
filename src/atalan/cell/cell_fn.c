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

#include "../language.h"

Cell * NewFn(Type * type, InstrBlock * instr)
{
	Var * var;
	var = NewCell(INSTR_FN);
	var->type  = type;
	var->instr = instr;
	return var;
}

Bool IsFnVar(Var * var)
{
	return var != NULL && var->mode == INSTR_VAR && var->type->mode == INSTR_FN;
}

Bool IsFnImplemented(Var * fn_cell)
{
	ASSERT(fn_cell->mode == INSTR_FN);
	return fn_cell->instr != NULL && fn_cell->instr->first != NULL && fn_cell->instr->first->op != INSTR_USES;
}

void FnSetCode(Cell * fn, InstrBlock * code)
{
	ASSERT(fn->mode == INSTR_FN);
	fn->instr = code;
}

InstrBlock * FnVarCode(Var * proc)
{
	ASSERT(proc->mode == INSTR_VAR);
	ASSERT(proc->type->mode == INSTR_FN);
	return proc->type->instr;
}

Bool VarIsInArg(Var * fn_var, Var * var)
{
	Var * fn;
	ASSERT(fn_var->mode == INSTR_VAR);
	fn = fn_var->type;
	ASSERT(fn->mode == INSTR_FN);

	return ContainsItem(ArgType(fn->type), var);
}

Bool VarIsOutArg(Var * fn_var, Var * var)
{
	Var * fn;
	ASSERT(fn_var->mode == INSTR_VAR);
	fn = fn_var->type;
	ASSERT(fn->mode == INSTR_FN);

	return ContainsItem(ResultType(fn->type), var);
}