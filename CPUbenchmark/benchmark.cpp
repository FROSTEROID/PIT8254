#ifdef __BORLANDC__
    #include <stdlib.h>
    #include <iostream.h>
#else
    #include <iostream>
#endif

#include "CPUports.h"

#ifndef __BORLANDC__
    using namespace std;
#endif
    
int main (int argc, char** argv){
    if(!TakePermissions()){
		cout<<"Couldn't take permissions for ports direct usage.\n"
			<<"Maybe should run as root or use DOS?\n";
		return 1;
	}

	// Lab2	Tasks:
	// 1 Set counter's period to it's maximum
	// 2 Read counter's value
	// 3 Calculate some shit
	// 4 Read counter's value once again
	// 5 Get the difference between counter's values and output it

	return 0;
}

