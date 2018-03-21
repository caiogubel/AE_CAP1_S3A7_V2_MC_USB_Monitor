################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/driver/r_ioport/r_ioport.c 

OBJS += \
./synergy/ssp/src/driver/r_ioport/r_ioport.o 

C_DEPS += \
./synergy/ssp/src/driver/r_ioport/r_ioport.d 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/driver/r_ioport/%.o: ../synergy/ssp/src/driver/r_ioport/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\Synergy\e2studio_v5.4.0.023_ssp_v1.3.3\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy_cfg\ssp_cfg\bsp" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy_cfg\ssp_cfg\driver" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc\bsp" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc\driver\api" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc\driver\instances" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\src" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\src\synergy_gen" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\r_touch_v2\inc\driver\api" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\r_touch_v2\inc\driver\instances" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy_cfg\ssp_cfg\framework\el" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc\framework\el" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\src\framework\el\tx" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\sf_button_v2\inc\driver\api" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\sf_button_v2\inc\driver\instances" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\r_ctsu_v2\inc\driver\api" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\r_ctsu_v2\inc\driver\instances" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy_cfg\ssp_cfg\framework" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc\framework\api" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\inc\framework\instances" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\ssp\src\framework\el\ux" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\sf_ctsu_comm\inc\framework\api" -I"C:\Projects\AE_CAP1_S3A7_ST_Mini_App_USB_Monitor\synergy\sf_ctsu_comm\inc\framework\instances" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


