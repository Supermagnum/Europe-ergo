# Europe-ergo
A 94 key ergonomic,split keyboard.
Its powered by 2X Raspberry pico and linked with two TRRS jacks.
It uses tht components.

The reset switches, TRRS jacks and raspberry pico's  goes on the reverse side of the Pcb's. 

Picture of Pcb's top side:
https://github.com/Supermagnum/Europe-ergo/blob/main/Europe-ergo-PCB/Europe-ergo.jpg


Layout:
https://github.com/Supermagnum/Europe-ergo/blob/main/layout.png
or:
http://www.keyboard-layout-editor.com/#/gists/50db7ea7b0832342d4c734eb985ec16b

The L1/L2 button is to change from  Norwegian QWERTY to Norwegian Dvorak.

Keycaps:
https://github.com/Supermagnum/Europe-ergo/blob/main/keycaps.jpg



It compiles with QMK.


Json file for VIAL is in the firmware folder.

All mechanical blueprints as pdf files can be exported from the Freecad file.
Freecad can be found for free here:
https://www.freecadweb.org/


Vial:


https://get.vial.today/


PWM1 to PWM 4 controls LED's ( ON/OFF) based by the active layer, and also caps lock and scroll lock active.

Those and the electrical diagram can be found here:
https://github.com/Supermagnum/Europe-ergo/blob/main/Europe-ergo-PCB/schema/Europe-ergo.pdf
The right side has identical outputs for PWM.

Cherry MX switches should fit the PCB'S.


STL files for 3D printing of the boxes:
https://github.com/Supermagnum/Europe-ergo/tree/main/mechanical


Link to aisler:
https://aisler.net/p/OPFSMZDA




PCB way ( use with caution,the pictures doesn't match the gerber files):
<a href="https://www.pcbway.com/project/shareproject/98keys_ergo_733ee9b8.html"><img src="https://www.pcbway.com/project/img/images/frompcbway-1220.png" alt="PCB from PCBWay" /></a>

Panelized version:
https://github.com/Supermagnum/erope-ergo-ex


License:
https://github.com/Supermagnum/Europe-ergo/blob/main/LICENSE


Todo:

Maybe add a supporting point in the middle of the Pcb's. 

Add a usb device id so the PCB will be recognised by Linux and others, if necessary. 


Thanks to :
https://github.com/hakbraley
for helping with the firmware,- I cant program at all and Ihave issues getting my head around programming.



