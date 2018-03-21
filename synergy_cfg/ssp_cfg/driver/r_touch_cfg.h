/* generated configuration header file - do not edit */
#ifndef R_TOUCH_CFG_H_
#define R_TOUCH_CFG_H_
/**
 * Specify whether to include code for API parameter checking.
 *    - 1 : Enabled (Assertion messages routed to Renesas Virtual Console if BSP_CFG_IO_LIB_ENABLE==1)
 *    - 0 : No parameter checking (No assertions)
 */
#define TOUCH_CFG_PARAM_CHECKING_ENABLE            (1)

/**
 * Perform drift compensation and sensitivity optimization for non-touched sensors while a sensor is touched.
 */
#define TOUCH_CFG_COMPENSATE_WHILE_TOUCHED      (1)

/**
 * Define the depth of the Single-Input-Single-Output averaging filter.
 */
#define TOUCH_CFG_FILTER_DEPTH                  (1)

/**
 * Define if interval for drift compensation should be variable.
 */
#define TOUCH_CFG_VARIABLE_DRIFT_RATES              (0)

/**
 * Define the type of multi-touch rejection algorithm.
 * 0 := No Multi-Touch Rejection. (Value in max_touched_sensors is ignored)
 * 1 := Multi-Touch rejection will release all touched sensors, if non-debounced touch count is > max_touched_sensors.
 * 2 := Multi-Touch rejection will release all touched sensors, if debounced touch count is > max_touched_sensors.
 * 3 := Multi-Touch rejection will release all touched sensors, if (current debounced sensors - previously debounced sensors) > max_touched_sensors
 */
#define TOUCH_CFG_MULTITOUCH_REJECTION_TYPE                 (0)

/**
 * Maximum open touch configurations used.
 */
#define TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS            (1)

/**
 * Upper limit used while calibrating sensors.
 */
#define TOUCH_CFG_TUNING_UPPER_DRIFT_LIMIT    (150) //(SYNERGY_NOT_DEFINED)

/**
 * Lower limit used when calibrating sensors.
 */
#define TOUCH_CFG_TUNING_LOWER_DRIFT_LIMIT    (100) //(SYNERGY_NOT_DEFINED)

/**
 * Maximum errors allowed before reporting to the upper layer.
 */
#define TOUCH_CFG_MAX_ERROR_COUNT             (1)

/**
 * Define maximum number of upper layer callbacks (Default = 1)
 */
#define TOUCH_CFG_MAX_UPPER_LAYER_CALLBACKS         (1)
#endif /* R_TOUCH_CFG_H_ */
