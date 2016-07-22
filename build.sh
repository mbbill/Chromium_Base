#!/bin/sh
gn --root=src args out/mybuild
ninja -C out/mybuild
