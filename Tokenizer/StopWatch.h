/*
* Enigma Swan Adams 
* CS202 HW1
* part of the program 1 files
* 
* more specific file info:
* StopWatch class header to file StopWatch.cpp
*/

#include<iostream>
#include <chrono>


#ifndef STOPWATCH_H_
#define STOPWATCH_H_

class StopWatch
{
public:
	// constructor that starts the clock
	StopWatch();

	// destructor is written by compiler

	// restart the clock 
	std::chrono::time_point<std::chrono::system_clock> Start();
	
	// record the end time 
	std::chrono::time_point<std::chrono::system_clock> Stop();

	// report time in seconds
	double TimeSec();

	// report time in millisecods
	double TimeMilliSec();
	

private:
	std::chrono::system_clock::time_point _start; 
	std::chrono::system_clock::time_point _end;
	double _diff_seconds = -1;
	double _diff_milliseconds = -1;
};


#endif /* STOPWATCH_H_ */
