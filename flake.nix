{
  description = "keyboards";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs?ref=nixos-unstable";
    qmk-firmware = {
      url = "git+https://github.com/qmk/qmk_firmware?ref=master&submodules=1";
      flake = false;
    };
  };
  outputs =
    {
      self,
      nixpkgs,
      qmk-firmware,
      ...
    }@inputs:
    let
      forAllSystems =
        f:
        nixpkgs.lib.genAttrs nixpkgs.lib.systems.flakeExposed (
          system: f (import nixpkgs { inherit system; })
        );
    in
    {
      packages = forAllSystems (pkgs: rec {
        qmk-src = pkgs.callPackage ./pkgs/qmk { inherit qmk-firmware; };

        annepro2 = (
          pkgs.callPackage ./pkgs/firmware.nix {
            inherit qmk-src;
            keyboard-path = "annepro2/c15";
            keymap-name = "homerow";
            ext = "bin";
          }
        );

        ergodox = (
          pkgs.callPackage ./pkgs/firmware.nix {
            inherit qmk-src;
            keyboard-path = "ergodox_ez";
            keymap-name = "homerow";
            binary-name = "ergodox_ez_base_homerow.hex";
            ext = "hex";
          }
        );
      });
    };
}
