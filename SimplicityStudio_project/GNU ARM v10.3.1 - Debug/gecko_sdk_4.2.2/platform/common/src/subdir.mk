################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk/platform/common/src/sl_assert.c \
C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk/platform/common/src/sl_string.c \
C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk/platform/common/src/sli_cmsis_os2_ext_task_register.c 

OBJS += \
./gecko_sdk_4.2.2/platform/common/src/sl_assert.o \
./gecko_sdk_4.2.2/platform/common/src/sl_string.o \
./gecko_sdk_4.2.2/platform/common/src/sli_cmsis_os2_ext_task_register.o 

C_DEPS += \
./gecko_sdk_4.2.2/platform/common/src/sl_assert.d \
./gecko_sdk_4.2.2/platform/common/src/sl_string.d \
./gecko_sdk_4.2.2/platform/common/src/sli_cmsis_os2_ext_task_register.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.2.2/platform/common/src/sl_assert.o: C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk/platform/common/src/sl_assert.c gecko_sdk_4.2.2/platform/common/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023\config" -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023\autogen" -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/cmsis/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/portable/GCC/ARM_CM3" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.2.2/platform/common/src/sl_assert.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.2.2/platform/common/src/sl_string.o: C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk/platform/common/src/sl_string.c gecko_sdk_4.2.2/platform/common/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023\config" -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023\autogen" -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/cmsis/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/portable/GCC/ARM_CM3" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.2.2/platform/common/src/sl_string.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.2.2/platform/common/src/sli_cmsis_os2_ext_task_register.o: C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk/platform/common/src/sli_cmsis_os2_ext_task_register.c gecko_sdk_4.2.2/platform/common/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DconfigNUM_SDK_THREAD_LOCAL_STORAGE_POINTERS=2' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023\config" -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023\autogen" -I"C:\OD\Bobo\uni\S6\PEP\gyak\PEP_FreeRTOS_2023" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/RTOS2/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/cmsis/Include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/include" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//util/third_party/freertos/kernel/portable/GCC/ARM_CM3" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/pboto/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.2.2/platform/common/src/sli_cmsis_os2_ext_task_register.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


