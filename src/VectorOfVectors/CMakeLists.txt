

add_executable(VectorOfVectors 
  ${CMAKE_SOURCE_DIR}/src/VectorOfVectors/main.cpp  
  ${CMAKE_SOURCE_DIR}/src/VectorOfVectors/VectorOfVectors.cpp  
  $<$<BOOL:${DOFUZZ}>:${CMAKE_SOURCE_DIR}/src/VectorOfVectors/fuzz/fuzz.cpp>  
)