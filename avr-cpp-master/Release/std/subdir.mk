################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../std/algorithm.cpp \
../std/associative_base.cpp \
../std/bitset.cpp \
../std/char_traits.cpp \
../std/complex.cpp \
../std/del_op.cpp \
../std/del_opnt.cpp \
../std/del_opv.cpp \
../std/del_opvnt.cpp \
../std/deque.cpp \
../std/eh_alloc.cpp \
../std/eh_globals.cpp \
../std/exception.cpp \
../std/fstream.cpp \
../std/func_exception.cpp \
../std/iomanip.cpp \
../std/ios.cpp \
../std/iostream.cpp \
../std/istream.cpp \
../std/iterator.cpp \
../std/limits.cpp \
../std/list.cpp \
../std/locale.cpp \
../std/map.cpp \
../std/new_handler.cpp \
../std/new_op.cpp \
../std/new_opnt.cpp \
../std/new_opv.cpp \
../std/new_opvnt.cpp \
../std/numeric.cpp \
../std/ostream.cpp \
../std/queue.cpp \
../std/set.cpp \
../std/sstream.cpp \
../std/stack.cpp \
../std/stdexcept.cpp \
../std/streambuf.cpp \
../std/string.cpp \
../std/support.cpp \
../std/typeinfo.cpp \
../std/utility.cpp \
../std/valarray.cpp \
../std/vector.cpp 

OBJS += \
./std/algorithm.o \
./std/associative_base.o \
./std/bitset.o \
./std/char_traits.o \
./std/complex.o \
./std/del_op.o \
./std/del_opnt.o \
./std/del_opv.o \
./std/del_opvnt.o \
./std/deque.o \
./std/eh_alloc.o \
./std/eh_globals.o \
./std/exception.o \
./std/fstream.o \
./std/func_exception.o \
./std/iomanip.o \
./std/ios.o \
./std/iostream.o \
./std/istream.o \
./std/iterator.o \
./std/limits.o \
./std/list.o \
./std/locale.o \
./std/map.o \
./std/new_handler.o \
./std/new_op.o \
./std/new_opnt.o \
./std/new_opv.o \
./std/new_opvnt.o \
./std/numeric.o \
./std/ostream.o \
./std/queue.o \
./std/set.o \
./std/sstream.o \
./std/stack.o \
./std/stdexcept.o \
./std/streambuf.o \
./std/string.o \
./std/support.o \
./std/typeinfo.o \
./std/utility.o \
./std/valarray.o \
./std/vector.o 

CPP_DEPS += \
./std/algorithm.d \
./std/associative_base.d \
./std/bitset.d \
./std/char_traits.d \
./std/complex.d \
./std/del_op.d \
./std/del_opnt.d \
./std/del_opv.d \
./std/del_opvnt.d \
./std/deque.d \
./std/eh_alloc.d \
./std/eh_globals.d \
./std/exception.d \
./std/fstream.d \
./std/func_exception.d \
./std/iomanip.d \
./std/ios.d \
./std/iostream.d \
./std/istream.d \
./std/iterator.d \
./std/limits.d \
./std/list.d \
./std/locale.d \
./std/map.d \
./std/new_handler.d \
./std/new_op.d \
./std/new_opnt.d \
./std/new_opv.d \
./std/new_opvnt.d \
./std/numeric.d \
./std/ostream.d \
./std/queue.d \
./std/set.d \
./std/sstream.d \
./std/stack.d \
./std/stdexcept.d \
./std/streambuf.d \
./std/string.d \
./std/support.d \
./std/typeinfo.d \
./std/utility.d \
./std/valarray.d \
./std/vector.d 


# Each subdirectory must supply rules for building sources it contributes
std/%.o: ../std/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Dokumente und Einstellungen\Daniel\workspace\cpp002\std" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=at90can128 -DF_CPU=14745600UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


