/* generated configuration header file - do not edit */
#ifndef R_CTSU_CFG_H_
#define R_CTSU_CFG_H_
/**
 * Specify whether to include code for API parameter checking. Valid settings include:
 *    - 1 : Includes parameter checking
 *    - 0 : Compiles out parameter checking
 */
#define CTSU_CFG_PARAM_CHECKING_ENABLE         (BSP_CFG_PARAM_CHECKING_ENABLE)

#define CTSU_CFG_WRITE_IPL                      ((2))
#define CTSU_CFG_READ_IPL                       ((2))
#define CTSU_CFG_END_IPL                        ((2))

#define CTSU_CFG_INTERRUPT_PRIORITY_LEVEL       (CTSU_CFG_WRITE_IPL|CTSU_CFG_READ_IPL|CTSU_CFG_END_IPL)

#define CTSU_CFG_CALIBRATION_ENABLE             (1)

#define CTSU_CFG_ENABLE_CORRECTION              (0)
#endif /* R_CTSU_CFG_H_ */
