set(BUILDTARGET "VectorOfVectors")

add_executable(${BUILDTARGET} 
  ${CMAKE_SOURCE_DIR}/src/${BUILDTARGET}/main.cpp  
  ${CMAKE_SOURCE_DIR}/src/${BUILDTARGET}/${BUILDTARGET}.cpp  
  $<$<BOOL:${DOFUZZ}>:${CMAKE_SOURCE_DIR}/src/${BUILDTARGET}/fuzz/fuzz.cpp>  
)

add_subdirectory(test)