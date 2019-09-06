project('hello-triangle', 'cpp')

compiler = meson.get_compiler('cpp')
deps = [compiler.find_library('SDL2', dirs : 'C:\usr\lib64'),
	compiler.find_library('SDL2main', dirs : 'C:\usr\lib64'),
	compiler.find_library('vulkan-1', dirs : 'C:\usr\lib64')]
	
executable('hello-triangle', 'main.cpp',
    include_directories : include_directories('C:\usr\include'),
    dependencies : deps,
	gui_app : true)