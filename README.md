# My keyboards

## AnnePro2/C15

Using nix to build the [QMK](https://docs.qmk.fm/) firmware for AnnePro2

Then can be flashed with [AnnePro2-Tools](https://github.com/OpenAnnePro/AnnePro2-Tools)

Press the ESC when plugging in to go to the bootloader

```bash
# compile
nix build .#annepro2

# flash
annepro2_tools $(realpath ./result)
```

## Ergodox EZ

A small pin can press the boot button next to the layer indicator lights on the right half

```bash
# compile
nix build .#ergodox

# qmk-toolbox works for flash
```
