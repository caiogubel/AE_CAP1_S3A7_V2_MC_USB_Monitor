/* generated common header file - do not edit */
#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "r_ctsu.h"
/* Include the headers for the CTSU API */
#include "r_ctsu_api.h"

/* Include the headers for the TOUCH API */
#include "r_touch.h"
/* Include the headers for the TOUCH API */
#include "r_touch_api.h"
#include "sf_ctsu_comm_cfg.h"
#include "sf_ctsu_comm.h"
#if (SF_CTSU_COMM_CFG_CONNECTION==2)
#include "r_uart_api.h"
#elif (SF_CTSU_COMM_CFG_CONNECTION==1)
#include "sf_comms_api.h"
#endif
#include "sf_touch_button.h"
#include "r_fmi.h"
#include "r_fmi_api.h"
#include "r_cgc.h"
#include "r_cgc_api.h"
#include "r_ioport.h"
#include "r_ioport_api.h"
#include "r_elc.h"
#include "r_elc_api.h"
#ifdef __cplusplus
extern "C"
{
#endif

#include "ux_api.h"

/* USBX Host Stack initialization error callback function. User can override the function if needed. */
void ux_v2_err_callback(void * p_instance, void * p_data);

#if !defined(NULL)
/* User Callback for Host Event Notification (Only valid for USB Host). */
extern UINT NULL(ULONG event, UX_HOST_CLASS * host_class, VOID * instance);
#endif

#ifdef UX_HOST_CLASS_STORAGE_H
/* Utility function to get the pointer to a FileX Media Control Block for a USB Mass Storage device. */
UINT ux_system_host_storage_fx_media_get(UX_HOST_CLASS_STORAGE * instance, UX_HOST_CLASS_STORAGE_MEDIA ** p_storage_media, FX_MEDIA ** p_fx_media);
#endif
void ux_common_init0(void);
#include "ux_api.h"
#include "ux_dcd_synergy.h"
#include "sf_el_ux_dcd_fs_cfg.h"
void g_sf_el_ux_dcd_fs_0_err_callback(void * p_instance, void * p_data);
#include "ux_api.h"
#include "ux_dcd_synergy.h"

/* USBX Device Stack initialization error callback function. User can override the function if needed. */
void ux_device_err_callback(void * p_instance, void * p_data);
void ux_device_init0(void);
/* Header section starts for g_ux_device_class_cdc_acm0 */
#include "ux_api.h"
#include "ux_device_class_cdc_acm.h"
/* USBX CDC-ACM Instance Activate User Callback Function */
extern VOID ux_cdc_device0_instance_activate(VOID * cdc_instance);
/* USBX CDC-ACM Instance Deactivate User Callback Function */
extern VOID ux_cdc_device0_instance_deactivate(VOID * cdc_instance);
/* Header section ends for g_ux_device_class_cdc_acm0 */
void ux_device_class_cdc_acm_init0(void);
/* Include the generated headers (when using Tuned data provided by Workbench6) */
#define DATA_SOURCE_WORKBENCH	(0)
#define DATA_SOURCE_SSPCONFIG	(1)

#define DATA_SOURCE 			(1)

#if (DATA_SOURCE == DATA_SOURCE_SSPCONFIG)
#define TS_MODE_UNUSED          (0)
#define TS_MODE_RECEIVE         (1)
#define TS_MODE_TRANSMIT        (2)

#define CTSU_CFG_MODE_SELF     (0)
#define CTSU_CFG_MODE_MUTUAL   (1)
#define CTSU_CFG_MODE_MUTUAL0  (CTSU_CFG_MODE_MUTUAL)
#define CTSU_CFG_MODE_MUTUAL1  (CTSU_CFG_MODE_MUTUAL)
#define CTSU_CFG_MODE_MUTUAL2  (CTSU_CFG_MODE_MUTUAL)
#define CTSU_CFG_MODE_MUTUAL3  (CTSU_CFG_MODE_MUTUAL)
#define CTSU_CFG_MODE_MUTUAL4  (CTSU_CFG_MODE_MUTUAL)
#define CTSU_CFG_MODE_MUTUAL5  (CTSU_CFG_MODE_MUTUAL)
#define CTSU_CFG_MODE_MUTUAL6  (CTSU_CFG_MODE_MUTUAL)
#define CTSU_CFG_MODE_MUTUAL7  (CTSU_CFG_MODE_MUTUAL)

#define CTSU_CFG_MODE    (CTSU_CFG_MODE_MUTUAL0)

#define MUTUAL0_TS0    (TS_MODE_RECEIVE)
#define MUTUAL0_TS1    (TS_MODE_RECEIVE)
#define MUTUAL0_TS2    (TS_MODE_UNUSED)
#define MUTUAL0_TS3    (TS_MODE_UNUSED)
#define MUTUAL0_TS4    (TS_MODE_UNUSED)
#define MUTUAL0_TS5    (TS_MODE_UNUSED)
#define MUTUAL0_TS6    (TS_MODE_UNUSED)
#define MUTUAL0_TS7    (TS_MODE_UNUSED)
#define MUTUAL0_TS8    (TS_MODE_UNUSED)
#define MUTUAL0_TS9    (TS_MODE_UNUSED)
#define MUTUAL0_TS10    (TS_MODE_UNUSED)
#define MUTUAL0_TS11    (TS_MODE_UNUSED)
#define MUTUAL0_TS12    (TS_MODE_UNUSED)
#define MUTUAL0_TS13    (TS_MODE_UNUSED)
#define MUTUAL0_TS14    (TS_MODE_UNUSED)
#define MUTUAL0_TS15    (TS_MODE_UNUSED)
#define MUTUAL0_TS16    (TS_MODE_UNUSED)
#define MUTUAL0_TS17    (TS_MODE_UNUSED)
#define MUTUAL0_TS18    (TS_MODE_TRANSMIT)
#define MUTUAL0_TS19    (TS_MODE_TRANSMIT)
#define MUTUAL0_TS20    (TS_MODE_UNUSED)
#define MUTUAL0_TS21    (TS_MODE_UNUSED)
#define MUTUAL0_TS22    (TS_MODE_UNUSED)
#define MUTUAL0_TS23    (TS_MODE_UNUSED)
#define MUTUAL0_TS24    (TS_MODE_UNUSED)
#define MUTUAL0_TS25    (TS_MODE_UNUSED)
#define MUTUAL0_TS26    (TS_MODE_UNUSED)
#define MUTUAL0_TS27    (TS_MODE_UNUSED)
#define MUTUAL0_TS28    (TS_MODE_UNUSED)
#define MUTUAL0_TS29    (TS_MODE_UNUSED)
#define MUTUAL0_TS30    (TS_MODE_UNUSED)
#define MUTUAL0_TS31    (TS_MODE_UNUSED)
#define MUTUAL0_TS32    (TS_MODE_UNUSED)
#define MUTUAL0_TS33    (TS_MODE_UNUSED)
#define MUTUAL0_TS34    (TS_MODE_UNUSED)
#define MUTUAL0_TS35    (TS_MODE_UNUSED)

#if (MUTUAL0_TS0==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS0                 (1)
#define TR_MUTUAL0_TS0                 (0)
#elif (MUTUAL0_TS0==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS0                 (1)
#define TR_MUTUAL0_TS0                 (1)
#else
#define EN_MUTUAL0_TS0                 (0)
#define TR_MUTUAL0_TS0                 (0)
#endif

#if (MUTUAL0_TS1==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS1                 (1)
#define TR_MUTUAL0_TS1                 (0)
#elif (MUTUAL0_TS1==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS1                 (1)
#define TR_MUTUAL0_TS1                 (1)
#else
#define EN_MUTUAL0_TS1                 (0)
#define TR_MUTUAL0_TS1                 (0)
#endif

#if (MUTUAL0_TS2==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS2                 (1)
#define TR_MUTUAL0_TS2                 (0)
#elif (MUTUAL0_TS2==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS2                 (1)
#define TR_MUTUAL0_TS2                 (1)
#else
#define EN_MUTUAL0_TS2                 (0)
#define TR_MUTUAL0_TS2                 (0)
#endif

#if (MUTUAL0_TS3==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS3                 (1)
#define TR_MUTUAL0_TS3                 (0)
#elif (MUTUAL0_TS3==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS3                 (1)
#define TR_MUTUAL0_TS3                 (1)
#else
#define EN_MUTUAL0_TS3                 (0)
#define TR_MUTUAL0_TS3                 (0)
#endif

#if (MUTUAL0_TS4==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS4                 (1)
#define TR_MUTUAL0_TS4                 (0)
#elif (MUTUAL0_TS4==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS4                 (1)
#define TR_MUTUAL0_TS4                 (1)
#else
#define EN_MUTUAL0_TS4                 (0)
#define TR_MUTUAL0_TS4                 (0)
#endif

#if (MUTUAL0_TS5==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS5                 (1)
#define TR_MUTUAL0_TS5                 (0)
#elif (MUTUAL0_TS5==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS5                 (1)
#define TR_MUTUAL0_TS5                 (1)
#else
#define EN_MUTUAL0_TS5                 (0)
#define TR_MUTUAL0_TS5                 (0)
#endif

#if (MUTUAL0_TS6==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS6                 (1)
#define TR_MUTUAL0_TS6                 (0)
#elif (MUTUAL0_TS6==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS6                 (1)
#define TR_MUTUAL0_TS6                 (1)
#else
#define EN_MUTUAL0_TS6                 (0)
#define TR_MUTUAL0_TS6                 (0)
#endif

#if (MUTUAL0_TS7==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS7                 (1)
#define TR_MUTUAL0_TS7                 (0)
#elif (MUTUAL0_TS7==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS7                 (1)
#define TR_MUTUAL0_TS7                 (1)
#else
#define EN_MUTUAL0_TS7                 (0)
#define TR_MUTUAL0_TS7                 (0)
#endif

#if (MUTUAL0_TS8==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS8                 (1)
#define TR_MUTUAL0_TS8                 (0)
#elif (MUTUAL0_TS8==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS8                 (1)
#define TR_MUTUAL0_TS8                 (1)
#else
#define EN_MUTUAL0_TS8                 (0)
#define TR_MUTUAL0_TS8                 (0)
#endif

#if (MUTUAL0_TS9==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS9                 (1)
#define TR_MUTUAL0_TS9                 (0)
#elif (MUTUAL0_TS9==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS9                 (1)
#define TR_MUTUAL0_TS9                 (1)
#else
#define EN_MUTUAL0_TS9                 (0)
#define TR_MUTUAL0_TS9                 (0)
#endif

#if (MUTUAL0_TS10==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS10                 (1)
#define TR_MUTUAL0_TS10                 (0)
#elif (MUTUAL0_TS10==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS10                 (1)
#define TR_MUTUAL0_TS10                 (1)
#else
#define EN_MUTUAL0_TS10                 (0)
#define TR_MUTUAL0_TS10                 (0)
#endif

#if (MUTUAL0_TS11==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS11                 (1)
#define TR_MUTUAL0_TS11                 (0)
#elif (MUTUAL0_TS11==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS11                 (1)
#define TR_MUTUAL0_TS11                 (1)
#else
#define EN_MUTUAL0_TS11                 (0)
#define TR_MUTUAL0_TS11                 (0)
#endif

#if (MUTUAL0_TS12==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS12                 (1)
#define TR_MUTUAL0_TS12                 (0)
#elif (MUTUAL0_TS12==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS12                 (1)
#define TR_MUTUAL0_TS12                 (1)
#else
#define EN_MUTUAL0_TS12                 (0)
#define TR_MUTUAL0_TS12                 (0)
#endif

#if (MUTUAL0_TS13==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS13                 (1)
#define TR_MUTUAL0_TS13                 (0)
#elif (MUTUAL0_TS13==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS13                 (1)
#define TR_MUTUAL0_TS13                 (1)
#else
#define EN_MUTUAL0_TS13                 (0)
#define TR_MUTUAL0_TS13                 (0)
#endif

#if (MUTUAL0_TS14==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS14                 (1)
#define TR_MUTUAL0_TS14                 (0)
#elif (MUTUAL0_TS14==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS14                 (1)
#define TR_MUTUAL0_TS14                 (1)
#else
#define EN_MUTUAL0_TS14                 (0)
#define TR_MUTUAL0_TS14                 (0)
#endif

#if (MUTUAL0_TS15==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS15                 (1)
#define TR_MUTUAL0_TS15                 (0)
#elif (MUTUAL0_TS15==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS15                 (1)
#define TR_MUTUAL0_TS15                 (1)
#else
#define EN_MUTUAL0_TS15                 (0)
#define TR_MUTUAL0_TS15                 (0)
#endif

#if (MUTUAL0_TS16==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS16                 (1)
#define TR_MUTUAL0_TS16                 (0)
#elif (MUTUAL0_TS16==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS16                 (1)
#define TR_MUTUAL0_TS16                 (1)
#else
#define EN_MUTUAL0_TS16                 (0)
#define TR_MUTUAL0_TS16                 (0)
#endif

#if (MUTUAL0_TS17==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS17                 (1)
#define TR_MUTUAL0_TS17                 (0)
#elif (MUTUAL0_TS17==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS17                 (1)
#define TR_MUTUAL0_TS17                 (1)
#else
#define EN_MUTUAL0_TS17                 (0)
#define TR_MUTUAL0_TS17                 (0)
#endif

#if (MUTUAL0_TS18==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS18                 (1)
#define TR_MUTUAL0_TS18                 (0)
#elif (MUTUAL0_TS18==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS18                 (1)
#define TR_MUTUAL0_TS18                 (1)
#else
#define EN_MUTUAL0_TS18                 (0)
#define TR_MUTUAL0_TS18                 (0)
#endif

#if (MUTUAL0_TS19==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS19                 (1)
#define TR_MUTUAL0_TS19                 (0)
#elif (MUTUAL0_TS19==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS19                 (1)
#define TR_MUTUAL0_TS19                 (1)
#else
#define EN_MUTUAL0_TS19                 (0)
#define TR_MUTUAL0_TS19                 (0)
#endif

#if (MUTUAL0_TS20==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS20                 (1)
#define TR_MUTUAL0_TS20                 (0)
#elif (MUTUAL0_TS20==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS20                 (1)
#define TR_MUTUAL0_TS20                 (1)
#else
#define EN_MUTUAL0_TS20                 (0)
#define TR_MUTUAL0_TS20                 (0)
#endif

#if (MUTUAL0_TS21==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS21                 (1)
#define TR_MUTUAL0_TS21                 (0)
#elif (MUTUAL0_TS21==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS21                 (1)
#define TR_MUTUAL0_TS21                 (1)
#else
#define EN_MUTUAL0_TS21                 (0)
#define TR_MUTUAL0_TS21                 (0)
#endif

#if (MUTUAL0_TS22==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS22                 (1)
#define TR_MUTUAL0_TS22                 (0)
#elif (MUTUAL0_TS22==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS22                 (1)
#define TR_MUTUAL0_TS22                 (1)
#else
#define EN_MUTUAL0_TS22                 (0)
#define TR_MUTUAL0_TS22                 (0)
#endif

#if (MUTUAL0_TS23==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS23                 (1)
#define TR_MUTUAL0_TS23                 (0)
#elif (MUTUAL0_TS23==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS23                 (1)
#define TR_MUTUAL0_TS23                 (1)
#else
#define EN_MUTUAL0_TS23                 (0)
#define TR_MUTUAL0_TS23                 (0)
#endif

#if (MUTUAL0_TS24==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS24                 (1)
#define TR_MUTUAL0_TS24                 (0)
#elif (MUTUAL0_TS24==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS24                 (1)
#define TR_MUTUAL0_TS24                 (1)
#else
#define EN_MUTUAL0_TS24                 (0)
#define TR_MUTUAL0_TS24                 (0)
#endif

#if (MUTUAL0_TS25==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS25                 (1)
#define TR_MUTUAL0_TS25                 (0)
#elif (MUTUAL0_TS25==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS25                 (1)
#define TR_MUTUAL0_TS25                 (1)
#else
#define EN_MUTUAL0_TS25                 (0)
#define TR_MUTUAL0_TS25                 (0)
#endif

#if (MUTUAL0_TS26==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS26                 (1)
#define TR_MUTUAL0_TS26                 (0)
#elif (MUTUAL0_TS26==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS26                 (1)
#define TR_MUTUAL0_TS26                 (1)
#else
#define EN_MUTUAL0_TS26                 (0)
#define TR_MUTUAL0_TS26                 (0)
#endif

#if (MUTUAL0_TS27==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS27                 (1)
#define TR_MUTUAL0_TS27                 (0)
#elif (MUTUAL0_TS27==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS27                 (1)
#define TR_MUTUAL0_TS27                 (1)
#else
#define EN_MUTUAL0_TS27                 (0)
#define TR_MUTUAL0_TS27                 (0)
#endif

#if (MUTUAL0_TS28==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS28                 (1)
#define TR_MUTUAL0_TS28                 (0)
#elif (MUTUAL0_TS28==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS28                 (1)
#define TR_MUTUAL0_TS28                 (1)
#else
#define EN_MUTUAL0_TS28                 (0)
#define TR_MUTUAL0_TS28                 (0)
#endif

#if (MUTUAL0_TS29==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS29                 (1)
#define TR_MUTUAL0_TS29                 (0)
#elif (MUTUAL0_TS29==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS29                 (1)
#define TR_MUTUAL0_TS29                 (1)
#else
#define EN_MUTUAL0_TS29                 (0)
#define TR_MUTUAL0_TS29                 (0)
#endif

#if (MUTUAL0_TS30==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS30                 (1)
#define TR_MUTUAL0_TS30                 (0)
#elif (MUTUAL0_TS30==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS30                 (1)
#define TR_MUTUAL0_TS30                 (1)
#else
#define EN_MUTUAL0_TS30                 (0)
#define TR_MUTUAL0_TS30                 (0)
#endif

#if (MUTUAL0_TS31==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS31                 (1)
#define TR_MUTUAL0_TS31                 (0)
#elif (MUTUAL0_TS31==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS31                 (1)
#define TR_MUTUAL0_TS31                 (1)
#else
#define EN_MUTUAL0_TS31                 (0)
#define TR_MUTUAL0_TS31                 (0)
#endif

#if (MUTUAL0_TS32==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS32                 (1)
#define TR_MUTUAL0_TS32                 (0)
#elif (MUTUAL0_TS32==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS32                 (1)
#define TR_MUTUAL0_TS32                 (1)
#else
#define EN_MUTUAL0_TS32                 (0)
#define TR_MUTUAL0_TS32                 (0)
#endif

#if (MUTUAL0_TS33==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS33                 (1)
#define TR_MUTUAL0_TS33                 (0)
#elif (MUTUAL0_TS33==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS33                 (1)
#define TR_MUTUAL0_TS33                 (1)
#else
#define EN_MUTUAL0_TS33                 (0)
#define TR_MUTUAL0_TS33                 (0)
#endif

#if (MUTUAL0_TS34==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS34                 (1)
#define TR_MUTUAL0_TS34                 (0)
#elif (MUTUAL0_TS34==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS34                 (1)
#define TR_MUTUAL0_TS34                 (1)
#else
#define EN_MUTUAL0_TS34                 (0)
#define TR_MUTUAL0_TS34                 (0)
#endif

#if (MUTUAL0_TS35==TS_MODE_RECEIVE)
#define EN_MUTUAL0_TS35                 (1)
#define TR_MUTUAL0_TS35                 (0)
#elif (MUTUAL0_TS35==TS_MODE_TRANSMIT)
#define EN_MUTUAL0_TS35                 (1)
#define TR_MUTUAL0_TS35                 (1)
#else
#define EN_MUTUAL0_TS35                 (0)
#define TR_MUTUAL0_TS35                 (0)
#endif

/*****    CTSUCHAC - CTSU Channel Enable Control Register    **********************************************************/
#define CTSUCHAC0_MUTUAL0_ENABLE_TS  ((EN_MUTUAL0_TS7<<7)|(EN_MUTUAL0_TS6<<6)|(EN_MUTUAL0_TS5<<5)|(EN_MUTUAL0_TS4<<4)|(EN_MUTUAL0_TS3<<3)|(EN_MUTUAL0_TS2<<2)|(EN_MUTUAL0_TS1<<1)|(EN_MUTUAL0_TS0<<0))
#define CTSUCHAC1_MUTUAL0_ENABLE_TS  ((EN_MUTUAL0_TS15<<7)|(EN_MUTUAL0_TS14<<6)|(EN_MUTUAL0_TS13<<5)|(EN_MUTUAL0_TS12<<4)|(EN_MUTUAL0_TS11<<3)|(EN_MUTUAL0_TS10<<2)|(EN_MUTUAL0_TS9<<1)|(EN_MUTUAL0_TS8<<0))
#define CTSUCHAC2_MUTUAL0_ENABLE_TS  ((EN_MUTUAL0_TS23<<7)|(EN_MUTUAL0_TS22<<6)|(EN_MUTUAL0_TS21<<5)|(EN_MUTUAL0_TS20<<4)|(EN_MUTUAL0_TS19<<3)|(EN_MUTUAL0_TS18<<2)|(EN_MUTUAL0_TS17<<1)|(EN_MUTUAL0_TS16<<0))
#define CTSUCHAC3_MUTUAL0_ENABLE_TS  ((EN_MUTUAL0_TS31<<7)|(EN_MUTUAL0_TS30<<6)|(EN_MUTUAL0_TS29<<5)|(EN_MUTUAL0_TS28<<4)|(EN_MUTUAL0_TS27<<3)|(EN_MUTUAL0_TS26<<2)|(EN_MUTUAL0_TS25<<1)|(EN_MUTUAL0_TS24<<0))
#define CTSUCHAC4_MUTUAL0_ENABLE_TS  ((EN_MUTUAL0_TS35<<3)|(EN_MUTUAL0_TS34<<2)|(EN_MUTUAL0_TS33<<1)|(EN_MUTUAL0_TS32<<0))

/*****    CTSUCHAC - CTSU Channel Transmit/Receive Control Register    ************************************************/
#define CTSUCHTRC0_MUTUAL0_TRANSMIT_TS   ((TR_MUTUAL0_TS7<<7)|(TR_MUTUAL0_TS6<<6)|(TR_MUTUAL0_TS5<<5)|(TR_MUTUAL0_TS4<<4)|(TR_MUTUAL0_TS3<<3)|(TR_MUTUAL0_TS2<<2)|(TR_MUTUAL0_TS1<<1)|(TR_MUTUAL0_TS0<<0))
#define CTSUCHTRC1_MUTUAL0_TRANSMIT_TS   ((TR_MUTUAL0_TS15<<7)|(TR_MUTUAL0_TS14<<6)|(TR_MUTUAL0_TS13<<5)|(TR_MUTUAL0_TS12<<4)|(TR_MUTUAL0_TS11<<3)|(TR_MUTUAL0_TS10<<2)|(TR_MUTUAL0_TS9<<1)|(TR_MUTUAL0_TS8<<0))
#define CTSUCHTRC2_MUTUAL0_TRANSMIT_TS   ((TR_MUTUAL0_TS23<<7)|(TR_MUTUAL0_TS22<<6)|(TR_MUTUAL0_TS21<<5)|(TR_MUTUAL0_TS20<<4)|(TR_MUTUAL0_TS19<<3)|(TR_MUTUAL0_TS18<<2)|(TR_MUTUAL0_TS17<<1)|(TR_MUTUAL0_TS16<<0))
#define CTSUCHTRC3_MUTUAL0_TRANSMIT_TS   ((TR_MUTUAL0_TS31<<7)|(TR_MUTUAL0_TS30<<6)|(TR_MUTUAL0_TS29<<5)|(TR_MUTUAL0_TS28<<4)|(TR_MUTUAL0_TS27<<3)|(TR_MUTUAL0_TS26<<2)|(TR_MUTUAL0_TS25<<1)|(TR_MUTUAL0_TS24<<0))
#define CTSUCHTRC4_MUTUAL0_TRANSMIT_TS   ((TR_MUTUAL0_TS35<<3)|(TR_MUTUAL0_TS34<<2)|(TR_MUTUAL0_TS33<<1)|(TR_MUTUAL0_TS32<<0))

/*****    CTSUCR0 - CTSU control register 0    ************************************************************************/
#define MUTUAL0_CTSUTXVSEL               (0)/* (SYNERGY_NOT_DEFINED) */

/*****    CTSUCR1 - CTSU channel register 1    ************************************************************************/
#define MUTUAL0_PCLK                     (0)

/*****    CTSUSDPRS - CTSU Sensor drive pulse spectrum diffusion set register    **************************************/
#define MUTUAL0_CTSUPRRATIO              (3)

#define MUTUAL0_CTSUPRMODE               (2)

#define MUTUAL0_CTSUSOFF                 (0)

/*****    CTSU Channel Verification    *******************************************************************************/
#define MUTUAL0_ENABLE_NUM               (EN_MUTUAL0_TS0 + EN_MUTUAL0_TS1 + EN_MUTUAL0_TS2 + EN_MUTUAL0_TS3 + \
                                                                     EN_MUTUAL0_TS4 + EN_MUTUAL0_TS5 + EN_MUTUAL0_TS6 + EN_MUTUAL0_TS7 + \
                                                                     EN_MUTUAL0_TS8 + EN_MUTUAL0_TS9 + EN_MUTUAL0_TS10 + EN_MUTUAL0_TS11 + \
                                                                     EN_MUTUAL0_TS12 + EN_MUTUAL0_TS13 + EN_MUTUAL0_TS14 + EN_MUTUAL0_TS15 + \
                                                                     EN_MUTUAL0_TS16 + EN_MUTUAL0_TS17 + EN_MUTUAL0_TS18 + EN_MUTUAL0_TS19 + \
                                                                     EN_MUTUAL0_TS20 + EN_MUTUAL0_TS21 + EN_MUTUAL0_TS22 + EN_MUTUAL0_TS23 + \
                                                                     EN_MUTUAL0_TS24 + EN_MUTUAL0_TS25 + EN_MUTUAL0_TS26 + EN_MUTUAL0_TS27 + \
                                                                     EN_MUTUAL0_TS28 + EN_MUTUAL0_TS29 + EN_MUTUAL0_TS30 + EN_MUTUAL0_TS31 + \
                                                                     EN_MUTUAL0_TS32 + EN_MUTUAL0_TS33 + EN_MUTUAL0_TS34 + EN_MUTUAL0_TS35)

