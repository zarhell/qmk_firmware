#!/bin/bash
export MSYS_NO_PATHCONV=1

echo "⚙️  Compiling firmware for crkbd"

docker run --rm \
  -v "$(pwd)":/qmk_firmware \
  -w /qmk_firmware \
  qmk-corne \
  qmk compile -kb crkbd -km zrzChords