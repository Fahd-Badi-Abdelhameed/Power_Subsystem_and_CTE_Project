################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Power_Subsystem_and_CTE_Project.lss \

FLASH_IMAGE += \
Power_Subsystem_and_CTE_Project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Power_Subsystem_and_CTE_Project.elf secondary-outputs

# Tool invocations
Power_Subsystem_and_CTE_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Power_Subsystem_and_CTE_Project.map -mmcu=atmega32 -o "Power_Subsystem_and_CTE_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Power_Subsystem_and_CTE_Project.lss: Power_Subsystem_and_CTE_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Power_Subsystem_and_CTE_Project.elf  >"Power_Subsystem_and_CTE_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

Power_Subsystem_and_CTE_Project.hex: Power_Subsystem_and_CTE_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Power_Subsystem_and_CTE_Project.elf  "Power_Subsystem_and_CTE_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Power_Subsystem_and_CTE_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Power_Subsystem_and_CTE_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Power_Subsystem_and_CTE_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
