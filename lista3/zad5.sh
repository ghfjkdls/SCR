#!/bin/bash

trap 'echo "sigint"' SIGINT 
trap 'echo "sighup"' SIGHUP  
trap 'echo "sigterm"' SIGTERM 
trap 'echo "sigquit"' SIGQUIT
trap 'echo "sigfpe"' SIGFPE
trap 'echo "sigkill"' SIGKILL

for (( ; ; ))
do
    sleep 2
    echo "dsjfkjsdkf"
done
