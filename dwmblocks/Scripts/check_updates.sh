# #!/bin/bash
#
# # Check for pacman updates
# pacman_updates=$(checkupdates | wc -l)
#
# # Check for yay updates
# yay_updates=$(yay -Qup | wc -l)
#
# # Check for flathub updates
# flathub_updates=$(flatpak update --appstream | wc -l)
#
# # If updates are available, output the count in the format pacman_updates|yay_updates|flathub_updates
# echo "$pacman_updates|$yay_updates|$flathub_updates" # Red color for updates

#!/bin/bash

# Check for pacman, yay, and flathub updates
pacman_updates=$(checkupdates | wc -l)
yay_updates=$(yay -Qup | wc -l)
flathub_updates=$(flatpak update --appstream | wc -l)

# Apply Catppuccin Mocha colors
if [ "$pacman_updates" -gt 0 ] || [ "$yay_updates" -gt 0 ] || [ "$flathub_updates" -gt 0 ]; then
  echo -e " $pacman_updates|$yay_updates|$flathub_updates" # Red for updates
else
  echo -e " 0" # Green for no updates
fi
