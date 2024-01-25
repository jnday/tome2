SET(SRCS
  main-gcu.c main-x11.c main-xaw.c main-sdl.c main-gtk2.c
  z-rand.c z-util.c z-form.c z-virt.c z-term.c
  variable.c tables.c plots.c util.c cave.c dungeon.c 
  melee1.c melee2.c messages.c modules.c
  q_god.c
  object1.c object2.c randart.c squeltch.c traps.c 
  monster1.c monster2.c monster3.c
  xtra1.c xtra2.c skills.c powers.c gods.c
  spells1.c spells2.c spells3.c spells4.c spells5.c spells6.c
  spell_type.c
  corrupt.c joke.c mimic.c
  status.c files.c notes.c loadsave.c string_list.c
  cmd1.c cmd2.c cmd3.c cmd4.c cmd5.c cmd6.c cmd7.c
  help.c hiscore.c range.c
  generate.c gen_maze.c gen_evol.c wild.c levels.c store.c bldg.c
  cmovie.c
  wizard2.c init2.c birth.c wizard1.c init1.c main.c 
  quark.c
  # Lua bits:
  lua_bind.c script.c
  # Windows bits:
  main-win.c readdib.c angband.rc
)

# tome executable
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
ADD_EXECUTABLE(tome ${EXECUTABLE_OPTIONS} ${SRCS})
TARGET_LINK_LIBRARIES(tome ${LIBS})

add_custom_target(copy_resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/res/lib ${CMAKE_CURRENT_BINARY_DIR}/lib
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/res/.tome ${CMAKE_CURRENT_BINARY_DIR}/.tome
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/res/tome.ini ${CMAKE_CURRENT_BINARY_DIR}/tome.ini
)   
add_dependencies(tome copy_resources)


set(VCPKG_DEBUG_BIN_DIR ${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/debug/bin)
set(VCPKG_BIN_DIR ${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/bin)

# post-build dll copy
add_custom_command(
	TARGET tome POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:tome> ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${VCPKG_DEBUG_BIN_DIR}/freetyped.dll ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${VCPKG_DEBUG_BIN_DIR}/libpng16d.dll ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${VCPKG_DEBUG_BIN_DIR}/zlibd1.dll ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${VCPKG_DEBUG_BIN_DIR}/bz2d.dll ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${VCPKG_DEBUG_BIN_DIR}/brotlidec.dll ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${VCPKG_DEBUG_BIN_DIR}/brotlicommon.dll ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${VCPKG_DEBUG_BIN_DIR}/brotlienc.dll ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND_EXPAND_LISTS
)

# Installation
INSTALL(TARGETS tome
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    INSTALL(
        FILES
        ${CMAKE_SOURCE_DIR}/res/tome.ini
        ${VCPKG_DEBUG_BIN_DIR}/freetyped.dll
        ${VCPKG_DEBUG_BIN_DIR}/libpng16d.dll
        ${VCPKG_DEBUG_BIN_DIR}/zlibd1.dll
        ${VCPKG_DEBUG_BIN_DIR}/bz2d.dll
        ${VCPKG_DEBUG_BIN_DIR}/brotlidec.dll
        ${VCPKG_DEBUG_BIN_DIR}/brotlicommon.dll
        ${VCPKG_DEBUG_BIN_DIR}/brotlienc.dll
        $<TARGET_RUNTIME_DLLS:tome>
        DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
else()
    INSTALL(
        FILES
        ${CMAKE_SOURCE_DIR}/res/tome.ini
        $<TARGET_RUNTIME_DLLS:tome>
        DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
endif()

INSTALL(
    DIRECTORY
    ${CMAKE_SOURCE_DIR}/res/.tome
    ${CMAKE_SOURCE_DIR}/res/lib
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)