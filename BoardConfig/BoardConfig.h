#ifndef BOARDCONFIG_H
#define BOARDCONFIG_H
//===-- BoardConfig.h - header for board config functions ----------------===//
//
// Part of the IAC energy monitoring project
//
//===---------------------------------------------------------------------===//
/// \file
/// Has the function prototypes for functions that set the board's
/// configuration.

#include "Networking.h"
#include "Structs.h"
#include "mbed.h"

// C++ headers
#include <deque>
#include <sstream>

// C headers
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

/// Arbitrary length for char buffers
#define BUFFLEN 1024

/// Tries to open the specified file to read and return the configuration.
/// \returns The board's configuration
/// \sa BoardSpecs
BoardSpecs readSDCard(const char *FileName);

/// Reads the fp and derives the board configuration from that file.
/// This function gets the Board's ID, network SSID, network password, and
/// database table name from the file pointer. In addition to that, it reads the
/// number of ports and their type. All of that data is returned in a struct.
/// \param fp The file pointer to read
/// \returns The board's configuration
/// \sa BoardSpecs
BoardSpecs readConfigText(FILE *fp);

/// takes in the sensor ID number and returns a number to convert the sensor's
/// value into a meaningful unit
/// \param Sens_ID The sensor's ID number
/// \param Sensors The set of sensor information to pick from
/// \returns The port's unit multiplier
float setUnitMultiplier(vector<SensorInfo> & Sensors, int Sens_ID);

/// Returns a name for each sensor depending on the sensor's ID number.
/// \returns A const char * that is the sensor name
/// \param Sens_ID The sensor's ID number
/// \param Sensors The set of sensor information to pick from
/// \returns What that sensor measures
string getSensorName(vector<SensorInfo> & Sensors, int Sens_ID);

/// Converts an integer to a string without C++11 functions.
string toString(int input);

/// Converts a float to a string without C++11 functions.
string toString(float input);

#endif // BOARDCONFIG