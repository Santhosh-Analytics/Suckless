# #!/bin/bash
# cpu=$(grep -o "^[^ ]*" /proc/loadavg)
# echo " $cpu"

#!/bin/bash

# Get CPU load
cpu=$(grep -o "^[^ ]*" /proc/loadavg)

# Apply Catppuccin Mocha colors
echo -e " $cpu" # Blue for CPU load
