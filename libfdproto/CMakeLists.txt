# Name of the subproject
Project("libfdproto" C)

# Configuration for newer cmake
cmake_policy(VERSION 2.6)
if (POLICY CMP0022)
	cmake_policy(SET CMP0022 OLD)
endif (POLICY CMP0022)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# List of source files for the library
SET(LFDPROTO_SRC
	fdproto-internal.h
	dictionary.c
	dictionary_functions.c
	dispatch.c
	fifo.c
	init.c
	lists.c
	log.c
	messages.c
	ostr.c
	portability.c
	rt_data.c
	sessions.c
	utils.c
	version.c
	hashlist.cpp
	)


# Save the list of files for testcases in the core's directory
SET(LFDPROTO_SRC ${LFDPROTO_SRC} PARENT_SCOPE)

# Include path
INCLUDE_DIRECTORIES(${LFDPROTO_INCLUDES})

# Build as a shared library
ADD_LIBRARY(libfdproto SHARED ${LFDPROTO_SRC})

ADD_DEPENDENCIES(libfdproto version_information)

# Avoid the liblib name, and set the version
SET_TARGET_PROPERTIES(libfdproto PROPERTIES 
	OUTPUT_NAME "fdproto"
	SOVERSION ${FD_PROJECT_VERSION_API}
	VERSION ${FD_PROJECT_VERSION_MAJOR}.${FD_PROJECT_VERSION_MINOR}.${FD_PROJECT_VERSION_REV}
	LINK_INTERFACE_LIBRARIES "${LFDPROTO_LINK_INTERFACES}")

# The library itself needs other libraries 
TARGET_LINK_LIBRARIES(libfdproto ${LFDPROTO_LIBS})


####
## INSTALL section ##

INSTALL(TARGETS libfdproto
	LIBRARY DESTINATION ${INSTALL_LIBRARY_SUFFIX}
	COMPONENT freeDiameter-common)

