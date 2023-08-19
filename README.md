# mBuild
## Disclaimer: This project is not affiliated with makeblock in anyway shape or form, I did it just becuase makeblock does not provide tools/software nessary to test/debug my team's robot

## Goal:
figuring out makeblock's mBuild interface  
this incude and not limited to:  
- protocol
- chaining protocol
- discovery process
- pairing and numbering
- limitations
- posability in creating a custom MakeX Power Management Module so my team can pratice properly just like in the real arena

## Data so far
after some poking arround with a multimeter this is my knowledge so far  
I used a halocode in this experiment becuase I dont feel like pulling the nova pi off our robot and they need somthing to use, since the protocol is universal across makeblock's product this should be how they all works

- mBuild commumicates over UART  
here's a few things that might make sense for you  
mBuild is chainable but its directional, if its I2c it will not be directional since it works a lot differently than mBuild
I will be testing with chaining different sensors and output devices to see how I can build a custom module and even to clone an existing module by reverse engineering the commumicaion protocol
- mBuild is 5V only, the power rail for mBuild port is 5V no matter what the master device was  
as I stated, I use a halocode which is based off ESP32 which is 3.3V logic, but the power output from the mBuild interface is 5V
- mBuild uses 19200bps baud rate  
this sounds kinda odd, I first assume 9200 or 115200 but after some playing arround 19200 seems to be the number I can get usuable data off, its just "++" and stuff right now, I'm going to assume its the discovery protcol, if it turns out to be I can easily sniff and replicate with a Raspberry pi Pico, add Wifi and I get a power management module which will be much more stable than anything makeblock has made, also a wifi based wireless upload module will come soon if it turns out to be so easily replicated

## mBuild Pinout
yes I cut a ridiculusly expensive wire just for this project  
I have 2 ends I intended to make another set to sniff data off the novapi and the original power management module  

heres the pinout from top(1) to buttom(4)  
1. 5V
2. GND
3. UART TX
4. UART RX
