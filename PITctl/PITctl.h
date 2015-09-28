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

class PIT2ctl{
private:
	CPUports ports;	


	void GetHLBytes(int inumber, unsigned char* low, unsigned char* high){
		low[0] = 	(inumber & 0xff);
		high[0] = 	(inumber >> 8);
	}

public:

	PIT2ctl(){
		if(!ports.TakePermission(port_timer2b, 2)){
			throw "Couldn't take direct port usage permissions!\r\nMaybe should run as root or use DOS?\r\n";
		}
	}

	inline void SetFreq(int freq){
		int countdown = 1193180 / freq;
		unsigned char *low = new unsigned char[1];
		unsigned char *high = new unsigned char[1];
		GetHLBytes(countdown, low, high);
		ports.WriteByteToPort(0xb6, port_timer2a); 	// SC1 SC0 RW1 RW0 M2 M1 M0 BCD
													//	1	0	1	1	
		ports.WriteByteToPort(*low, port_timer2b);
		ports.WriteByteToPort(*high, port_timer2b);
	}

	int GetCounterValue(){
		int rez;
		
	}

};

