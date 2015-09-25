# compiler:
CC=g++
# flags:
FLG=-std=c++11

nothing:
	
benchmark:
	$(CC) $(FLG) main.cpp -o benchmark

pcsplayer:
	$(CC) $(FLG) PCSplayer/PCSplayer.cpp -o PCSplayer/build/pcsplayer
