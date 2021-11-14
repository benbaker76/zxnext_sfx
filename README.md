# SFX Demo

Sound effects demo for the ZX Spectrum Next.

You can create an AY FX Bank (afb) file using the [AY Sound FX Editor](https://github.com/Threetwosevensixseven/ayfxedit-improved)

## How to Build

If you want to build the zxnext_sfx program yourself, follow the steps below:

1. Install the latest version of [z88dk](https://github.com/z88dk/z88dk) and
a Sinclair ZX Spectrum emulator [CSpect](https://dailly.blogspot.com/) or
[ZEsarUX](https://sourceforge.net/projects/zesarux/).

2. Download the zxnext_sfx repository either as a ZIP archive using the
"Clone or download" button at the top of this page or with Git using the
following command:

> git clone https://github.com/headkaze/zxnext_sfx.git

3. Go to the zxnext_sfx directory and enter the following command:

> make

4. Run the zxnext_sfx/bin/zxnext_sfx.nex file in your
Sinclair ZX Spectrum emulator.

## Thanks

- [Michael Ware](https://www.rustypixels.uk/) for innumerable help with the Next hardware and z80 asm
- [Sefan Bylund](https://github.com/stefanbylund) for his z88dk examples on which these are based
- [Shiru](https://shiru.untergrund.net/software.shtml) for original ayfx player assembly code

## License

This software is licensed under the terms of the MIT license.
