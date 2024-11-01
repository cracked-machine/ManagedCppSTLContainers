
include_directories(${CMAKE_SOURCE_DIR}/src/EncapsulatedEnums)

add_executable(EncapsulatedEnums 
  ${CMAKE_SOURCE_DIR}/src/EncapsulatedEnums/main.cpp  
  $<$<BOOL:${DOFUZZ}>:${CMAKE_SOURCE_DIR}/src/EncapsulatedEnums/fuzz/fuzz.cpp>  
)