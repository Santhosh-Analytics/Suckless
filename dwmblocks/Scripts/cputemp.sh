#!/bin/bash

# Get CPU temperature
cputemp=$(sensors k10temp-pci-00c3 | awk '/^Tctl/ {print "\nCPU: " substr($2,2,2)}')
gputemp=$(sensors | awk '/^edge/ {print " | \nGPU:" substr($2,2,2)}')

# Stats notification color
if [[ $cputemp -gt 75 ]]; then color="#bf616a"; elif [[ $cputemp -gt 65 ]]; then color="#ebcb8b"; else color="#a3be8c"; fi

# Output temperature with color
echo $cputemp"°c" $gputemp"g"
