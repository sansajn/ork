# ork build script
env = Environment()

env.Append(
	CCFLAGS = ['-g', '-O0']
)

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
	stbi_src
]

env.Append(
	CCFLAGS=['-DORK_API=', '-DTIXML_USE_STL', '-fPIC'],
	CPPPATH=['libraries', '.']
)

ork_lib = env.Library('libork', ork_src)

env.SharedLibrary('libork', ork_src)


# examples
common_libs = ['GL', 'GLU', 'GLEW', 'glut', 'pthread']
example_src = Glob('examples/*.cpp')

env.Program(
	'examples/examples', 
	[example_src], 
	LIBS=[ork_lib, common_libs]
)

