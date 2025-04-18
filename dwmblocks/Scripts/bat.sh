# #!/bin/bash
# capacity=$(cat /sys/class/power_supply/BAT1/capacity)
# status=$(cat /sys/class/power_supply/BAT1/status)
# icon="" # Default to charging icon
#
# case "$status" in
# "Charging") icon="" ;;    # Charging
# "Discharging") icon="" ;; # Discharging
# "Full") icon="" ;;        # Full
# esac
#
# echo "$icon $capacity%"

#!/bin/bash

# Get battery capacity and status
capacity=$(cat /sys/class/power_supply/BAT1/capacity)
status=$(cat /sys/class/power_supply/BAT1/status)

# Set icon based on battery status
case "$status" in
"Charging") icon="" ;;    # Charging
"Discharging") icon="🔋" ;; # Discharging
"Full") icon="" ;;        # Full
esac

# Apply Catppuccin Mocha colors
echo -e "$icon $capacity%" # Blue for battery status