#define MUTUAL0_TRANSMIT_NUM             (TR_MUTUAL0_TS0 + TR_MUTUAL0_TS1 + TR_MUTUAL0_TS2 + TR_MUTUAL0_TS3 + \
                                                                     TR_MUTUAL0_TS4 + TR_MUTUAL0_TS5 + TR_MUTUAL0_TS6 + TR_MUTUAL0_TS7 + \
                                                                     TR_MUTUAL0_TS8 + TR_MUTUAL0_TS9 + TR_MUTUAL0_TS10 + TR_MUTUAL0_TS11 + \
                                                                     TR_MUTUAL0_TS12 + TR_MUTUAL0_TS13 + TR_MUTUAL0_TS14 + TR_MUTUAL0_TS15 + \
                                                                     TR_MUTUAL0_TS16 + TR_MUTUAL0_TS17 + TR_MUTUAL0_TS18 + TR_MUTUAL0_TS19 + \
                                                                     TR_MUTUAL0_TS20 + TR_MUTUAL0_TS21 + TR_MUTUAL0_TS22 + TR_MUTUAL0_TS23 + \
                                                                     TR_MUTUAL0_TS24 + TR_MUTUAL0_TS25 + TR_MUTUAL0_TS26 + TR_MUTUAL0_TS27 + \
                                                                     TR_MUTUAL0_TS28 + TR_MUTUAL0_TS29 + TR_MUTUAL0_TS30 + TR_MUTUAL0_TS31 + \
                                                                     TR_MUTUAL0_TS32 + TR_MUTUAL0_TS33 + TR_MUTUAL0_TS34 + TR_MUTUAL0_TS35)

