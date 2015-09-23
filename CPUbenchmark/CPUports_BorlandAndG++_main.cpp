#ifdef __BORLANDC__
    #include <dos.h>
    #include <stdlib.h>
    #include <iostream.h>
    #include <stdio.h>
    #include <conio.h>
#else
    #include <sys/io.h>
    #include <unistd.h>
    #include <iostream>

    #include <thread>
    #include <chrono>
#endif

int port_timer2a = 0x43;
int port_timer2b = 0x42;
//int port_speaker = 0x61;

#ifndef __BORLANDC__
    using namespace std;
#endif


int TakePermissions() {
    #ifndef __BORLANDC__
    if(ioperm(port_timer2b, 0x02, 1))
        return 0;
//    if(ioperm(port_speaker, 0x20, 1))
//        return 0;
    #else
    cout << "Fuck permissions, we are in a DOS country!" << endl;
    #endif
    return 1;
}

inline void writeByteToPort(unsigned char value, unsigned char port){
    #ifdef __BORLANDC__
        outportb(port, value);
    #else
        outb(value, port);
    #endif
}
inline unsigned char readByteFromPort(unsigned char port){
    #ifdef __BORLANDC__
        return inportb(port);
    #else
        return inb(port);
    #endif
}

#ifndef __BORLANDC__
void delay(int ms){
    this_thread::sleep_for(std::chrono::milliseconds(ms));
}
#endif

// for splitting a conter value before putting it to the port
void GetHLBytes(int inumber, unsigned char* low, unsigned char* high){
    low[0] =    (inumber & 0xff);
    high[0] =   (inumber >> 8);
}

inline void SetFreq(int freq){
    int countdown = 1193180 / freq;
    unsigned char *low = new unsigned char[1];
    unsigned char *high = new unsigned char[1];
    GetHLBytes(countdown, low, high);
    writeByteToPort(0xb6, port_timer2a);
    writeByteToPort(*low, port_timer2b);
    writeByteToPort(*high, port_timer2b);
}

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


