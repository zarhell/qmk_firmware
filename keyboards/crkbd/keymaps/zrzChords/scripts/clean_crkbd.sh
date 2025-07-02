#!/bin/bash
echo "🧹 Cleaning build files"
docker run --rm \
  -v "$(pwd)":/qmk_firmware \
  -w /qmk_firmware \
  qmk-corne \
  make clean