#define MUTUAL0_RECEIVE_NUM              ((MUTUAL0_ENABLE_NUM) - MUTUAL0_TRANSMIT_NUM)

#if !defined(_0_CTSUATUNE0_NORMAL)
#define _0_CTSUATUNE0_NORMAL             (0)        /* Normal operating mode                                          */
#endif

#if !defined(_1_CTSUATUNE0_LOW)
#define _1_CTSUATUNE0_LOW                (1)        /* Low-voltage operating mode                                     */
#endif

#if !defined(SELF_CTSUATUNE0)
#define SELF_CTSUATUNE0                  (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL0_CTSUATUNE0)
#define MUTUAL0_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL1_CTSUATUNE0)
#define MUTUAL1_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL2_CTSUATUNE0)
#define MUTUAL2_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL3_CTSUATUNE0)
#define MUTUAL3_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL4_CTSUATUNE0)
#define MUTUAL4_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL5_CTSUATUNE0)
#define MUTUAL5_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL6_CTSUATUNE0)
#define MUTUAL6_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(MUTUAL7_CTSUATUNE0)
#define MUTUAL7_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#endif

#if !defined(_0_CTSUATUNE1_NORMAL)
#define _0_CTSUATUNE1_NORMAL             (0)        /* Normal output                                                  */
#endif

