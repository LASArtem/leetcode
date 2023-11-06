#!/bin/bash
clear
BASEDIR="$(cd "$(dirname "$0")" && pwd)"
echo "Script location: ${BASEDIR}"
cd ${BASEDIR}

# default value
THREADS_COUNT=$(grep -c ^processor /proc/cpuinfo)

for i in "$@"; do
    case $i in
    -j1 | --set-1-threads) THREADS_COUNT=1 ;;
    -j2 | --set-2-threads) THREADS_COUNT=2 ;;
    -j4 | --set-4-threads) THREADS_COUNT=4 ;;
    -j8 | --set-8-threads) THREADS_COUNT=8 ;;
    -jx | --set-max-threads) THREADS_COUNT=$(grep -c ^processor /proc/cpuinfo) ;;
    -h | --help | -?) echo "Use keys:
                -j1|--set-1-threads                 - Compile binaries with 1 threads
                -j2|--set-2-threads                 - Compile binaries with 2 threads
                -j4|--set-4-threads                 - Compile binaries with 4 threads
                -j8|--set-8-threads                 - Compile binaries with 8 threads
                -jx|--set-max-threads               - Compile binaries with max threads
            " && exit ;;
    esac
done

if [ "${CLEAN_BUILD}" = TRUE ]; then
    echo "==========CLEAN BUILD=========="
    rm -rf build
fi

echo "THREADS_COUNT=${THREADS_COUNT}"

mkdir -p build
cmake -H. -Bbuild
cd build
cmake --build . --parallel ${THREADS_COUNT} --target all

IS_PROJECT_BUILT=$?
if [ $IS_PROJECT_BUILT -eq 0 ]; then
  echo "Project is builded succesfully"
else
  exit
fi

echo -e "=================================="
echo -e "Programm is executed:"
echo -e "=================================="
START=$(date +%N)
${BASEDIR}/build/Solution*
END=$(date +%N)
DIFF=$(echo "$END - $START" | bc)
echo -e "=================================="
echo "Executing of programm tooks $DIFF nanoseconds or $(($DIFF / 1000000)) ms"
echo -e "=================================="