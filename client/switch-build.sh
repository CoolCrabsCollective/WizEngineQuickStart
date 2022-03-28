#! /bin/bash
set -eu
cd ../common
./switch-install.sh
cd ../client
make
