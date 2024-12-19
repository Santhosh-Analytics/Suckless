#!/bin/bash

# Check for pacman updates
pacman_updates=$(checkupdates | wc -l)

# Check for yay updates
yay_updates=$(yay -Qup | wc -l)

# Check for flathub updates
flathub_updates=$(flatpak update --appstream | wc -l)

# If updates are available, output the count in the format pacman_updates|yay_updates|flathub_updates
echo "$pacman_updates|$yay_updates|$flathub_updates" # Red color for updates
