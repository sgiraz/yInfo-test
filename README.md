# yInfo-test
The purpose of this repository is to provide a minimal, reproducible example in order to debug the behavior of YARP yInfo function when it is execute in either yarplogger or console context.

### Prerequisites
Follow the source installation of the [robotology-superbuild](https://github.com/robotology/robotology-superbuild/tree/v2021.05).

### How to build
```bash
mkdir build
cd build
cmake ..
make
sudo make install
```

### Run using console

__Terminal #1__
```bash
yarpserver
```
__Terminal #2__
```bash
test_yInfo
```

### Run using yarpmanger and inspect using yarplogger

__Terminal #1__
```bash
yarpserver
```
__Terminal #2__
```bash
yarplogger
```
__Terminal #3__
```bash
yarpmanager
```

- In the yarplogger window start the logger using the start green button ▶
- In the yarpmanager window double click on the application called _Debug_yInfo_App_, click on _test_info_ module and run using the start green button ▶.
- Now in the yarplogger window I should be able to see the current log session. Double click on it and look at the output.

⚠ Don't forget to setup the `YARP_FORWARD_LOG_ENABLE` environment variable.

### Check for missing traces
As we said the `yarplogger` may not trace all the `yInfo` function calls. To check this automatically, you can run the [check_log_file.sh](check_log_file.sh) passing a `.log` file as an argument (see the example below)

```
./check_log_file.sh build/yarprunlog_04_07_2021_23_41_24.log
Parsing log file...
Missing value 3224, previous was at [ Time delay ]: 0.0001 Counter value: 3223
Missing value 3512, previous was at [ Time delay ]: 0.0001 Counter value: 3511
Missing value 3513, previous was at
Missing value 3514, previous was at
Missing value 3515, previous was at
Missing value 8594, previous was at [ Time delay ]: 0.0001 Counter value: 8593
Missing value 8595, previous was at
Missing value 8596, previous was at
Done.
```

Each time that the `yarplogger` has missed to track a yInfo call, the script will disaply a `Missing ...` line.
In a `Missing ...` reports:
- the missed value
- the current time delay used between 2 consecutives `yInfo` function calls.
- the plast value tracked before the lost.

**Note**

If you change the number of values to generate in [main.cpp](src/main.cpp) you have to update the `total` variable within the [check_log_file.sh](check_log_file.sh). 
