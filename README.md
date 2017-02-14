# Chromium_Base

It's the *base* component of Chromium where a lot of good tools sits in.

## Tools included:
 * trace event
 * Threading
 * bind
 * profiler
 * stack trace
 * file utils
 * logging
 * containers
 * json
 * memory tools
 * message loop
 * process tools
 * rand
 * string
 * synchronization
 * task scheduler
 * timer
 * a lot more..

# Example
## Trace event demo
Generate tracing event and view flame graph with [catapult](https://github.com/catapult-project/catapult) or Chrome's ```about:tracing```
![Trace Event Demo](https://raw.githubusercontent.com/mbbill/Chromium_Base/master/demo/res/trace_demo.png "Trace event demo")

## Trace event for some complex project
![Trace Event Demo](https://raw.githubusercontent.com/mbbill/Chromium_Base/master/demo/res/trace_demo_webkit.png "Trace event demo")

# Usage
Refer to examples under /demo for more information.

# Build
 * Download and addd [depot_tools](https://www.chromium.org/developers/how-tos/install-depot-tools) to your PATH
 * On Linux or macOS, run ```prep.sh```
 * Configure with gn.
 ```
 :: on Windows, you need first
 > set DEPOT_TOOLS_WIN_TOOLCHAIN=0
 ```
 then
 ```
 $ cd src
 $ gn args out/mybuild
 ```
 * Build with ninja

 ```
 $ ninja -C out/mybuild
 ```

# Platform Support
 * macOS
 * Windows
 * Linux
 * Android
 * IOS

