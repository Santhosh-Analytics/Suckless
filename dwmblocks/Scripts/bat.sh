#!/bin/bash
capacity=$(cat /sys/class/power_supply/BAT1/capacity)
status=$(cat /sys/class/power_supply/BAT1/status)
icon="" # Default to charging icon

case "$status" in
  "Charging") icon="" ;; # Charging
  "Discharging") icon="" ;; # Discharging
  "Full") icon="" ;; # Full
esac

echo "$icon $capacity%"

