#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "leptonica" for configuration "Release"
set_property(TARGET leptonica APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(leptonica PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/leptonica-1.83.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/leptonica-1.83.1.dll"
  )

list(APPEND _cmake_import_check_targets leptonica )
list(APPEND _cmake_import_check_files_for_leptonica "${_IMPORT_PREFIX}/lib/leptonica-1.83.1.lib" "${_IMPORT_PREFIX}/bin/leptonica-1.83.1.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
