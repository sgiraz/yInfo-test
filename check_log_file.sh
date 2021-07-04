#!/bin/bash

echo "Parsing log file..."

if [ $# -ne 1 ]; then
    echo "missing argument. Please provide yarplogger file as argument."
fi

LOG_FILE=$1

LOG_OUTPUT=($(grep -Po '(?<=Counter value:  ).*(?=<#STRING_END#>)' $LOG_FILE))

total="10000" # number of expeceted values
REF=0

for ((i = 0; i < total; i++)); do
    NUM=$((${LOG_OUTPUT[$i]} + 0))

    while [ "$REF" -ne "$NUM" ] && [ "$REF" -lt "$total" ]
    do
        LINE=$(grep -F "  $((REF - 1))<#STRING_END#>" $LOG_FILE | sed -e 's/<#STRING_START#>---- \(.*\)<#STRING_END#>/\1/')
        echo -e "Missing value $REF, previous was at $LINE"
        REF=$((REF + 1))
        #sleep 3
    done

    REF=$((REF + 1))

done

echo "Done."