cmake_minimum_required(VERSION 3.16)
project(cloud-profiler-java)
add_library(
  profiler_java_agent SHARED
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
