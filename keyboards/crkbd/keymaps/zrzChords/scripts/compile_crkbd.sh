#!/bin/bash
echo "⚙️  Compiling firmware for crkbd"
docker run --rm \
  -v "$(pwd)/keymap":/qmk_firmware/keyboards/crkbd/keymaps/zrzChords \
  -v "$(pwd)":/qmk_firmware \
  -w /qmk_firmware \
  qmk-corne \
  qmk compile
