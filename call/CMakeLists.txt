cmake_minimum_required (VERSION 3.16.3)

project(aa)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_LIST})

if(MSVC)
    target_include_directories(${PROJECT_NAME}
    PRIVATE 
	"F:/work/code/mailio/mailio-dev/include"
	"F:/work/code/ggk/public/3rdparty/boost"
	)
	target_link_directories(${PROJECT_NAME}
    PRIVATE
    "F:/work/code/mailio/mailio-dev/libs/win32"
	)
	target_link_libraries(${PROJECT_NAME} mailio libcrypto libssl)
else
	target_link_directories(${PROJECT_NAME}
    PRIVATE
    "F:/work/code/mailio/mailio-dev/libs/win32"
	)
	target_link_libraries(${PROJECT_NAME} mailio crypto ssl)
endif()

