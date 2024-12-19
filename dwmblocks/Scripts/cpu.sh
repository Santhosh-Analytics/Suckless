#!/bin/bash
cpu=$(grep -o "^[^ ]*" /proc/loadavg)
echo " $cpu"
