# ork build script
# dependencies: libglew-dev <- in Ubuntu 22.04 LTS there is libglew 2.2 which is already too new for this version of ork (glew-1.5.6, needs to be installed manually)
# run 'scons --debug-build' for debug build

AddOption('--debug-build', action='store_true', dest='debug_build',
	help='debug build', default=False)

ork_env = Environment()

#for Ubuntu 22.04 LTS we need to build and install glew manually and it place pkg-config files to /usr/lib64/pkgconfig directory
ork_env.AppendENVPath('PKG_CONFIG_PATH', '/usr/lib64/pkgconfig')

ork_env.ParseConfig('pkg-config --libs --cflags glew')

ork_env.Append(
	LIBS=['glut', 'pthread', 'GL', 'X11', 'GLU'],  # issue: manually installed glew 1.5.6 pkg-config file is missing `-lGL -lX11 -lGLU` and so compilation fails
	CCFLAGS=['-fPIC'],
	CPPPATH=['libraries', '.'],
	CPPDEFINES=['ORK_API=', 'TIXML_USE_STL'])

if GetOption('debug_build'):
	ork_env.Append(CCFLAGS=['-g', '-O0', '-std=c++98'])
else:
	ork_env.Append(CCFLAGS=['-Os', '-std=c++98'])

# ork
core_src = Glob('ork/core/*.cpp')
math_src = Glob('ork/math/*.cpp')
render_src = Glob('ork/render/*.cpp')
resource_src = Glob('ork/resource/*.cpp')
scenegraph_src = Glob('ork/scenegraph/*.cpp')
taskgraph_src = Glob('ork/taskgraph/*.cpp')
ui_src = Glob('ork/ui/*.cpp')
util_src = Glob('ork/util/*.cpp')

# stbi
stbi_src = Glob('libraries/stbi/*.cpp')

# tinyxml
tinyxml_src = Glob('libraries/tinyxml/*.cpp')

ork_src = [
	core_src,
	math_src,
	render_src,
	resource_src,
	scenegraph_src,
	taskgraph_src,
	ui_src,
	util_src,
	tinyxml_src,
	stbi_src]

# static library
static_ork = ork_env.Library('libork', ork_src)

# shared library
shared_ork = ork_env.SharedLibrary('libork', ork_src)

# for install option run '$ scons install' and then '$ sudo ldconfig'
lib_dir = '/usr/local/lib'
ork_env.Install(lib_dir, shared_ork)
ork_env.Alias('install', lib_dir)

# examples
example_src = Glob('examples/*.cpp')

ork_env.Program(
	'examples/examples', [example_src, static_ork])

ork_env.Program(  # not working 'undefined symbol: __glewVertexAttrib4Nsv'
	'examples/examples-shared', [example_src, shared_ork])

