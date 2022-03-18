/*
*
* Enigma Swan Adams
* CS202 HW1
* part of the program 1 files
*
* more specific file info :
* StopWatch class definitions 
*/

#include "StopWatch.h"
#include <chrono>
#include <ctime>
using std::cout;
using std::endl;


// constructor that starts the clock
StopWatch::StopWatch() {
	auto _start = std::chrono::system_clock::now();
}

// destructor is written by compiler

// restart the clock 
std::chrono::time_point<std::chrono::system_clock> StopWatch::Start() {
	_start = std::chrono::system_clock::now();
	return  _start;
}

// record the end time 
std::chrono::time_point<std::chrono::system_clock> StopWatch::Stop() {
	_end = std::chrono::system_clock::now();
	return _end;}


// report time in seconds
double StopWatch::TimeSec() { 
	auto _diff = _end - _start;
	_diff_seconds = std::chrono::duration<double>(_diff).count();
	//cout << "Time in seconds was: " << _diff_seconds << endl; // for testing
	return _diff_seconds; }

// report time in millisecods
double StopWatch::TimeMilliSec() { 
	auto _diff = _end - _start;
	_diff_milliseconds = std::chrono::duration<double,std::milli>(_diff).count();
	//cout << "Time in milliseconds was: " << _diff_milliseconds << endl; // was for testing
	return _diff_milliseconds;
}
