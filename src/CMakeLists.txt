include_directories(${LEARNING_CPP_SOURCE_DIR})
link_directories(${LEARNING_CPP_BINARY_DIR})



add_library(buffer buffer.cpp)
add_executable(testSocket testSocket.cpp)
target_link_libraries(testSocket buffer)
#add_executable(buffer buffer.cpp)

#these are all compiled the same way
#set(PROGRAMS oglfirst pointers)
#set(CORELIBS ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)

#foreach(program ${PROGRAMS})
#  add_executable(${program} ${program}.cpp)
#  target_link_libraries(${program} ${CORELIBS})
#endforeach(program)

#building just a library. 

#add_executable(test_geometry test_geometry.cpp)
#linking against a custom library
#target_link_libraries(test_geometry ${CORELIBS} geometry)
