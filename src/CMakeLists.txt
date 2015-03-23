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

#include_directories(${CMAKE_CURRENT_LIST_DIR} )
include_directories("${CMAKE_CURRENT_LIST_DIR}/spirit" )
include_directories("${CMAKE_CURRENT_LIST_DIR}/pattern/singelton/variant_1" )
include_directories("${CMAKE_CURRENT_LIST_DIR}/asyncprotocol_stack" )
include_directories("${CMAKE_CURRENT_LIST_DIR}/event_bus" )
include_directories("${CMAKE_CURRENT_LIST_DIR}/event_bus/event_bus" )
include_directories("${CMAKE_CURRENT_LIST_DIR}/boost_costum_errorcodes" )



file(GLOB_RECURSE SOURCES_HEX_TO_BINARY "tests/parser_performance/*.cpp")
file(GLOB_RECURSE SOURCES_SPIRIT "spirit/*.cpp")
file(GLOB_RECURSE SOURCES_PATTERN "pattern/*.cpp")
file(GLOB_RECURSE SOURCES_PARSE "parse/*.cpp")
file(GLOB_RECURSE SOURCES_SPIRIT "spirit/*.cpp")
file(GLOB_RECURSE SOURCES_ERROR_CODES "boost_costum_errorcodes/*.cpp")
 
message(STATUS "SOURCES_ERROR_CODES  ${SOURCES_ERROR_CODES}")
message(STATUS "Includes ${CMAKE_CURRENT_LIST_DIR}/boost_costum_errorcodes")
#message(STATUS "Includes ${CMAKE_CURRENT_LIST_DIR}/asyncprotocol_stack") 


#### Project Build Targets
add_executable(hex_to_binary  ${SOURCES_HEX_TO_BINARY} )

add_executable(spirit  ${SOURCES_SPIRIT} )
add_executable(main main.cpp ${SOURCES_ASYNC} ${SOURCES_PATTERN} ${SOURCES_ERROR_CODES})

add_executable(event_bus_main ${CMAKE_CURRENT_LIST_DIR}/event_bus/event_bus_main.cpp  )
add_executable(event_bus_client ${CMAKE_CURRENT_LIST_DIR}/event_bus/client_main.cpp  )


#### Linking
target_link_libraries(main ${Boost_LIBRARIES} ${PSAPI_LIBRARIES}  pthread)
target_link_libraries(spirit ${Boost_LIBRARIES} ${PSAPI_LIBRARIES} pthread)
#target_link_libraries(main_spirit ${Boost_LIBRARIES} ${PSAPI_LIBRARIES} pthread)
target_link_libraries(event_bus_main ${Boost_LIBRARIES} ${PSAPI_LIBRARIES} pthread)
target_link_libraries(event_bus_client ${Boost_LIBRARIES} ${PSAPI_LIBRARIES} pthread)
 

	
if(WIN32)
  target_link_libraries(main wsock32 ws2_32)
endif()

#------------------------------------
# Installation
#------------------------------------


