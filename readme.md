# About

Fork of [Ork](https://gitlab.inria.fr/neyret/ork) library with SCons build support.

# Build

Following lines describes how to build *Ork* under *Ubuntu 24.04 LTS* (*Ubuntu 22.04 LTS*).

- download *glew* library from [glew](https://glew.sourceforge.net/) page where 1.5.6 version can be downloaded [here](https://sourceforge.net/projects/glew/files/glew/1.5.6/)

> **note**: We can't install *glew* from repository because the current *Ubuntu 22.04 LTS* already contains version 2.2 which is not API compatible with the older one.

- unpack with
```bash
tar -xaf glew-1.5.6.tgz
```
command.

- install *glew* dependencies with
```bash
sudo apt install libxmu-dev libglu1-mesa-dev libglut-dev
```
command

- build with
```bash
cd glew-1.5.6
make -j8
```
command
> **note**: works only with tarball (not zip glew library file)

- install to `/usr/local` directory with
```bash
sudo make GLEW_DEST=/usr/local install
```
command. Where *glew* library in installed to `/usr/local` directory.

- create linker configuration for `/usr/local/lib64` where *glew* was installed. Go to configuration directory with

```bash
cd /etc/ld.so.conf.d
```

and create `usr_local.conf` with following

```console
$ cat usr_local.conf
# linker configuration for /usr/local
/usr/local/lib64
```

content

- update linker cache with

```bash
sudo ldconfig
```

Be aware that (`/usr/local/lib64/pkgconfig`) pkg-config install directory is not searched by `pkg-config` command and as a result `pkg-config` is not aware of locally installed *glew* library e.g.

```console
$ pkg-config --modversion glew
2.2.0
```

can return 2.2.0 (version of *glew* library installed by package manager) instead of 1.5.6 version installed manually.

This can be solved by setting `PKG_CONFIG_PATH` environment variable from build script with

```python
env.AppendENVPath('PKG_CONFIG_PATH', '/usr/local/lib64/pkgconfig')
```

line (see `SConstruct` file).

Now finally we can run

```bash
scons -j8
```

command to build *Ork* library.

## Issues

1. undefined reference to `glEnable`

```
/bin/ld: libork.a(FrameBuffer.o): undefined reference to symbol 'glEnable'
/bin/ld: /lib/x86_64-linux-gnu/libGL.so.1: error adding symbols: DSO missing from command line
```

There are missing `-lGL -lX11 -lGLU` dependencies for *glew* library in a pkg-config configuration.


# Run

After successful build, examples can be found in `examples` directory.

```console
$ cd examples
$ ./examples minimal
```

there are also *render*, *resource*, *scenegraph*, *scenegraphresource* and *tessellation* examples there.

Run

```bash
./examples render .
```

command for *render* example or

```bash
./examples resource .
```

command for *resource* or

```bash
./examples scenegraph .
```

command for *scenegraph* or

```bash
./example scenegraphresource . cubesScene|exampleScene|postprocessScene|skyboxScene
```

command for scene graph from resource file sample or

```bash
./examples tessellation
```

command for a tessellation sample (GLSL 4.0).


> TODO: how to run tests to find errors?


## Issues

1. Unable to loading shared library `libGLEW.so.1.5`
```console
$ ./examples
./examples: error while loading shared libraries: libGLEW.so.1.5: c/etc/ld.so.conf.dannot open shared object file: No such file or directory
```

The root cause is that the library in not in a linker cache.

```console
$ ldconfig -p|grep -i glew
        libGLEW.so.2.2 (libc6,x86-64) => /lib/x86_64-linux-gnu/libGLEW.so.2.2
        libGLEW.so (libc6,x86-64) => /lib/x86_64-linux-gnu/libGLEW.so
```

There is missig linker configuration for `/usr/lib64` in `/etc/ld.so.conf.d` directory.
> TODO: what needs to be done in that case? How to fix it.

2. *OpenGL error 1282* complain for exampes

```console
$ ./examples minimal
ERROR [RENDER] OpenGL error 1282, returned string 'invalid operation'
invalid operation
examples: ork/render/Program.cpp:660: void ork::Program::initUniforms(): Assertion `FrameBuffer::getError() == 0' failed.
Aborted (core dumped)
```

3. unknown sequence resource type for scenegraph example

```console
$ ./examples scenegraph .
...
ERROR [RESOURCE] Unknown resource type 'sequence' at line 1 in sequence>
```

this is because implicit resource type registration mechanism is optimized out by linker in case sequence resource part of the code is not called by an application (which is the case or runtime configuration). No idea how to force linker to not optimized out local static variables so therefore we've introduced explicit initialization as `ork::InitResourceTypes()` in `resources/InitResources.h` header.


# Install

To install *Ork* library run

```bash
sudo scons install
```

command and to update linker database, run

```bash
sudo ldconfig
```

> TODO: is linker searching in `/usr/local/lib` by default?

command.

The library is installed to `/usr/local/lib` directory.

# Documentation

To build documentation execute

```bash
cd doc
doxygen
```

commands, where documentation is stored into `doc/doc/html` directory (open `index.html` file).

