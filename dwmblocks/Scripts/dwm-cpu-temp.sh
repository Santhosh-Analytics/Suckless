#!/bin/bash

cputemp=$(sensors k10temp-pci-00c3 | awk '/^Tctl/ {print $2}' | sed 's/+//;s/°C//')
gputemp=$(sensors | awk '/^edge/ {print $2}' | sed 's/+//;s/°C//')

echo "$cputemp $gputemp"
