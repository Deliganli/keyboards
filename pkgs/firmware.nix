{
  stdenv,
  qmk,
  qmk-src,
  keyboard-path,
  keymap-name,
  lib,
  ext,
  binary-name ? "${lib.replaceString "/" "_" keyboard-path}_${keymap-name}.${ext}",
  ...
}:
stdenv.mkDerivation {
  name = "qmk_${binary-name}";
  nativeBuildInputs = [ qmk ];
  src = qmk-src;
  postPatch = ''
    VERSION="''${out#/nix/store}"
    echo "#define QMK_VERSION \"$VERSION\"" \
        > quantum/version.h
  '';

  buildPhase = ''
    SKIP_GIT=true SKIP_VERSION=true \
        make ${keyboard-path}:${keymap-name}
  '';

  installPhase = ''
    cp ${binary-name} "$out"
  '';
}
