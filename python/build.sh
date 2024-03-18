#!/bin/bash
clear
BASEDIR="$(cd "$(dirname "$0")" && pwd)"
echo "Script location: ${BASEDIR}"
cd ${BASEDIR}

# default value
TASK_NUMBER=0

for i in "$@"; do
    case $i in
    -t=*|--task=*) TASK_NUMBER="${i#*=}";;
    -h | --help | -?) echo "Use keys:
                -t=|--task=                         - number of task
            " && exit ;;
    esac
done

echo -e "=================================="
echo -e "Programm is executed:"
echo -e "=================================="
START=$(date +%N)
python3 ${BASEDIR}/main.py ${TASK_NUMBER}
END=$(date +%N)
DIFF=$(echo "$END - $START" | bc)
echo -e "=================================="
echo "Executing of programm tooks $DIFF nanoseconds or $(($DIFF / 1000000)) ms"
echo -e "=================================="