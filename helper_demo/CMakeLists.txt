cmake_minimum_required (VERSION 3.16.3)
project(mailio_helper_demo)

find_package(Boost REQUIRED COMPONENTS file_system)
#find_package(OpenSSL)

file(GLOB demo_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(mailio_helper_demo ${demo_files})
target_link_libraries(${file_name} PUBLIC mailio ${CMAKE_THREAD_LIBS_INIT})


install(TARGETS ${file_name} DESTINATION "${SHARE_INSTALL_DIR}/${PROJECT_NAME}")

