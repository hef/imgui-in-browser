import os
vars = Variables('custom.py')
vars.Add(BoolVariable('RELEASE','set to 1 for ', 1))
vars.Add(PathVariable('EMSDK', "path to emsdk dir", os.environ.get('EMSDK')))
vars.Add(PathVariable('OUTDIR', "path to output dir", 'out'))
env = Environment(variables = vars)
vars.Save('custom.py', env)


#env.Append( CPPPATH=['src', 'external'] )
if env['RELEASE']:
    flags = '-s WASM=1 -Oz'
    linkerflags = ''
else:
    flags = '-O0 -s WASM=1 -g4 -s ASSERTIONS=2 -s SAFE_HEAP=1 -s DEMANGLE_SUPPORT=1 --source-map-base /'
    linkerflags = ''

env.StaticLibrary('imgui',source=[
    'external/imgui.cpp',
    'external/imgui_demo.cpp',
    'external/imgui_draw.cpp',
    'external/imgui_widgets.cpp'
])
env.StaticLibrary('core', source=[
    'src/draw.cpp',
    'src/funimgui.cpp',
    'src/main.cpp',
], CPPPATH=['external'])
index = env.Program(target='{}/index.js'.format(env['OUTDIR']), source=[
'src/em.cpp'
], LIBS=['core', 'imgui'], LIBPATH='.')
Default(index)

env['CC'] = 'emcc'
env['CXX'] = 'em++'
env['AR'] = 'emar'
env['RANLIB'] = 'emranlib'
env['CXXFLAGS'] = '-std=c++14 ' + flags
env['LINKFLAGS'] = flags + " --bind " + linkerflags
env['ENV']['PATH'] += ':{}'.format(env['EMSDK'])
env['ENV']['PATH'] += ':{}/upstream/emscripten'.format(env['EMSDK'])

env['ENV']['EMSDK'] = env['EMSDK']
