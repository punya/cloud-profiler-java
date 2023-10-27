cmake_minimum_required(VERSION 3.16)
project(profiler_java_agent)
include(FetchContent)
FetchContent_Declare(
  glog
  GIT_REPOSITORY https://github.com/google/glog.git
  GIT_TAG v0.6.0
  SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/download_deps/glog)
FetchContent_MakeAvailable(glog)

find_package(JNI REQUIRED)
add_library(
  ${PROJECT_NAME} SHARED
  src/cloud_env.cc
  src/entry.cc
  src/http.cc
  src/jni.cc
  src/pem_roots.cc
  src/profiler.cc
  src/proto.cc
  src/string.cc
  src/threads.cc
  src/throttler_api.cc
  src/throttler_timed.cc
  src/uploader.cc
  src/uploader_gcs.cc
  src/worker.cc)
target_include_directories(${PROJECT_NAME} PRIVATE . ${JNI_INCLUDE_DIRS}
                                                   glog::glog)
target_link_libraries(${PROJECT_NAME} glog::glog)
