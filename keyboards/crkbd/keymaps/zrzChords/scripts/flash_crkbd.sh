#!/bin/bash
echo "Flashing firmware to crkbd"
docker run --rm --privileged   -v /dev:/dev   -v "$(pwd)":/qmk_firmware   -w /qmk_firmware   qmk-corne   qmk flash -kb crkbd/rev1 -km zrzChords "$@"