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
