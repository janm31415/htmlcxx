set(HDRS
    )
	
set(SRCS
tests.cc
)

if (WIN32)
list(APPEND HDRS ../getopt/getopt.h)
list(APPEND SRCS ../getopt/getopt.c)
endif(WIN32)

if (WIN32)
set(CMAKE_C_FLAGS_DEBUG "/W4 /MP /GF /RTCu /Od /MDd /Zi")
set(CMAKE_CXX_FLAGS_DEBUG "/W4 /MP /GF /RTCu /Od /MDd /Zi")
set(CMAKE_C_FLAGS_RELEASE "/W4 /MP /GF /O2 /Ob2 /Oi /Ot /MD /Zi /DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "/W4 /MP /GF /O2 /Ob2 /Oi /Ot /MD /Zi /DNDEBUG")
endif (WIN32)

# general build definitions
add_definitions(-D_SCL_SECURE_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)


add_definitions(-DMEMORY_LEAK_TRACKING)

add_executable(tests ${HDRS} ${SRCS})
source_group("Header Files" FILES ${hdrs})
source_group("Source Files" FILES ${srcs})	

target_include_directories(tests
      PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/..
      )
      
target_link_libraries(tests
      PRIVATE
      htmlcxx
      )

