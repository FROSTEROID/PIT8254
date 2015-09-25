#ifdef __BORLANDC__

#else
	#include <thread>
	#include <chrono>
#endif
 
#include "CPUports.h"
#include <math.h>

#ifndef __BORLANDC__
	using namespace std;
#endif

int port_timer2a = 0x43;
int port_timer2b = 0x42;

#ifndef __BORLANDC__
void delay(int ms){
	this_thread::sleep_for(std::chrono::milliseconds(ms));
}
#endif

class PIT2ctl{
private:
	CPUports ports();	


	void GetHLBytes(int inumber, unsigned char* low, unsigned char* high){
		low[0] = 	(inumber & 0xff);
		high[0] = 	(inumber >> 8);
	}

public:
	inline void SetFreq(int freq){
		int countdown = 1193180 / freq;
		unsigned char *low = new unsigned char[1];
		unsigned char *high = new unsigned char[1];
		GetHLBytes(countdown, low, high);
		ports.WriteByteToPort(0xb6, port_timer2a); 	// SC1 SC0 RW1 RW0 M2 M1 M0 BCD
													//	1	0	1	1	
		ports.ReadByteFromPort(*low, port_timer2b);
		ports.ReadByteFromPort(*high, port_timer2b);
	}

	int GetCounterValue(){
		int rez;
		
	}

}