#if !defined(_1_CTSUATUNE1_HIGH)
#define _1_CTSUATUNE1_HIGH               (1)        /* High-current output                                            */
#endif

#if !defined(SELF_CTSUATUNE1)
#define SELF_CTSUATUNE1                  (_0_CTSUATUNE1_NORMAL)
#endif

#if !defined(MUTUAL0_CTSUATUNE1)
#define MUTUAL0_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

#if !defined(MUTUAL1_CTSUATUNE1)
#define MUTUAL1_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

#if !defined(MUTUAL2_CTSUATUNE1)
#define MUTUAL2_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

#if !defined(MUTUAL3_CTSUATUNE1)
#define MUTUAL3_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

#if !defined(MUTUAL4_CTSUATUNE1)
#define MUTUAL4_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

#if !defined(MUTUAL5_CTSUATUNE1)
#define MUTUAL5_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

#if !defined(MUTUAL6_CTSUATUNE1)
#define MUTUAL6_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

#if !defined(MUTUAL7_CTSUATUNE1)
#define MUTUAL7_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#endif

/*****    Address 000A 0903h CTSU Sensor wait time register    ********************************************************/
#define _00010000_CTSUSST_RECOMMEND      (16)       /* The value of these bits should be fixed to 00010000b           */

/*****    Address 000A 0910h CTSU Channel send and receive control register 0 *****************************************/
#if !defined(_00_CTSUSSMOD)
#define _00_CTSUSSMOD                    (0)        /* These bits should be set to 00b.                               */
#endif

