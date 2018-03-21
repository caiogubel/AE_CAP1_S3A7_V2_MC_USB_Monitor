/* generated thread header file - do not edit */
#ifndef USB_MONITOR_THREAD_H_
#define USB_MONITOR_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus 
extern "C" void usb_monitor_thread_entry(void);
#else 
extern void usb_monitor_thread_entry(void);
#endif
#include "sf_el_ux_comms_v2.h"
#include "sf_comms_api.h"
#include "r_agt.h"
#include "r_timer_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/* USB Communication Framework Instance */
extern const sf_comms_instance_t g_sf_comms0;
/* USBX CDC-ACM Instance Activate User Callback Function */
VOID ux_cdc_device0_instance_activate(VOID *cdc_instance);
/* USBX CDC-ACM Instance Deactivate User Callback Function */
VOID ux_cdc_device0_instance_deactivate_internal(VOID *cdc_instance);
void g_sf_comms0_err_callback(void * p_instance, void * p_data);
void sf_comms_init0(void);
/** AGT Timer Instance */
extern const timer_instance_t g_timer0;
#ifndef agt_cb
void agt_cb(timer_callback_args_t * p_args);
#endif
extern TX_EVENT_FLAGS_GROUP g_s3a7_st_flags;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* USB_MONITOR_THREAD_H_ */
