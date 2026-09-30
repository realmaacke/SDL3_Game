project('game', 'cpp',
  version : '0.1.0',
  default_options : [
    'cpp_std=c++20',
    'warning_level=3',
    'buildtype=debugoptimized'
  ]
)

sdl3_dep = dependency('sdl3', fallback: ['sdl3', 'sdl3_dep'])

custom_target('cfg',
  output: 'cfg',
  command: ['cp', '-rT', meson.project_source_root() / 'cfg', '@OUTPUT@'],
  build_by_default: true,
  build_always_stale: true,
)

sources = run_command('find', 'src', '-name', '*.cpp', check: true).stdout().strip().split('\n')
inc = include_directories('include', 'external')

executable('game',
  sources,
  include_directories : inc,
  dependencies : [sdl3_dep]
)