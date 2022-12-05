# 98keys

![98keys](https://github.com/Supermagnum/98keys-ergo/blob/master/layout.png)

*A 94 key ergonomic,split keyboard. Its powered by a two Raspberry pico.


* Keyboard Maintainer: [Supermagnum](https://github.com/Supermagnum)
* Hardware Supported: https://github.com/Supermagnum/Europe-ergo
* Hardware Availability: https://github.com/Supermagnum/Europe-ergo

L1/L2 controls what layer is active, QWERTY or DVORAK.
PWM1 to PWM 4 controls LED's based by the active layer, and also caps lock and scroll lock active. Those can be found here:https://github.com/Supermagnum/98keys-ergo/blob/master/98keys-split-pcb/schema/98keys-split-pcb.pdf The right side has identical outputs for PWM.

Make example for this keyboard (after setting up your build environment):

    make Europe-ergo:default

Flashing example for this keyboard:

    make Europe-ergo:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
