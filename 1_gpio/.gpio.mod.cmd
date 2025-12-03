savedcmd_/home/dsd/Documents/1_gpio/gpio.mod := printf '%s\n'   gpio.o | awk '!x[$$0]++ { print("/home/dsd/Documents/1_gpio/"$$0) }' > /home/dsd/Documents/1_gpio/gpio.mod
