#!/bin/bash


Path=$1

Total_folders=$(find "$Path" -type d |  wc -l) 
T_5_folders=$(du -h "$Path" | sort -hr | head -n 5 | awk '{ printf "%d - %s, %s\n",FNR, $2, $1}')