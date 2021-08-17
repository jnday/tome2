INSTALL(DIRECTORY 
  apex
  cmov
  data
  dngn
  edit
  file
  help
  info
  note
  pref
  save
  user
  xtra
  DESTINATION "${DEFAULT_PATH}/lib"
  PATTERN "*.raw" EXCLUDE
  PATTERN "delete.me" EXCLUDE
  )

ADD_SUBDIRECTORY (mods)
