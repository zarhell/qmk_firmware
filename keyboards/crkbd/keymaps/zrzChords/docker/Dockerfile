FROM qmkfm/qmk_cli

WORKDIR /qmk_firmware

RUN qmk setup -y \
 && qmk config user.keyboard=crkbd/rev1 \
 && qmk config user.keymap=zrzChords

COPY keymap /qmk_firmware/keyboards/crkbd/keymaps/zrzChords
