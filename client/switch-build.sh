#! /bin/bash
set -e
cd ../common
./switch-install.sh
cd ../client
make
