#ifndef STRUCTS_H
#define STRUCTS_H
/// \file
///  \brief Has the structs that store the board's information.

#include "mbed.h"
#include <string>
#include <vector>
using namespace std;

/// Houses the information for each port
struct PortInfo {

    /// Name of the port (Port_1, Port_2, etc.)
    string Name;

    /// The value of the port, read from a sensor.
    float Value;

    /// Port description
    string Description;

    /// Multiplies port value to convert units
    float Multiplier;

    /// Indicates what type of sensor is attached to the port
    int SensorID;

    float RangeFloor; ///< Any port reading below this is considered an error.

    float RangeCeiling; ///< Any port reading above this is cosidered an error.

    /// Default Constructor.
    /// Sets all string values to "", integers to 0, and floats to 0.0
    PortInfo()
        : Name(""), Value(0.0), Description(""), Multiplier(0.0), SensorID(0),
           RangeFloor(0.0), RangeCeiling(0.0) {}
};

/// Stores information regarding specific sensors
struct SensorInfo {
    int ID; ///< The sensor's id integer

    string Type; ///< quantity that the sensor type measures.

    string Unit; ///< Unit the quantity is measured in

    float
        Multiplier; ///< Multiplier to convert sensor's value to specified unit

    float RangeFloor; ///< Any port reading below this is considered an error.

    float RangeCeiling; ///< Any port reading above this is cosidered an error.

    SensorInfo()
        : ID(0), Type("No Sensor"), Unit("No Unit"), Multiplier(0.0),
          RangeFloor(0.0), RangeCeiling(0) {}
};

/// Contains board properties and the ports' data and info.

/// To access a port's data, use this syntax: BoardSpecs.Ports[i].Value
/// \sa PortInfo
struct BoardSpecs {

    /// The board's name
    string ID;

    /// Name of the WiFi network to connect to
    string NetworkSSID;

    /// Password of the above WiFi network
    string NetworkPassword;

    /// The name used in the remote database to identify this board.
    /// This name is sent up every time this board needs to send data
    /// to the remote database
    string DatabaseTableName;

    /// The IP Address that this board will communicate with
    string RemoteIP;

    /// The remote directory used when making a GET request
    string RemoteDir;

    /// hostname for the site you are connecting to
    string HostName;

    /// the http port used in the GET request
    uint16_t RemotePort;

    /// The collection of ports and their information
    vector<PortInfo> Ports;

    /// Collection of possible sensor types.
    vector<SensorInfo> Sensors;

    /// Sets the number of ports for the board
    void setPortNum(unsigned int Num) { Ports.resize(Num); }

    /// Returns number of ports
    unsigned int getPortNum() { return Ports.size(); }

    /// Default constructor.
    /// Sets all strings to "" and sets the initializes the vector size to 0
    BoardSpecs()
        : ID(""), NetworkSSID(""), NetworkPassword(""), DatabaseTableName(""),
          RemoteIP(""), RemoteDir(""), RemotePort(0), Ports() {}
};

#endif // STRUCTS
