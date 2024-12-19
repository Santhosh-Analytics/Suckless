#!/bin/bash

# Get the SSID of the connected Wi-Fi
ssid=$(iw dev wlp2s0 link | grep 'SSID' | awk '{print $2}')

# Get the connection speed (in Mbps) of the current Wi-Fi connection
# speed=$(iw dev wlp2s0 link | grep 'tx bitrate' | awk '{print $3 $4}')

# If not connected, show a placeholder
if [ -z "$ssid" ]; then
    ssid="Not Connected"
    speed="N/A"
fi

# Unicode icons
wifi_icon="󰤨" # Wi-Fi icon

# Display the SSID and connection speed
echo "$wifi_icon $ssid" # @ $speed"
