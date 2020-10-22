find_package(darabonba_util ${darabonba_util_MINIMUM_REQUIRED} QUIET COMPONENTS ${darabonba_util_COMPONENTS_REQUIRED})

if(darabonba_util_FOUND)
  message(STATUS "Found darabonba_util version ${darabonba_util_MAJOR_VERSION}.${darabonba_util_MINOR_VERSION}.${darabonba_util_SUBMINOR_VERSION}")
  add_library(darabonba_util_external INTERFACE)
else()
  message(STATUS "darabonba_util ${darabonba_util_MINIMUM_REQUIRED} could not be located, Building darabonba_util instead.")
  include(FetchContent)

  FetchContent_Declare(
    _darabonba_util
    GIT_REPOSITORY https://github.com/alibabacloud-sdk-cpp/dara-util.git
    GIT_TAG master)
  
  FetchContent_GetProperties(_darabonba_util)
  if(NOT _darabonba_util_POPULATED)
    FetchContent_Populate(_darabonba_util)
    message(STATUS "Added darabonba_util source : ${_darabonba_util_SOURCE_DIR}")
    message(STATUS "Added darabonba_util binary : ${_darabonba_util_BINARY_DIR}")
    add_subdirectory(
      ${_darabonba_util_SOURCE_DIR} 
      ${_darabonba_util_BINARY_DIR}
    )
    target_include_directories(alibabacloud_rpc INTERFACE "${_darabonba_util_SOURCE_DIR}/include")
  endif()
endif()
