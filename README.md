# chatease-server

> [[domain] http://studease.cn](http://studease.cn)

> [[source] https://github.com/studease/chatease-server](https://github.com/studease/chatease-server)

This is a websocket server for chatting.


## Prepare
----------

Supply an interface to return a JSON object formatted as /data/userinfo.json.

While the client is connecting to upgrade protocol, we send an identify upstream request to get the user info,
which decides whether the operation will be satisfied.


## Build
--------

Note: LUA is no longer used.

### CMake

To build chatease-server, you need CMake 3.5 and or above. Then run:

```
mkdir build 
cd build
cmake ..
```


## Run
------

```
sudo ./chatease-server
```


## Websocket Client
-------------------

[chatease.js https://github.com/studease/chatease](https://github.com/studease/chatease)


## Software License
-------------------

Apache License 2.0
