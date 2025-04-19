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

# # Get battery capacity and status
capacity=$(cat /sys/class/power_supply/BAT1/capacity)
status=$(cat /sys/class/power_supply/BAT1/status)
#
# # Set icon based on battery status
# case "$status" in
# "Charging") icon="" ;;    # Charging
# "Discharging") icon="🔋" ;; # Discharging
# "Full") icon="🔋" ;;        # Full
# esac
capacity=${capacity%.*}

# Set icon based on status and capacity
if [ "$status" = "Charging" ]; then
	icon="" # Charging
elif [ "$status" = "Full" ]; then
	icon="🔌" # Full and plugged in
else
	# Discharging - different icons for different levels
	if [ "$capacity" -lt 10 ]; then
		icon="🪫" # Critical (under 10%)
	elif [ "$capacity" -lt 30 ]; then
		icon="🔋" # Low (under 30%)
	elif [ "$capacity" -lt 70 ]; then
		icon="🔋" # Medium (30-69%)
	else
		icon="🔋" # High (70%+)
	fi
fi

# Output JSON format
echo "{\"icon\":\"$icon\", \"level\":\"$capacity%\"}"
