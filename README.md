# Last Square Standing

## Dependencies
- [CMake][]
- [SDL2][SDL] library
- [SDL2_image][] library

**On Debian/Ubuntu based distributions, use the following command:**
```sh
sudo apt install git build-essential pkg-config cmake cmake-data libsdl2-dev libsdl2-image-dev
```

## Build instructions
```sh
# Clone this repo
git clone https://github.com/mertcanekiz/lss.git
cd lss

# Create a build folder
mkdir build
cd build

#Build
cmake ..
make

#Run
../bin/lss
```

[CMake]: https://cmake.org
[SDL]: https://www.libsdl.org
[SDL2_image]: https://www.libsdl.org/projects/SDL_image