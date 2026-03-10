#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mailio::mailio" for configuration ""
set_property(TARGET mailio::mailio APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(mailio::mailio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmailio.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS mailio::mailio )
list(APPEND _IMPORT_CHECK_FILES_FOR_mailio::mailio "${_IMPORT_PREFIX}/lib/libmailio.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
