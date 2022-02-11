# TemplateSFMLProject
Ready to run template SFML project for Windows, Mac, Linux and Switch

# Development setup
## Nintendo Switch
### Install Pacman
Download Debian install package [here](https://github.com/devkitPro/pacman/releases/tag/v1.0.2)
For Ubuntu:
* `sudo dpkg -i devkitpro-pacman.amd64.deb`

### use Pacman to install devkitA64 for compilation toolchains
* `sudo dkp-pacman -S switch-dev`
  (Hit enter to use all repositories by default)

### Add DevKit environment variables to ~./bashrc file
```   
   export DEVKITPRO=/opt/devkitpro
   export DEVKITARM=/opt/devkitpro/devkitARM
   export DEVKITPPC=/opt/devkitpro/devkitPPC
```

### Install specific libraries for switch development
`sudo dkp-pacman -S switch-sdl2 switch-sdl2_mixer switch-glad switch-bzip2 switch-zlib switch-mesa switch-libpng switch-libogg switch-flac switch-glm switch-sdl2_image switch-sdl2_ttf switch-libvorbis switch-openal-soft`

If library is custom and thus not found using pacman, copy .a files to `$DEVKITPRO/portlibs/switch/lib`

### Installing SFML-switch
Build via the instructions in the readme on my fork of [SFML-switch](https://github.com/RealWilliamWells/SFML-switch) then run the installation bash script

### Installing mojoAL-switch
Go [here](https://github.com/TomBebb/mojoAL-switch/releases/tag/latest) for the latest release and copy the .a file to `$DEVKITPRO/portlibs/switch/lib`

### Installing WizEngineCore
Build via
```
cd core
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/DevkitA64Libnx.cmake
cd build
make
cd ..
./install-built-library.sh
```

### Launch homebrew with debug printing for hardware testing
* `/opt/devkitpro/tools/bin/nxlink -s path/to/homebrew.nro`