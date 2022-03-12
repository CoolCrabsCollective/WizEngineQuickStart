# WizEngineQuickStart
This project is meant to be a ready to run WizEngine template project for Windows, Linux and Switch. You can clone or fork this repo and start making your game. All dependencies (SFML, WizEngine) are handled by the project.

# Deploying the client

## Desktop

### Building

```
cd client
cmake -B build -S .
cd build
make
cd ..
```

This will produce an executable and copy required assets in the folder `client/bin/<your platform>/`. (e.g. `client/bin/linux64` on 64 bits Linux systems)

### Executing

```
cd bin/<your platform>/
./<Executable name> # Name will change according to your project name
```

Make sure you distribute all files that are in the `bin/<your platform>` folder. .so, .dll and res/ folder are all required by the game.

## Switch

### Development setup

This development setup only needs to be done once for the Switch. After this you can just build according to the method below.

#### Install Pacman

For Ubuntu:

Download Debian install package [here](https://github.com/devkitPro/pacman/releases/tag/v1.0.2)

* `sudo dpkg -i devkitpro-pacman.amd64.deb`

For ArchLinux:

Customize your existing pacman installation using this guide: https://devkitpro.org/wiki/devkitPro_pacman

#### use Pacman to install devkitA64 for compilation toolchains
* `sudo dkp-pacman -S switch-dev`
  (Hit enter to use all repositories by default)

#### Add DevKit environment variables to ~./bashrc file
```   
   export DEVKITPRO=/opt/devkitpro
   export DEVKITARM=/opt/devkitpro/devkitARM
   export DEVKITPPC=/opt/devkitpro/devkitPPC
```

#### Install specific libraries for switch development
`sudo dkp-pacman -S switch-sdl2 switch-sdl2_mixer switch-glad switch-bzip2 switch-zlib switch-mesa switch-libpng switch-libogg switch-flac switch-glm switch-sdl2_image switch-sdl2_ttf switch-libvorbis switch-openal-soft`

If library is custom and thus not found using pacman, copy .a files to `$DEVKITPRO/portlibs/switch/lib`

#### Installing WizEngine

Install the WizEngine using the following commands. This will install sfml as well at the same time.

```
git clone https://github.com/WinterAlexander/WizEngine
cd WizEngine
./switch-install.sh
```

This procedure should have copied the following files 
```
libWizEngine.a
libsfml-audio.a
libsfml-graphics.a
libsfml-network.a
libsfml-system.a
libsfml-window.a
```

to the directory `$DEVKITPRO/portlibs/switch/lib/`. Make sure they are present after this script has run.

#### Installing mojoAL-switch
Go [here](https://github.com/TomBebb/mojoAL-switch/releases/tag/latest) for the latest release and copy the .a file to `$DEVKITPRO/portlibs/switch/lib`


This completes the installation setup.

#### Launch homebrew with debug printing for hardware testing
* `/opt/devkitpro/tools/bin/nxlink -s path/to/homebrew.nro`

### Building

```
cd client
make
```

### Executing

Use the produced .nro file in the folder `client/bin/switch/` to run onto your switch or open with [Yuzu](https://yuzu-emu.org/).


# Deploying the server

TODO
