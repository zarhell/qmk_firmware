#!/bin/bash
echo "🔌 Flashing firmware to crkbd"
docker run --rm --privileged \
  -v /dev:/dev \
  -v "$(pwd)/keymap":/qmk_firmware/keyboards/crkbd/keymaps/zrzChords \
  -v "$(pwd)":/qmk_firmware \
  -w /qmk_firmware \
  qmk-corne \
  qmk flash "$@"
