# AvrProgramming

Setting up VS(atmel/microchip studio) :

Command: C:\avrdude-6.3-mingw32\avrdude.exe

Arguments: -c usbasp -p m8 -U flash:w:$(TargetDir)$(TargetName).hex:i

Initial Directory: $(BinDir)

Tools menu screen:

![image](https://user-images.githubusercontent.com/31712183/116710050-9d76ce00-a9d1-11eb-941f-9705f30562b6.png)
