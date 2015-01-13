#------------------------------------
# Global Vars
#------------------------------------


#------------------------------------
# Dependencies
#------------------------------------
# Boost
set(BOOST_ALL_DYN_LINK ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)    
find_package(Boost 1.55 COMPONENTS  serialization thread date_time filesystem system program_options log log_setup REQUIRED )
link_directories (${Boost_LIBRARY_DIRS})
include_directories (${Boost_INCLUDE_DIRS})
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

# Threads
find_package(Threads)

if(WIN32)
    find_library(PSAPI_LIBRARIES psapi)
endif()

#------------------------------------
# Project Setup
#------------------------------------
#### Project Files

include_directories(${CMAKE_CURRENT_LIST_DIR} )
include_directories("${CMAKE_CURRENT_LIST_DIR}/pattern/singelton/variant_1" )
include_directories("${CMAKE_CURRENT_LIST_DIR}/asyncprotocol_stack" )


file(GLOB_RECURSE SOURCES "*.cpp")


message(STATUS "SOURCES  ${SOURCES}")
message(STATUS "Includes ${CMAKE_CURRENT_LIST_DIR}/pattern/singelton/variant_1")
message(STATUS "Includes ${CMAKE_CURRENT_LIST_DIR}/asyncprotocol_stack") 


#### Project Build Targets
add_executable(main  ${SOURCES} )


#### Linking
target_link_libraries(main ${Boost_LIBRARIES} ${PSAPI_LIBRARIES} pthread)


	
if(WIN32)
  target_link_libraries(main wsock32 ws2_32)
endif()

#------------------------------------
# Installation
#------------------------------------

