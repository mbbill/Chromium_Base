#!/bin/sh
download_from_google_storage --no_resume --platform=linux --no_auth --bucket chromium-gn -s 'src/buildtools/linux64/gn.sha1'

# update sysroot
python ./src/build/linux/sysroot_scripts/install-sysroot.py --arch=amd64 
