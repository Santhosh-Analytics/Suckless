#!/bin/bash

# Get CPU temperature (strip the + and °C symbols)
cputemp=$(sensors k10temp-pci-00c3 | awk '/^Tctl/ {print $2}' | sed 's/+//;s/°C//')
# Get GPU temperature (strip the + and °C symbols)
gputemp=$(sensors | awk '/^edge/ {print $2}' | sed 's/+//;s/°C//')

# Set notification color based on CPU temperature using awk for floating-point comparison
if (($(echo "$cputemp > 75" | awk '{if ($1 > 75) print 1; else print 0}'))); then
  color="\033[31m" # Red for high temperature
elif (($(echo "$cputemp > 65" | awk '{if ($1 > 65) print 1; else print 0}'))); then
  color="\033[33m" # Yellow for medium temperature
else
  color="\033[32m" # Green for normal temperature
fi

# Reset color
reset="\033[0m"

# Output temperature with color
echo -e "${color}CPU: ${cputemp}°C${reset} | GPU: ${gputemp}°C"
