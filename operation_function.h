//head file of the operation function
// such as crossing and variant
// inherit the data structure
#pragma once
#include "stdafx.h"
#include "data_structure.h"

// operation class
class operation_function :
	public data_structure
{
public:
	operation_function();	// initialize the initial solution set
	~operation_function();	//destructive function
	void func_cross();	// crossing operation
	void func_print();	// output function
	void func_refitness();	//	count the fitness again
	void func_erase();	// eliminate operation
	void func_variant(); // variant operation
	void func_loop();	// iteration and termination
};

