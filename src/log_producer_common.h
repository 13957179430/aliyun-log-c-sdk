//
// Created by ZhangCheng on 21/11/2017.
//

#ifndef LOG_C_SDK_LOG_PRODUCER_COMMON_H_H
#define LOG_C_SDK_LOG_PRODUCER_COMMON_H_H

#include "log_define.h"
#include <stdint.h>
#include <stddef.h>
LOG_CPP_START


/**
 * log producer result for all operation
 */
typedef int log_producer_result;

/**
 * callback function for producer client
 * @param result send result
 * @param log_bytes log group packaged bytes
 * @param compressed_bytes lz4 compressed bytes
 * @param error_message if send result is not ok, error message is set. must check if is NULL when use it
 * @param send_finished if all data put into log producer client already send out, 1 mean true and 0 means NO
 */
typedef void (*on_log_producer_send_done_function)(const char * config_name, log_producer_result result, size_t log_bytes, size_t compressed_bytes, const char * req_id, const char * error_message, int send_finished, void *user_param);

extern log_producer_result LOG_PRODUCER_OK;
extern log_producer_result LOG_PRODUCER_INVALID;
extern log_producer_result LOG_PRODUCER_WRITE_ERROR;
extern log_producer_result LOG_PRODUCER_DROP_ERROR;
extern log_producer_result LOG_PRODUCER_SEND_NETWORK_ERROR;
extern log_producer_result LOG_PRODUCER_SEND_QUOTA_ERROR;
extern log_producer_result LOG_PRODUCER_SEND_UNAUTHORIZED;
extern log_producer_result LOG_PRODUCER_SEND_SERVER_ERROR;
extern log_producer_result LOG_PRODUCER_SEND_DISCARD_ERROR;
extern log_producer_result LOG_PRODUCER_SEND_TIME_ERROR;


/**
 * check if rst if ok
 * @param rst
 * @return 1 if ok, 0 not ok
 */
LOG_EXPORT int is_log_producer_result_ok(log_producer_result rst);

/**
 * get string value of log producer operation result
 * @param rst
 * @return
 */
LOG_EXPORT const char * get_log_producer_result_string(log_producer_result rst);


LOG_CPP_END

#endif //LOG_C_SDK_LOG_PRODUCER_COMMON_H_H