#if !defined(_11_CTSUSSCNT)
#define _11_CTSUSSCNT                    (3)        /* These bits should be set to 11b.                               */
#endif

#if (CTSU_CFG_MODE==CTSU_CFG_MODE_SELF)
#define SENSOR_COUNT    (MUTUAL0_ENABLE_NUM)
#define MULTIPLIER      (1)

#if (MUTUAL0_TRANSMIT_NUM > 0)
#error "Cannot Use TS Pins as Transmission. Check CTSUCHTRCn settings and TS Pin Settings. Atleast one pin in CTSU V2 HAL Driver Pin Mode should be transmit."
#endif

#else
#define SENSOR_COUNT    (MUTUAL0_RECEIVE_NUM * MUTUAL0_TRANSMIT_NUM)
#define MULTIPLIER      (2)
#endif

#if (SENSOR_COUNT==0)
#error "Sensor Count cannot be zero. Check CTSU V2 HAL Driver Pin Modes."
#endif

#if defined(MUTUAL0_NUM)
#undef MUTUAL0_NUM
#endif

#define MUTUAL0_NUM  (SENSOR_COUNT)
#define MUTUAL0_KEY_NUM  (SENSOR_COUNT)

#define MUTUAL0_WR_SIZE  (SENSOR_COUNT*3)
#define MUTUAL0_RD_SIZE  (SENSOR_COUNT*MULTIPLIER*2)

