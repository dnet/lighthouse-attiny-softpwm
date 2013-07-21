PORT ?= /dev/ttyUSB0
PROG ?= stk500
# ATtiny22 or compatible
PART ?= 2343
MMCU ?= attiny22
# 1 MHz - ATtiny22 with internal clock
FCPU ?= 1000000

# normally, changes should only be made above this line

OBJECTS = main main.hex

main.hex: main
	avr-objcopy -j .text -j .data -O ihex $^ $@

main: main.c
	avr-gcc $^ -o $@ -O2 -DF_CPU=$(FCPU) -mmcu=$(MMCU)

upload: main.hex
	avrdude -p $(PART) -c $(PROG) -P $(PORT) -U flash:w:$^

clean:
	rm -f $(OBJECTS)

.PHONY: clean upload
