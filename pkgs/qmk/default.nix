{
  stdenv,
  qmk-firmware,
  ...
}:
let
  userspace = stdenv.mkDerivation {
    name = "qmk-config";
    src = ./userspace;
    phases = [ "installPhase" ];
    installPhase = ''
      cp -r "$src" "$out"
    '';
  };
in
stdenv.mkDerivation {
  name = "qmk-custom-src";
  src = qmk-firmware;
  phases = [ "installPhase" ];
  installPhase = ''
    cp -r "$src" "$out"

    pushd "$out"/keyboards
    chmod -R +w "."
    cp -Tr ${userspace} "./"
    chmod -R -w "."
    popd
  '';
}
