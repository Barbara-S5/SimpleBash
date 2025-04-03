#!/bin/bash

source ./take_info.sh

func_fold_info(){
    echo "Total number of folders (including all nested ones) =" ${Total_folders} 
    echo -e "TOP 5 folders of maximum size arranged in descending order (path and size):\n${T_5_folders}"
    echo "Script execution time (in seconds) = $SECONDS.${SECONDS%}s"
}