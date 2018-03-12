# imu-viewer
This programm is written in Qt and alows you to see visualized sensordata comming from the imu-utils.

You would create an server running in backend ,and pass the sensor data by this json format:

{
    "acc": {
        "x": 1, 
        "y": 1.100000023841858, 
        "z": 1.2000000476837158
    }, 
    "angles": {
        "pitch": 4.099999904632568, 
        "roll": 4, 
        "yaw": 4.199999809265137
    }, 
    "dt": 1, 
    "gyr": {
        "x": 2, 
        "y": 2.0999999046325684, 
        "z": 2.200000047683716
    }, 
    "mag": {
        "x": 3, 
        "y": 3.0999999046325684, 
        "z": 3.200000047683716
    }
}

I am thinking another method of acquiring the sensor data by the serial port,
but still have no time to implement yet.
