#!/bin/bash
clear
BASEDIR="$(cd "$(dirname "$0")" && pwd)"
echo "Script location: ${BASEDIR}"
cd ${BASEDIR}

# default value
TASK_NUMBER=0
CLEAN_BUILD=FALSE
THREADS_COUNT=$(grep -c ^processor /proc/cpuinfo)

for i in "$@"; do
    case $i in
    -t=*|--task=*) TASK_NUMBER="${i#*=}";;
    -c | --clean-build) CLEAN_BUILD=TRUE ;;
    -j1 | --set-1-threads) THREADS_COUNT=1 ;;
    -j2 | --set-2-threads) THREADS_COUNT=2 ;;
    -j4 | --set-4-threads) THREADS_COUNT=4 ;;
    -j8 | --set-8-threads) THREADS_COUNT=8 ;;
    -jx | --set-max-threads) THREADS_COUNT=$(grep -c ^processor /proc/cpuinfo) ;;
    -h | --help | -?) echo "Use keys:
                -t=|--task=                         - number of task
                -c|--clean-build                    - remove the build folder
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


CMAKE_PARAMS=""

#logOff = 0U,
#logFatal = 1U,
#logError = 2U,
#logWarn = 3U,
#logInfo = 4U,
#logDebug = 5U,
#logVerbose = 6U
CMAKE_PARAMS+=" -DCMAKE_MAX_LOG_LEVEL=6"

echo "CMAKE_PARAMS: ${CMAKE_PARAMS}"
echo "THREADS_COUNT=${THREADS_COUNT}"
mkdir -p build
cmake -H. -Bbuild ${CMAKE_PARAMS}
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
${BASEDIR}/build/LeetCode_Solutions ${TASK_NUMBER}
END=$(date +%N)
DIFF=$(echo "$END - $START" | bc)
echo -e "=================================="
echo "Executing of programm tooks $DIFF nanoseconds or $(($DIFF / 1000000)) ms"
echo -e "=================================="