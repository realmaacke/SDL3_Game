project('game', 'cpp',
  version : '0.1.0',
  default_options : [
    'cpp_std=c++20',
    'warning_level=3',
    'buildtype=debugoptimized'
  ]
)

pkg_datadir = get_option('prefix') / get_option('datadir') / meson.project_name()

# Installs the folder to: <prefix>/share/game/resources
install_subdir('resources', install_dir : pkg_datadir)

sdl3_dep    = dependency('sdl3', fallback: ['sdl3', 'sdl3_dep'])

sources = run_command('find', 'src', '-name', '*.cpp', check: true).stdout().strip().split('\n')
inc = include_directories('include', 'external')

add_project_arguments(
  '-DAPP_RESOURCE_DIR="' + pkg_datadir / 'resources"',
  language : 'cpp'
)

executable('game',
  sources,
  install: false,
  include_directories : inc,
  dependencies : [sdl3_dep]
)