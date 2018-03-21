/* generated thread source file - do not edit */
#include "ctsu_thread.h"

TX_THREAD ctsu_thread;
void ctsu_thread_create(void);
static void ctsu_thread_func(ULONG thread_input);
/** Alignment requires using pragma for IAR. GCC is done through attribute. */
#if defined(__ICCARM__)
#pragma data_alignment = BSP_STACK_ALIGNMENT
#endif
static uint8_t ctsu_thread_stack[1024] BSP_PLACE_IN_SECTION(".stack.ctsu_thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void * p_instance, void * p_data);
TX_EVENT_FLAGS_GROUP ctsu_event_flags;
TX_EVENT_FLAGS_GROUP g_new_event_flags0;
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;
void g_hal_init(void);

void ctsu_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_ctsu_event_flags;
    err_ctsu_event_flags = tx_event_flags_create (&ctsu_event_flags, (CHAR *) "New Event Flags");
    if (TX_SUCCESS != err_ctsu_event_flags)
    {
        tx_startup_err_callback (&ctsu_event_flags, 0);
    }
    UINT err_g_new_event_flags0;
    err_g_new_event_flags0 = tx_event_flags_create (&g_new_event_flags0, (CHAR *) "New Event Flags");
    if (TX_SUCCESS != err_g_new_event_flags0)
    {
        tx_startup_err_callback (&g_new_event_flags0, 0);
    }

    UINT err;
    err = tx_thread_create (&ctsu_thread, (CHAR *) "CTSU Thread", ctsu_thread_func, (ULONG) NULL, &ctsu_thread_stack,
                            1024, 1, 1, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&ctsu_thread, 0);
    }
}

static void ctsu_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* First thread will take care of common initialization. */
    UINT err;
    err = tx_semaphore_get (&g_ssp_common_initialized_semaphore, TX_WAIT_FOREVER);

    if (TX_SUCCESS != err)
    {
        /* Check err, problem occurred. */
        tx_startup_err_callback (&g_ssp_common_initialized_semaphore, 0);
    }

    /* Only perform common initialization if this is the first thread to execute. */
    if (false == g_ssp_common_initialized)
    {
        /* Later threads will not run this code. */
        g_ssp_common_initialized = true;

        /* Perform common module initialization. */
        g_hal_init ();

        /* Now that common initialization is done, let other threads through. */
        /* First decrement by 1 since 1 thread has already come through. */
        g_ssp_common_thread_count--;
        while (g_ssp_common_thread_count > 0)
        {
            err = tx_semaphore_put (&g_ssp_common_initialized_semaphore);

            if (TX_SUCCESS != err)
            {
                /* Check err, problem occurred. */
                tx_startup_err_callback (&g_ssp_common_initialized_semaphore, 0);
            }

            g_ssp_common_thread_count--;
        }
    }

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    ctsu_thread_entry ();
}
