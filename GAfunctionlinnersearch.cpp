// GAfunctionlinnersearch.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "GAfunctionlinnersearch.h"

//the main function
int main()
{
	func_start();
	// count the run duration
	clock_t start_time = clock();
	clock_t end_time = clock();
	// several groups of examples
	for (ll i = 0; i < 1; i++)
	{
		cout << "testing" << endl;
		operation_function test;	//testing
		test.Cities::func_print();	//output
		test.func_print();
		//test.func_print();

		test.func_cross();
		test.func_print();
		test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross(); test.func_cross();
		//test.func_print();
		test.func_print();
		test.func_loop();
		test.func_print();

		cout << "finish"<<endl;
	}
	cout << endl << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	getchar(); getchar(); getchar(); getchar();
    return 0;
}

