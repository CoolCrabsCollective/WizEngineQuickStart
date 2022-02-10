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

If library is custom and thus not found using pacman, copy .a files to $DEVKITPRO/portlibs/switch/lib

### Installing switch-sfml
Run the installation bash script in the fork repo after building following the instructions in the readme on there

### Launch homebrew with debug printing for hardware testing
* `/opt/devkitpro/tools/bin/nxlink -s path/to/homebrew.nro`