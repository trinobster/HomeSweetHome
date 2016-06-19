################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera.cpp \
../Map.cpp \
../Pine.cpp \
../Polygon.cpp \
../Snowman.cpp \
../Utility.cpp \
../main.cpp 

OBJS += \
./Camera.o \
./Map.o \
./Pine.o \
./Polygon.o \
./Snowman.o \
./Utility.o \
./main.o 

CPP_DEPS += \
./Camera.d \
./Map.d \
./Pine.d \
./Polygon.d \
./Snowman.d \
./Utility.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/panda3d -I/usr/include/python2.7 -I/usr/local/include/bullet -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


