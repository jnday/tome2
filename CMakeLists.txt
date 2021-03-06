# Project definition.
PROJECT (tome2)
CMAKE_MINIMUM_REQUIRED (VERSION 2.9)

# We want a readable feature summary.
INCLUDE(FeatureSummary)

# Default flags.
IF(CMAKE_COMPILER_IS_GNUCC)
  # Let's set sensible options.
  SET(CMAKE_C_FLAGS         "${CMAKE_C_FLAGS} -pipe -Wall -Wno-unused-value -Wno-unused-variable")
  SET(CMAKE_C_FLAGS_RELEASE "-O2")
  SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g")
ENDIF()

# Add definitions.
ADD_DEFINITIONS(-DUSE_PRECISE_CMOVIE)

#
# JSON support
#
FIND_PACKAGE(JANSSON CONFIG REQUIRED)
IF(JANSSON_FOUND)
  set(LIBS ${LIBS} jansson::jansson)
  ADD_FEATURE_INFO(JANSSON JANSSON_FOUND "enabled")
ENDIF()

#
# X11 support (OPTIONAL)
#
FIND_PACKAGE(X11)
IF(X11_FOUND)
  # Add X11 flags/options
  ADD_DEFINITIONS(-DUSE_X11)
  INCLUDE_DIRECTORIES(${X11_INCLUDE_DIR})
  SET(LIBS ${LIBS} ${X11_LIBRARIES})
  ADD_FEATURE_INFO(X11 X11_FOUND "enabled")
ENDIF()

#
# GTK2 support (OPTIONAL)
#
FIND_PACKAGE(GTK2)
IF(GTK2_FOUND)
  # Add GTK flags/options
  ADD_DEFINITIONS(-DUSE_GTK2)
  INCLUDE_DIRECTORIES(${GTK2_INCLUDE_DIRS})
  SET(LIBS ${LIBS} ${GTK2_LIBRARIES})
  ADD_FEATURE_INFO(GTK2 GTK2_FOUND "enabled")
ENDIF()

#
# SDL support (OPTIONAL)
#
FIND_PACKAGE(SDL)
IF(SDL_FOUND)
  # This is a bit roundabout, but we're working around
  # the FindSDL_* scripts not respecting the REQUIRED
  # flag.
  #
  # the SDL port also requires SDL_image and SDL_ttf
  FIND_PACKAGE(SDL_image)
  FIND_PACKAGE(SDL_ttf)
  IF(SDLIMAGE_FOUND AND SDLTTF_FOUND)
    # Add SDL flags/options
    ADD_DEFINITIONS(-DUSE_SDL)
    INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR} ${SDLTTF_INCLUDE_DIR})
    SET(LIBS ${LIBS} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY} ${SDL_LIBRARY})
    ADD_FEATURE_INFO(SDL SDL_FOUND "enabled")
  ELSE()
    # Let user know that (and why) we haven't enabled SDL.
    IF(SDLIMAGE_FOUND)
      MESSAGE(STATUS "Found SDL and SDL_image, but not SDL_ttf!")
    ELSEIF(SDLTTF_FOUND)
      MESSAGE(STATUS "Found SDL and SDL_ttf, but not SDL_image!")
    ELSE()
      MESSAGE(STATUS "Found SDL, but not SDL_image nor SDL_ttf!")
    ENDIF()
    # add info about finding but not enabling SDL
    ADD_FEATURE_INFO(SDL SDL_FOUND "not enabled")
  ENDIF()
ENDIF()

#
# Curses support (OPTIONAL)
#
FIND_PACKAGE(Curses)
IF(CURSES_FOUND)
  # Add Curses flags/options
  ADD_DEFINITIONS(-DUSE_GCU)
  INCLUDE_DIRECTORIES(${CURSES_INCLUDE_DIR})
  SET(LIBS ${LIBS} ${CURSES_LIBRARIES})
  ADD_FEATURE_INFO(CURSES CURSES_FOUND "enabled")
ENDIF()

#
# Windows support
#
if(WIN32)
  # Add Windows flags/options
  #ADD_DEFINITIONS(-DWINDOWS)
  SET(EXECUTABLE_OPTIONS WIN32)
  SET(LIBS ${LIBS} winmm wsock32)
endif(WIN32)

#
# Set the path for loading the library bits.
#
IF(SYSTEM_INSTALL)
  SET(DEFAULT_PATH ${CMAKE_INSTALL_PREFIX}/lib/tome)
ELSE()
  SET(DEFAULT_PATH ${CMAKE_INSTALL_PREFIX})
ENDIF()
ADD_DEFINITIONS(-DDEFAULT_PATH=${DEFAULT_PATH}/)

INSTALL(FILES
  tome.ini
  DESTINATION ${CMAKE_INSTALL_PREFIX}
)
INSTALL(DIRECTORY
  DESTINATION ${CMAKE_INSTALL_PREFIX}/.tome/2.3/save
)
INSTALL(DIRECTORY
  DESTINATION ${CMAKE_INSTALL_PREFIX}/.tome/2.3/theme
)
INSTALL(DIRECTORY
  DESTINATION ${CMAKE_INSTALL_PREFIX}/.tome/2.3/save/theme
)

# Print out a summary of features.
feature_summary(WHAT ENABLED_FEATURES DESCRIPTION "Enabled features:")

# Add the source subdirectory.
ADD_SUBDIRECTORY (src)
ADD_SUBDIRECTORY (lib)
