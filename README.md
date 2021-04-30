# AvrProgramming

Setting up VS(atmel/microchip studio) :

Command: C:\avrdude-6.3-mingw32\avrdude.exe
Arguments: -c usbasp -p m8 -U flash:w:$(TargetDir)$(TargetName).hex:i
Initial Directory: $(BinDir)
