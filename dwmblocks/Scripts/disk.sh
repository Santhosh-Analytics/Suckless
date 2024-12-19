#!/bin/bash
disk=$(df -h / | awk 'NR==2 {print $3 "/" $2}')
windows=$(df -h | grep '/run/media/Windows' | awk '{print $5}')
project=$(df -h | grep '/run/media/Project' | awk '{print $5}')
backup=$(df -h | grep '/run/media' | grep 'Drive_Backup' | awk '{print $5}')

# Unicode icons
windows_icon="󰍉"  # Windows Icon
project_icon="󰈙"  # Book/Project Icon
backup_icon="󰆼"   # Database/Backup Icon

echo " $disk | $windows_icon: $windows | $project_icon: $project | $backup_icon: $backup"

