# ork build script

env = Environment()

# ork
env.Append(
	CCFLAGS=['-DORK_API=', '-DTIXML_USE_STL', '-fPIC'],
	CPPPATH=['libraries', '.'])

core_objs = env.Object(Glob('ork/core/*.cpp'))
math_objs = env.Object(Glob('ork/math/*.cpp'))
render_objs = env.Object(Glob('ork/render/*.cpp'))
resource_objs = env.Object(Glob('ork/resource/*.cpp'))
scenegraph_objs = env.Object(Glob('ork/scenegraph/*.cpp'))
taskgraph_objs = env.Object(Glob('ork/taskgraph/*.cpp'))
ui_objs = env.Object(Glob('ork/ui/*.cpp'))
util_objs = env.Object(Glob('ork/util/*.cpp'))

# stbi
stbi_objs = env.Object(Glob('libraries/stbi/*.cpp'))

# tinyxml
tinyxml_objs = env.Object(Glob('libraries/tinyxml/*.cpp'))

ork_objs = [
	core_objs,
	math_objs,
	render_objs,
	resource_objs,
	scenegraph_objs,
	taskgraph_objs,
	ui_objs,
	util_objs,
	tinyxml_objs,
	stbi_objs
]

ork_lib = env.Library('libork.a', ork_objs)


# examples
common_libs = ['GL', 'GLU', 'GLEW', 'glut', 'pthread']
example_objs = env.Object(Glob('examples/*.cpp'))

env.Program('examples/examples', [example_objs], LIBS=[ork_lib, common_libs])
