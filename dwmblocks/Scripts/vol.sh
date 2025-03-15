#!/bin/bash
# volume=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -oP '\d+%' | head -1) # Gets the volume level as a percentage
# mute=$(pactl get-sink-mute @DEFAULT_SINK@ | grep -oP 'yes|no') # Checks if the audio is muted
#
# if [ "$mute" = "yes" ]; then
#     echo "婢 Muted" # Displays "Muted" icon if audio is muted
# else
#     echo " $volume" # Displays the volume percentage
# fi
#

# Get volume level
volume=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -oP '\d+%' | head -1)
# Check if audio is muted
mute=$(pactl get-sink-mute @DEFAULT_SINK@ | grep -oP 'yes|no')

# Apply Catppuccin Mocha colors
if [ "$mute" = "yes" ]; then
  echo -e "婢 Muted" # Red for muted
else
  echo -e " $volume" # Blue for volume
fi
