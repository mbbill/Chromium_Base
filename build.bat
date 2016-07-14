set DEPOT_TOOLS_WIN_TOOLCHAIN=0
call gn --root=src args out/mybuild
call ninja -C out/mybuild
