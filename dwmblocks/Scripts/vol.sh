#!/bin/bash
volume=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -oP '\d+%' | head -1) # Gets the volume level as a percentage
mute=$(pactl get-sink-mute @DEFAULT_SINK@ | grep -oP 'yes|no') # Checks if the audio is muted

if [ "$mute" = "yes" ]; then
    echo "婢 Muted" # Displays "Muted" icon if audio is muted
else
    echo " $volume" # Displays the volume percentage
fi

