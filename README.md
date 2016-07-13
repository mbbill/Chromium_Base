# Chromium_Base

It's the 'base' of Chromium, a lot of good stuff in there.
Compiling it into a stand alone library so that it can be used by other projects more easily.

## The 'good stuff's:
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

# Build
 * Download and addd [depot_tools](https://www.chromium.org/developers/how-tos/install-depot-tools) to your PATH
 * Configure with gn.

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

# Usage
See /demo
