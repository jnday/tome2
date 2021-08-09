INSTALL(FILES
  module.lua
  DESTINATION "${DEFAULT_PATH}/lib"
)
INSTALL(DIRECTORY 
  apex
  cmov
  core
  data
  dngn
  edit
  file
  help
  info
  mods
  note
  pref
  save
  scpt
  user
  xtra
  DESTINATION "${DEFAULT_PATH}/lib"
  PATTERN "*.raw" EXCLUDE
  PATTERN "delete.me" EXCLUDE
  )
