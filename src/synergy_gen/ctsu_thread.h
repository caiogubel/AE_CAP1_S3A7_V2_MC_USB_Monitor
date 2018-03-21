/* generated thread header file - do not edit */
#ifndef CTSU_THREAD_H_
#define CTSU_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus 
extern "C" void ctsu_thread_entry(void);
#else 
extern void ctsu_thread_entry(void);
#endif
#ifdef __cplusplus
extern "C"
{
#endif
extern TX_EVENT_FLAGS_GROUP ctsu_event_flags;
extern TX_EVENT_FLAGS_GROUP g_new_event_flags0;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* CTSU_THREAD_H_ */
