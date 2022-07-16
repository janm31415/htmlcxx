
set(HDRS
_api.h
ci_string.h
debug.h
Extensions.h
Node.h
ParserDom.h
ParserSax.h
profile.h
tld.h
tree.h
Uri.h
utils.h
    )

set(SRCS
Extensions.cc
Node.cc
ParserDom.cc
ParserSax.cc
ParserSax.tcc
Uri.cc
utils.cc
)

if (WIN32)
list(APPEND HDRS wincstring.h)
endif(WIN32)

if (WIN32)
set(CMAKE_C_FLAGS_DEBUG "/W4 /MP /GF /RTCu /Od /MDd /Zi")
set(CMAKE_CXX_FLAGS_DEBUG "/W4 /MP /GF /RTCu /Od /MDd /Zi")
set(CMAKE_C_FLAGS_RELEASE "/W4 /MP /GF /O2 /Ob2 /Oi /Ot /MD /Zi")
set(CMAKE_CXX_FLAGS_RELEASE "/W4 /MP /GF /O2 /Ob2 /Oi /Ot /MD /Zi")
endif(WIN32)


add_library(html SHARED ${HDRS} ${SRCS})


source_group("Header Files" FILES ${hdrs})
source_group("Source Files" FILES ${srcs})

target_include_directories(html
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  )
  
target_link_libraries(html
  PRIVATE
  )	