#if (CTSU_CFG_MODE==CTSU_CFG_MODE_SELF)
#define CTSUMD_SFR    (1)
#else
#define CTSUMD_SFR    (3)
#endif
#if !defined(SF_CTSU_TUNING_CFG_H_)
/** Buffer for CTSU sensor measurement output (provided by Workbench6) */
extern uint16_t g_ctsu_data_buffer[MUTUAL0_RD_SIZE];

/** CTSU Settings for each sensor (provided by Workbench6) */
extern ctsu_sensor_setting_t g_ctsu_sensor_settings[MUTUAL0_NUM];
#else
/** Buffer for CTSU sensor measurement output (provided by Workbench6) */
extern uint16_t g_ctsu_data_buffer[];

/** CTSU Settings for each sensor (provided by Workbench6) */
extern ctsu_sensor_setting_t g_ctsu_sensor_settings[];
#endif
/** CTSU configuration */
extern const ctsu_cfg_t g_ctsu0_cfg;

/** CTSU SFRs common to all sensors (in a configuration) */
extern ctsu_const_sfrs_t g_ctsu_common_sfrs;

#ifndef NULL
void NULL(ctsu_callback_arg_t const * const p_arg);
#endif
#endif /* (DATA_SOURCE == DATA_SOURCE_SSPCONFIG) */

extern ctsu_instance_t const g_ctsu0;
#define CTSU_SENSOR_1_TS_RX     (1)
#define CTSU_SENSOR_1_TS_TX     (19)
#define g_ctsu0_INDEX_1     (1)
#define CTSU_SENSOR_1_FREQ      (SYNERGY_NOT_DEFINED)

#define CTSU_SENSOR_1_CTSUSSDIV (0)
#define CTSU_SENSOR_1_CTSUSO    (380)
#define CTSU_SENSOR_1_CTSUSNUM  (7)
#define CTSU_SENSOR_1_CTSURICOA (0x3F)
#define CTSU_SENSOR_1_CTSUSDPA  (2)
#define CTSU_SENSOR_1_CTSUICOG  (1)

#define CTSU_SENSOR_1_CTSUSST   (CTSU_SENSOR_1_CTSUSSDIV << 8)
#define CTSU_SENSOR_1_CTSUSO0   ((CTSU_SENSOR_1_CTSUSNUM << 10)|CTSU_SENSOR_1_CTSUSO)
#define CTSU_SENSOR_1_CTSUSO1   ((CTSU_SENSOR_1_CTSUICOG << 13)|(CTSU_SENSOR_1_CTSUSDPA << 8) |CTSU_SENSOR_1_CTSURICOA)

#define CTSU_SENSOR_1_THRESHOLD     (3390)
#define CTSU_SENSOR_1_HYSTERESIS    (169)
#define CTSU_SENSOR_1_DELAY_2_T     (3)
#define CTSU_SENSOR_1_DELAY_2_R     (3)

#define CTSU_SENSOR_1_DRIFT_RATE    (1000)
#define CTSU_SENSOR_1_RATE_PLUS     (0) /* (SYNERGY_NOT_DEFINED) */
#define CTSU_SENSOR_1_RATE_MINUS    (0) /* (SYNERGY_NOT_DEFINED) */

#define CTSU_SENSOR_1_ADJ_INTERVAL  (1000)
#define CTSU_SENSOR_1_ADJ_THRESHOLD (100)

#define CTSU_SENSOR_1_CTSU_SFRS       {CTSU_SENSOR_1_CTSUSST, CTSU_SENSOR_1_CTSUSO0, CTSU_SENSOR_1_CTSUSO1}
#define g_ctsu0_INDEX_1_CTSU_SFRS    CTSU_SENSOR_1_CTSU_SFRS
#define CTSU_SENSOR_1_TOUCH_PARAMS    {CTSU_SENSOR_1_THRESHOLD,CTSU_SENSOR_1_HYSTERESIS,CTSU_SENSOR_1_DELAY_2_T,CTSU_SENSOR_1_DELAY_2_R,CTSU_SENSOR_1_DRIFT_RATE,CTSU_SENSOR_1_RATE_PLUS,CTSU_SENSOR_1_RATE_MINUS,CTSU_SENSOR_1_ADJ_INTERVAL,CTSU_SENSOR_1_ADJ_THRESHOLD,}
#define g_ctsu0_INDEX_1_TOUCH_PARAMS    CTSU_SENSOR_1_TOUCH_PARAMS

#if !defined(g_ctsu0_RX_1_TX_19)
#define g_ctsu0_RX_1_TX_19   (1)
#else
#error "Combination with TS1 as receive and TS19 as transmit is already in use with a Capacitive Touch Sensor on r_ctsu_v2 which uses g_ctsu0"
#endif

#if (CTSU_SENSOR_1_TS_RX > 35)
#error "Check TS for CTSU_SENSOR_1_TS_RX"
#elif (MUTUAL0_TS1!=1)
#error "Check TS for CTSU_SENSOR_1_TS_RX"
#endif

#if (CTSU_SENSOR_1_TS_TX < 36)
#if (MUTUAL0_TS19!=2)
#error "Check TS for CTSU_SENSOR_1_TS_TX"
#endif
#endif
#define CTSU_SENSOR_3_TS_RX     (1)
#define CTSU_SENSOR_3_TS_TX     (18)
#define g_ctsu0_INDEX_3     (3)
#define CTSU_SENSOR_3_FREQ      (SYNERGY_NOT_DEFINED)

#define CTSU_SENSOR_3_CTSUSSDIV (0)
#define CTSU_SENSOR_3_CTSUSO    (380)
#define CTSU_SENSOR_3_CTSUSNUM  (7)
#define CTSU_SENSOR_3_CTSURICOA (0x3f)
#define CTSU_SENSOR_3_CTSUSDPA  (2)
#define CTSU_SENSOR_3_CTSUICOG  (1)

