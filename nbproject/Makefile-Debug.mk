#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang-3.5
CCC=clang++-3.5
CXX=clang++-3.5
FC=gfortran
AS=llvm-as-3.5

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/net/Client.o \
	${OBJECTDIR}/src/net/TCPServer.o \
	${OBJECTDIR}/src/script/Entry.o \
	${OBJECTDIR}/src/util/Exception.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64
CXXFLAGS=-m64

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=--64

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread libs/v8/out/native/obj.target/tools/gyp/libv8_base.a libs/v8/out/native/obj.target/tools/gyp/libv8_libbase.a libs/v8/out/native/obj.target/tools/gyp/libv8_libplatform.a libs/v8/out/native/obj.target/tools/gyp/libv8_nosnapshot.a libs/v8/out/native/obj.target/tools/gyp/libv8_snapshot.a libs/v8/out/native/obj.target/third_party/icu/libicudata.a libs/v8/out/native/obj.target/tools/gyp/libv8.so libs/v8/out/native/obj.target/third_party/icu/libicui18n.so libs/v8/out/native/obj.target/third_party/icu/libicuuc.so libs/libuv/out/Debug/obj.target/libuv.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/tools/gyp/libv8_base.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/tools/gyp/libv8_libbase.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/tools/gyp/libv8_libplatform.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/tools/gyp/libv8_nosnapshot.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/tools/gyp/libv8_snapshot.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/third_party/icu/libicudata.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/tools/gyp/libv8.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/third_party/icu/libicui18n.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/v8/out/native/obj.target/third_party/icu/libicuuc.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: libs/libuv/out/Debug/obj.target/libuv.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	clang++-3.5 -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -s -Ilibs/v8 -Ilibs/libuv -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/net/Client.o: src/net/Client.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/net
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -s -Ilibs/v8 -Ilibs/libuv -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/net/Client.o src/net/Client.cpp

${OBJECTDIR}/src/net/TCPServer.o: src/net/TCPServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/net
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -s -Ilibs/v8 -Ilibs/libuv -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/net/TCPServer.o src/net/TCPServer.cpp

${OBJECTDIR}/src/script/Entry.o: src/script/Entry.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/script
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -s -Ilibs/v8 -Ilibs/libuv -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/script/Entry.o src/script/Entry.cpp

${OBJECTDIR}/src/util/Exception.o: src/util/Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -s -Ilibs/v8 -Ilibs/libuv -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/util/Exception.o src/util/Exception.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
