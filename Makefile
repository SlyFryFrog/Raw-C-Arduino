############################
# Board and library config #
############################

MCU     = atmega328p
F_CPU   = 16000000UL
BAUD    = 115200                # bits/s
PORT    = /dev/tty.usbmodem101  # <- Replace with your board's port

#########
# Tools #
#########

CC      = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

#########
# Files #
#########

TARGET  = main
SRC     = sources/$(TARGET).c sources/gpio.c

#########
# Flags #
#########

CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Isources -Iheaders
AVRDUDE_FLAGS = -c arduino -p m328p -P $(PORT) -b $(BAUD)

#################
# Make commands #
#################

.PHONY: all flash clean

all: build/$(TARGET).hex

# Ensure build directory exists before compiling
build:
	@mkdir -p build

build/$(TARGET).elf: $(SRC) | build
	$(CC) $(CFLAGS) -o $@ $^

build/$(TARGET).hex: build/$(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: build/$(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$<

clean:
	rm -f build/*.elf build/*.hex
