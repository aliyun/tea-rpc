find_package(alibabacloud_rpcutil ${alibabacloud_rpcutil_MINIMUM_REQUIRED} QUIET COMPONENTS ${alibabacloud_rpcutil_COMPONENTS_REQUIRED})

if(alibabacloud_rpcutil_FOUND)
  message(STATUS "Found alibabacloud_rpcutil version ${alibabacloud_rpcutil_MAJOR_VERSION}.${alibabacloud_rpcutil_MINOR_VERSION}.${alibabacloud_rpcutil_SUBMINOR_VERSION}")
  add_library(alibabacloud_rpcutil_external INTERFACE)
else()
  message(STATUS "alibabacloud_rpcutil ${alibabacloud_rpcutil_MINIMUM_REQUIRED} could not be located, Building alibabacloud_rpcutil instead.")
  include(FetchContent)

  FetchContent_Declare(
    _alibabacloud_rpcutil
    GIT_REPOSITORY https://github.com/alibabacloud-sdk-cpp/rpcutil.git
    GIT_TAG master)
  
  FetchContent_GetProperties(_alibabacloud_rpcutil)
  if(NOT _alibabacloud_rpcutil_POPULATED)
    FetchContent_Populate(_alibabacloud_rpcutil)
    message(STATUS "Added alibabacloud_rpcutil source : ${_alibabacloud_rpcutil_SOURCE_DIR}")
    message(STATUS "Added alibabacloud_rpcutil binary : ${_alibabacloud_rpcutil_BINARY_DIR}")
    add_subdirectory(
      ${_alibabacloud_rpcutil_SOURCE_DIR} 
      ${_alibabacloud_rpcutil_BINARY_DIR}
    )
    target_include_directories(alibabacloud_rpc PRIVATE "${_alibabacloud_rpcutil_SOURCE_DIR}/include")
  endif()
endif()