#define CTSU_SENSOR_3_CTSUSST   (CTSU_SENSOR_3_CTSUSSDIV << 8)
#define CTSU_SENSOR_3_CTSUSO0   ((CTSU_SENSOR_3_CTSUSNUM << 10)|CTSU_SENSOR_3_CTSUSO)
#define CTSU_SENSOR_3_CTSUSO1   ((CTSU_SENSOR_3_CTSUICOG << 13)|(CTSU_SENSOR_3_CTSUSDPA << 8) |CTSU_SENSOR_3_CTSURICOA)

#define CTSU_SENSOR_3_THRESHOLD     (3591)
#define CTSU_SENSOR_3_HYSTERESIS    (179)
#define CTSU_SENSOR_3_DELAY_2_T     (3)
#define CTSU_SENSOR_3_DELAY_2_R     (3)

#define CTSU_SENSOR_3_DRIFT_RATE    (1000)
#define CTSU_SENSOR_3_RATE_PLUS     (0) /* (SYNERGY_NOT_DEFINED) */
#define CTSU_SENSOR_3_RATE_MINUS    (0) /* (SYNERGY_NOT_DEFINED) */

#define CTSU_SENSOR_3_ADJ_INTERVAL  (1000)
#define CTSU_SENSOR_3_ADJ_THRESHOLD (100)

#define CTSU_SENSOR_3_CTSU_SFRS       {CTSU_SENSOR_3_CTSUSST, CTSU_SENSOR_3_CTSUSO0, CTSU_SENSOR_3_CTSUSO1}
#define g_ctsu0_INDEX_3_CTSU_SFRS    CTSU_SENSOR_3_CTSU_SFRS
#define CTSU_SENSOR_3_TOUCH_PARAMS    {CTSU_SENSOR_3_THRESHOLD,CTSU_SENSOR_3_HYSTERESIS,CTSU_SENSOR_3_DELAY_2_T,CTSU_SENSOR_3_DELAY_2_R,CTSU_SENSOR_3_DRIFT_RATE,CTSU_SENSOR_3_RATE_PLUS,CTSU_SENSOR_3_RATE_MINUS,CTSU_SENSOR_3_ADJ_INTERVAL,CTSU_SENSOR_3_ADJ_THRESHOLD,}
#define g_ctsu0_INDEX_3_TOUCH_PARAMS    CTSU_SENSOR_3_TOUCH_PARAMS

#if !defined(g_ctsu0_RX_1_TX_18)
#define g_ctsu0_RX_1_TX_18   (1)
#else
#error "Combination with TS1 as receive and TS18 as transmit is already in use with a Capacitive Touch Sensor on r_ctsu_v2 which uses g_ctsu0"
#endif

#if (CTSU_SENSOR_3_TS_RX > 35)
#error "Check TS for CTSU_SENSOR_3_TS_RX"
#elif (MUTUAL0_TS1!=1)
#error "Check TS for CTSU_SENSOR_3_TS_RX"
#endif

#if (CTSU_SENSOR_3_TS_TX < 36)
#if (MUTUAL0_TS18!=2)
#error "Check TS for CTSU_SENSOR_3_TS_TX"
#endif
#endif
#define CTSU_SENSOR_0_TS_RX     (0)
#define CTSU_SENSOR_0_TS_TX     (19)
#define g_ctsu0_INDEX_0     (0)
#define CTSU_SENSOR_0_FREQ      (SYNERGY_NOT_DEFINED)

#define CTSU_SENSOR_0_CTSUSSDIV (0)
#define CTSU_SENSOR_0_CTSUSO    (380)
#define CTSU_SENSOR_0_CTSUSNUM  (7)
#define CTSU_SENSOR_0_CTSURICOA (0x3F)
#define CTSU_SENSOR_0_CTSUSDPA  (2)
#define CTSU_SENSOR_0_CTSUICOG  (1)

#define CTSU_SENSOR_0_CTSUSST   (CTSU_SENSOR_0_CTSUSSDIV << 8)
#define CTSU_SENSOR_0_CTSUSO0   ((CTSU_SENSOR_0_CTSUSNUM << 10)|CTSU_SENSOR_0_CTSUSO)
#define CTSU_SENSOR_0_CTSUSO1   ((CTSU_SENSOR_0_CTSUICOG << 13)|(CTSU_SENSOR_0_CTSUSDPA << 8) |CTSU_SENSOR_0_CTSURICOA)

#define CTSU_SENSOR_0_THRESHOLD     (3283)
#define CTSU_SENSOR_0_HYSTERESIS    (164)
#define CTSU_SENSOR_0_DELAY_2_T     (3)
#define CTSU_SENSOR_0_DELAY_2_R     (3)

#define CTSU_SENSOR_0_DRIFT_RATE    (1000)
#define CTSU_SENSOR_0_RATE_PLUS     (0) /* (SYNERGY_NOT_DEFINED) */
#define CTSU_SENSOR_0_RATE_MINUS    (0) /* (SYNERGY_NOT_DEFINED) */

#define CTSU_SENSOR_0_ADJ_INTERVAL  (1000)
#define CTSU_SENSOR_0_ADJ_THRESHOLD (100)

#define CTSU_SENSOR_0_CTSU_SFRS       {CTSU_SENSOR_0_CTSUSST, CTSU_SENSOR_0_CTSUSO0, CTSU_SENSOR_0_CTSUSO1}
#define g_ctsu0_INDEX_0_CTSU_SFRS    CTSU_SENSOR_0_CTSU_SFRS
#define CTSU_SENSOR_0_TOUCH_PARAMS    {CTSU_SENSOR_0_THRESHOLD,CTSU_SENSOR_0_HYSTERESIS,CTSU_SENSOR_0_DELAY_2_T,CTSU_SENSOR_0_DELAY_2_R,CTSU_SENSOR_0_DRIFT_RATE,CTSU_SENSOR_0_RATE_PLUS,CTSU_SENSOR_0_RATE_MINUS,CTSU_SENSOR_0_ADJ_INTERVAL,CTSU_SENSOR_0_ADJ_THRESHOLD,}
#define g_ctsu0_INDEX_0_TOUCH_PARAMS    CTSU_SENSOR_0_TOUCH_PARAMS

#if !defined(g_ctsu0_RX_0_TX_19)
#define g_ctsu0_RX_0_TX_19   (1)
#else
#error "Combination with TS0 as receive and TS19 as transmit is already in use with a Capacitive Touch Sensor on r_ctsu_v2 which uses g_ctsu0"
#endif

#if (CTSU_SENSOR_0_TS_RX > 35)
#error "Check TS for CTSU_SENSOR_0_TS_RX"
#elif (MUTUAL0_TS0!=1)
#error "Check TS for CTSU_SENSOR_0_TS_RX"
#endif

