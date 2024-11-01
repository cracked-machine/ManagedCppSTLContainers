
set(BUILDTARGET "EncapsulatedEnums")

include_directories(${CMAKE_SOURCE_DIR}/src/${BUILDTARGET})

add_executable(${BUILDTARGET} 
  ${CMAKE_SOURCE_DIR}/src/${BUILDTARGET}/main.cpp  
  $<$<BOOL:${DOFUZZ}>:${CMAKE_SOURCE_DIR}/src/${BUILDTARGET}/fuzz/fuzz.cpp>  
)

add_subdirectory(test)