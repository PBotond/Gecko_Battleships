################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.2.3/util/third_party/freertos/kernel/portable/MemMang/subdir.mk
-include gecko_sdk_4.2.3/util/third_party/freertos/kernel/portable/GCC/ARM_CM3/subdir.mk
-include gecko_sdk_4.2.3/util/third_party/freertos/kernel/subdir.mk
-include gecko_sdk_4.2.3/util/third_party/freertos/cmsis/Source/subdir.mk
-include gecko_sdk_4.2.3/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.2.3/platform/service/system/src/subdir.mk
-include gecko_sdk_4.2.3/platform/service/iostream/src/subdir.mk
-include gecko_sdk_4.2.3/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.2.3/platform/emlib/src/subdir.mk
-include gecko_sdk_4.2.3/platform/emdrv/dmadrv/src/subdir.mk
-include gecko_sdk_4.2.3/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.2.3/platform/common/src/subdir.mk
-include gecko_sdk_4.2.3/platform/Device/SiliconLabs/EFM32GG/Source/subdir.mk
-include gecko_sdk_4.2.3/platform/CMSIS/RTOS2/Source/subdir.mk
-include gecko_sdk_4.2.3/hardware/board/src/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := PEP_hf_refork
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: PEP_hf_refork.axf

# Tool invocations
PEP_hf_refork.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "C:\OD\Bobo\uni\S6\PEP\hazi\PEP_hf_refork\autogen\linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="PEP_hf_refork.map" --specs=nano.specs -o PEP_hf_refork.axf -Wl,--start-group "./app.o" "./fuggvenyek.o" "./main.o" "./segmentlcd.o" "./segmentlcd_individual.o" "./szamlalo.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./gecko_sdk_4.2.3/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.2.3/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.2.3/platform/CMSIS/RTOS2/Source/os_systick.o" "./gecko_sdk_4.2.3/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.o" "./gecko_sdk_4.2.3/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.o" "./gecko_sdk_4.2.3/platform/common/src/sl_assert.o" "./gecko_sdk_4.2.3/platform/common/src/sl_string.o" "./gecko_sdk_4.2.3/platform/common/src/sli_cmsis_os2_ext_task_register.o" "./gecko_sdk_4.2.3/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.2.3/platform/emdrv/dmadrv/src/dmactrl.o" "./gecko_sdk_4.2.3/platform/emdrv/dmadrv/src/dmadrv.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_core.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_dma.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_emu.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_lcd.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_msc.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_system.o" "./gecko_sdk_4.2.3/platform/emlib/src/em_usart.o" "./gecko_sdk_4.2.3/platform/service/device_init/src/sl_device_init_emu_s0.o" "./gecko_sdk_4.2.3/platform/service/device_init/src/sl_device_init_hfxo_s0.o" "./gecko_sdk_4.2.3/platform/service/device_init/src/sl_device_init_lfxo_s0.o" "./gecko_sdk_4.2.3/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.2.3/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_4.2.3/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_4.2.3/platform/service/iostream/src/sl_iostream_stdlib_config.o" "./gecko_sdk_4.2.3/platform/service/iostream/src/sl_iostream_uart.o" "./gecko_sdk_4.2.3/platform/service/iostream/src/sl_iostream_usart.o" "./gecko_sdk_4.2.3/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.2.3/platform/service/system/src/sl_system_kernel.o" "./gecko_sdk_4.2.3/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.2.3/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./gecko_sdk_4.2.3/util/third_party/freertos/cmsis/Source/cmsis_os2.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/croutine.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/event_groups.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/list.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/queue.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/stream_buffer.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/tasks.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/timers.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/portable/GCC/ARM_CM3/port.o" "./gecko_sdk_4.2.3/util/third_party/freertos/kernel/portable/MemMang/heap_2.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: PEP_hf_refork.hex'
	arm-none-eabi-objcopy -O ihex "PEP_hf_refork.axf" "PEP_hf_refork.hex"
	@echo ' '

	@echo 'Building bin file: PEP_hf_refork.bin'
	arm-none-eabi-objcopy -O binary "PEP_hf_refork.axf" "PEP_hf_refork.bin"
	@echo ' '

	@echo 'Building s37 file: PEP_hf_refork.s37'
	arm-none-eabi-objcopy -O srec "PEP_hf_refork.axf" "PEP_hf_refork.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "PEP_hf_refork.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) PEP_hf_refork.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
