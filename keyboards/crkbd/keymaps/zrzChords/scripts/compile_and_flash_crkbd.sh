#!/bin/bash
echo "🔁 Compiling and flashing firmware"
./scripts/compile_crkbd && ./scripts/flash_crkbd "$@"
