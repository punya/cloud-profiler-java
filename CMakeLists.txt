cmake_minimum_required(VERSION 3.16)
project(cloud-profiler-java)
add_library(profiler_java_agent SHARED src/*.cc)
