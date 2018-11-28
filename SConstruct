vars = Variables('custom.py')
vars.Add(BoolVariable('RELEASE','set to 1 for ', 1))
vars.Add(PathVariable('EMSDK', "path to emsdk dir", None))
vars.Add(PathVariable('OUTDIR', "path to output dir", 'out'))
env = Environment(variables = vars)
vars.Save('custom.py', env)


#env.Append( CPPPATH=['src', 'external'] )
if env['RELEASE']:
    flags = '-s WASM=1 -Oz'
    linkerflags = ''
else:
    flags = '-O0 -s WASM=0 -g4 -s ASSERTIONS=2 -s DEMANGLE_SUPPORT=1'
    linkerflags = "--pre-js {}/emscripten/1.38.20/src/emscripten-source-map.min.js".format(env['EMSDK'])

env.StaticLibrary('imgui',source=[
    'external/imgui.cpp',
    'external/imgui_demo.cpp',
    'external/imgui_draw.cpp'
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
env['ENV']['PATH'] += ':{}/clang/e1.38.20_64bit'.format(env['EMSDK'])
env['ENV']['PATH'] += ':{}/node/8.9.1_64bit/bin'.format(env['EMSDK'])
env['ENV']['PATH'] += ':{}/emscripten/1.38.20'.format(env['EMSDK'])

env['ENV']['EMSDK'] = env['EMSDK']
env['ENV']['BINARYEN_ROOT'] = '{}/clang/e1.38.20_64bit/binaryen'.format(env['EMSDK'])
env['ENV']['EMSCRIPTEN'] = '{}/emscripten/1.38.20'.format(env['EMSDK'])
