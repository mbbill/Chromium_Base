set DEPOT_TOOLS_WIN_TOOLCHAIN=0
call gn --root=src args src/out/mybuild
call ninja -C src/out/mybuild