#if (CTSU_SENSOR_0_TS_TX < 36)
#if (MUTUAL0_TS19!=2)
#error "Check TS for CTSU_SENSOR_0_TS_TX"
#endif
#endif
#define CTSU_SENSOR_2_TS_RX     (0)
#define CTSU_SENSOR_2_TS_TX     (18)
#define g_ctsu0_INDEX_2     (2)
#define CTSU_SENSOR_2_FREQ      (SYNERGY_NOT_DEFINED)

#define CTSU_SENSOR_2_CTSUSSDIV (0)
#define CTSU_SENSOR_2_CTSUSO    (380)
#define CTSU_SENSOR_2_CTSUSNUM  (7)
#define CTSU_SENSOR_2_CTSURICOA (0x3F)
#define CTSU_SENSOR_2_CTSUSDPA  (2)
#define CTSU_SENSOR_2_CTSUICOG  (1)

#define CTSU_SENSOR_2_CTSUSST   (CTSU_SENSOR_2_CTSUSSDIV << 8)
#define CTSU_SENSOR_2_CTSUSO0   ((CTSU_SENSOR_2_CTSUSNUM << 10)|CTSU_SENSOR_2_CTSUSO)
#define CTSU_SENSOR_2_CTSUSO1   ((CTSU_SENSOR_2_CTSUICOG << 13)|(CTSU_SENSOR_2_CTSUSDPA << 8) |CTSU_SENSOR_2_CTSURICOA)

#define CTSU_SENSOR_2_THRESHOLD     (3315)
#define CTSU_SENSOR_2_HYSTERESIS    (165)
#define CTSU_SENSOR_2_DELAY_2_T     (3)
#define CTSU_SENSOR_2_DELAY_2_R     (3)

#define CTSU_SENSOR_2_DRIFT_RATE    (1000)
#define CTSU_SENSOR_2_RATE_PLUS     (0) /* (SYNERGY_NOT_DEFINED) */
#define CTSU_SENSOR_2_RATE_MINUS    (0) /* (SYNERGY_NOT_DEFINED) */

#define CTSU_SENSOR_2_ADJ_INTERVAL  (1000)
#define CTSU_SENSOR_2_ADJ_THRESHOLD (100)

#define CTSU_SENSOR_2_CTSU_SFRS       {CTSU_SENSOR_2_CTSUSST, CTSU_SENSOR_2_CTSUSO0, CTSU_SENSOR_2_CTSUSO1}
#define g_ctsu0_INDEX_2_CTSU_SFRS    CTSU_SENSOR_2_CTSU_SFRS
#define CTSU_SENSOR_2_TOUCH_PARAMS    {CTSU_SENSOR_2_THRESHOLD,CTSU_SENSOR_2_HYSTERESIS,CTSU_SENSOR_2_DELAY_2_T,CTSU_SENSOR_2_DELAY_2_R,CTSU_SENSOR_2_DRIFT_RATE,CTSU_SENSOR_2_RATE_PLUS,CTSU_SENSOR_2_RATE_MINUS,CTSU_SENSOR_2_ADJ_INTERVAL,CTSU_SENSOR_2_ADJ_THRESHOLD,}
#define g_ctsu0_INDEX_2_TOUCH_PARAMS    CTSU_SENSOR_2_TOUCH_PARAMS

#if !defined(g_ctsu0_RX_0_TX_18)
#define g_ctsu0_RX_0_TX_18   (1)
#else
#error "Combination with TS0 as receive and TS18 as transmit is already in use with a Capacitive Touch Sensor on r_ctsu_v2 which uses g_ctsu0"
#endif

#if (CTSU_SENSOR_2_TS_RX > 35)
#error "Check TS for CTSU_SENSOR_2_TS_RX"
#elif (MUTUAL0_TS0!=1)
#error "Check TS for CTSU_SENSOR_2_TS_RX"
#endif

#if (CTSU_SENSOR_2_TS_TX < 36)
#if (MUTUAL0_TS18!=2)
#error "Check TS for CTSU_SENSOR_2_TS_TX"
#endif
#endif
#if (DATA_SOURCE == DATA_SOURCE_SSPCONFIG)
/** CTSU SFRs common to all sensors (in a configuration) */
extern uint64_t g_touch0_on_g_ctsu_binary;

#ifndef NULL
void NULL(touch_callback_arg_t * p_args);
#endif
#endif /* (DATA_SOURCE == DATA_SOURCE_SSPCONFIG) */

extern touch_instance_t const g_touch0_on_g_ctsu;
extern sf_ctsu_comm_instance_t const g_sf_ctsu_comm0;
/** SF Touch Button instance */
extern touch_button_instance_t Button_RX02_on_g_touch0_on_g_ctsu;
#ifndef touch_button_common_callback_defined
#define touch_button_common_callback_defined
/** Declaration of user callback function. This function MUST be defined in the user application.*/
void touch_button_common_callback(touch_button_callback_arg_t * p_args);
#endif
/** SF Touch Button instance */
extern touch_button_instance_t Button_RX01_on_g_touch0_on_g_ctsu;
#ifndef touch_button_common_callback_defined
#define touch_button_common_callback_defined
/** Declaration of user callback function. This function MUST be defined in the user application.*/
void touch_button_common_callback(touch_button_callback_arg_t * p_args);
#endif
/** SF Touch Button instance */
extern touch_button_instance_t Button_RX03_on_g_touch0_on_g_ctsu;
#ifndef touch_button_common_callback_defined
#define touch_button_common_callback_defined
/** Declaration of user callback function. This function MUST be defined in the user application.*/
void touch_button_common_callback(touch_button_callback_arg_t * p_args);
#endif
/** SF Touch Button instance */
extern touch_button_instance_t Button_RX00_on_g_touch0_on_g_ctsu;
#ifndef touch_button_common_callback_defined
#define touch_button_common_callback_defined
/** Declaration of user callback function. This function MUST be defined in the user application.*/
void touch_button_common_callback(touch_button_callback_arg_t * p_args);
#endif
/** FMI on FMI Instance. */
extern const fmi_instance_t g_fmi;
/** CGC Instance */
extern const cgc_instance_t g_cgc;
/** IOPORT Instance */
extern const ioport_instance_t g_ioport;
/** ELC Instance */
extern const elc_instance_t g_elc;
void g_common_init(void);
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* COMMON_DATA_H_ */
