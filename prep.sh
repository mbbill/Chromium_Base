#!/bin/bash
export OS=$(uname)

# Linux
if [[ ${OS} == "Linux" ]]; then
    download_from_google_storage --no_resume --platform=linux --no_auth --bucket chromium-gn -s 'src/buildtools/linux64/gn.sha1'
    # update sysroot
    python ./src/build/linux/sysroot_scripts/install-sysroot.py --arch=amd64 
fi

# macOS
if [[ ${OS} == "Darwin" ]]; then
    download_from_google_storage --no_resume --platform=darwin --no_auth --bucket chromium-gn -s 'src/buildtools/mac/gn.sha1'
fi

# update llvm binaries
python ./src/tools/clang/scripts/update.py --if-needed

