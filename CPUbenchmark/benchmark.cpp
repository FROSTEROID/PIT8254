#ifdef __BORLANDC__
    #include <stdlib.h>
    #include <iostream.h>
#else
    #include <iostream>
#endif

#include "PITctl.h"

#ifndef __BORLANDC__
    using namespace std;
#endif

#ifndef __BORLANDC__
	void delay(int ms){
		this_thread::sleep_for(std::chrono::milliseconds(ms));
	}
#endif
	
PIT2ctl* pit2; 

void Initialize(){
	delay(1000);
	try{
		pit2 = new PIT2ctl();
	}
	catch(const char* ex){
		cout << "Error occured while initializing subclasses.\r\nThe exception says:\r\n{\r\n"
			 << ex
			 << "}\r\n";
	}		
}

int main (int argc, char** argv){
	//cout<<ports.TakePermission(0x61, 1);
	Initialize();
	// Lab2	Tasks:
	// 1 Set counter's period to it's maximum
	// 2 Read counter's value
	// 3 Calculate some shit many times
	// 4 Read counter's value again
	// 5 Do nothing the same amount of times
	// 6 And read counter's value one more time
	// 7 Get the desired difference between counter's values, substract, divide and output it

	return 0;
}

