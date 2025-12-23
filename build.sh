#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -f "dmc_unrar.h" ]; then return; fi
URL="https://github.com/DrMcCoy/dmc_unrar/raw/refs/heads/master/dmc_unrar.c"
FILE="dmc_unrar.h"

# Download the release
if [ ! -f "$FILE" ]; then
  echo "Downloading $FILE from $URL ..."
  curl -L "$URL" -o "$FILE"
  echo ""
fi
}


# Test the project
test() {
echo "Running 01-list-contents.c ..."
clang -I. -o 01.exe examples/01-list-contents.c    && ./01.exe examples/archive.rar            && echo -e "\n"
echo "Running 02-extract-file.c ..."
clang -I. -o 02.exe examples/02-extract-file.c     && ./02.exe examples/archive.rar README.log && echo -e "\n"
echo "Running 03-validate-archive.c ..."
clang -I. -o 03.exe examples/03-validate-archive.c && ./03.exe examples/archive.rar            && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
