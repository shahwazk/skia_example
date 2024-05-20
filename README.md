# SKIA EXAMPLE PROJECT

This is an example CMakeLists based that integrates Google's [Skia](https://skia.org) library.

```
Skia is an open source 2D graphics library which provides common APIs that work across a variety of hardware and software platforms. It serves as the graphics engine for Google Chrome and ChromeOS, Android, Flutter, and many other products.
```

This repo has only one [main.cpp](src/main.cpp) file that will generate an `output.png` file as shown below using skia's official api usage [page](https://skia.org/docs/user/api/skcanvas_overview/)

![output.png](output.png)

## Install depot_tools and Git

Follow the instructions on [Installing Chromium’s depot_tools](http://www.chromium.org/developers/how-tos/install-depot-tools) to download depot_tools (which includes gclient, git-cl, and Ninja). Below is a summary of the necessary steps.

```bash
mkdir skia_setup && cd skia_setup

git clone 'https://chromium.googlesource.com/chromium/tools/depot_tools.git'
export PATH="${PWD}/depot_tools:${PATH}"
```
**NOTE**: depot_tools will also install Git on your system, if it wasn’t installed already


## Install ninja
Ninja can be supplied using `gclient` or with `bin/fetch-ninja`.


# Clone the Skia repository
Skia can either be cloned using git or the fetch tool that is installed with depot_tools.

```bash
cd skia_setup
git clone https://skia.googlesource.com/skia.git
cd skia
python3 tools/git-sync-deps
bin/fetch-ninja
```
**RECOMMENDED**
When running the above commands and syncing deps using commands `python3 tools/git-sync-deps` you might face `Thread failure`. So try to run the command multiple times and see if it works. In case `Thread failure` is still persistent then follow the below steps.

Instead of cloning, we'll use `fetch` tool from `depot_tools` to clone skia and all the dependencies. Make sure you export the depot_tools to `PATH`

```bash
export PATH="${PWD}/depot_tools:${PATH}"
```

After exporting, run the following commands:

```bash
fetch skia
```
Once the fetch process is complete, run the following command to install any other dependencies

```bash
cd skia
tools/install_dependencies.sh
```

Now we have all the necessary tools and dependencies to successfully build skia.

## Generate Compilation Rules
Thanks to [asperite](https://github.com/aseprite) for the next steps on generating compilation rules for skia. Basically there are two options:

### Clang
Some more tools to install if using clang for builing
```bash
sudo apt-get install libc++-dev libc++abi-dev
```

1. Generate rules for compiling skia using clang (**recommended** if you have clang compiler):
    ```bash
     gn gen out/Release-clang --args='is_debug=false is_official_build=true skia_use_system_expat=false skia_use_system_icu=false skia_use_system_libjpeg_turbo=false skia_use_system_libpng=false skia_use_system_libwebp=false skia_use_system_zlib=false skia_use_sfntly=false skia_use_freetype=true skia_use_harfbuzz=true skia_pdf_subset_harfbuzz=true skia_use_system_freetype2=false skia_use_system_harfbuzz=false cc="clang" cxx="clang++" extra_cflags_cc=["-stdlib=libc++"] extra_ldflags=["-stdlib=libc++"]'
    ```

### G++
2. Generate rules for compiling skia using the default compiler (usually g++):

    ```bash

    gn gen out/Release-gcc --args="is_debug=false is_official_build=true skia_use_system_expat=false skia_use_system_icu=false skia_use_system_libjpeg_turbo=false skia_use_system_libpng=false skia_use_system_libwebp=false skia_use_system_zlib=false skia_use_sfntly=false skia_use_freetype=true skia_use_harfbuzz=true skia_pdf_subset_harfbuzz=true skia_use_system_freetype2=false skia_use_system_harfbuzz=false"
    ```

Final step:

```bash
ninja -C out/Release-x64 skia modules
```
Visit official skia [website](https://skia.org/docs/user/build/) for more info on build process.


## Build Skia_Example project
Now that we are done building skia, we can build this example repo showing how to use skia in your project.

**NOTE**: Assuming that both `skia_setup` and `skia_example` are on the same level in the directory. If not then make sure they are because the path for `skia` in `CMakeLists.txt` for the `skia_example` is set in such a way that it looks for `skia` on the same level as `skia_example`.

Also this example is built using the clang compilation rools instead of g++.

```bash
set(SKIA_DIR ${CMAKE_SOURCE_DIR}/../skia_setup/skia)
```

### Builid skia_example

```bash
cd skia_example
mkdir build && cd build

cmake ..
make
```

```bash
# To run executable
./skia_example
```
The above commands should generate a `skia_example` executable inside the build directory, when run will generate the `output.png` file.
