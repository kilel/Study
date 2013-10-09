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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BigInt.o \
	${OBJECTDIR}/BigIntOperators.o \
	${OBJECTDIR}/EncodedMessage.o \
	${OBJECTDIR}/Message.o \
	${OBJECTDIR}/RSAKey.o \
	${OBJECTDIR}/RSAKeyFactory.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=`cppunit-config --cflags` 

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -lInfoSec_lab2_Hash

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rsa

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rsa: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rsa ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BigInt.o: BigInt.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -I../InfoSec_lab2_Hash -I../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/BigInt.o BigInt.cpp

${OBJECTDIR}/BigIntOperators.o: BigIntOperators.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -I../InfoSec_lab2_Hash -I../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/BigIntOperators.o BigIntOperators.cpp

${OBJECTDIR}/EncodedMessage.o: EncodedMessage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -I../InfoSec_lab2_Hash -I../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/EncodedMessage.o EncodedMessage.cpp

${OBJECTDIR}/Message.o: Message.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -I../InfoSec_lab2_Hash -I../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Message.o Message.cpp

${OBJECTDIR}/RSAKey.o: RSAKey.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -I../InfoSec_lab2_Hash -I../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/RSAKey.o RSAKey.cpp

${OBJECTDIR}/RSAKeyFactory.o: RSAKeyFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -I../InfoSec_lab2_Hash -I../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/RSAKeyFactory.o RSAKeyFactory.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -I../InfoSec_lab2_Hash -I../InfoSec_lab2_Hash/dist/Lib/GNU-Linux-x86 -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rsa

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
