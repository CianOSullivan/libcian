#ifndef C_LOG_H
#define C_LOG_H

/**
Set the level of the debugger

Level = 0: OFF
Level = 1: INFO
Level = 2: DEBUG
@param level the level to set the debugger to.
 */
void c_set_logger(int level);

/**
Print message if DEBUG level set.

@param message the message to print
 */
void c_log_debug(const char* message);

/**
Print message if INFO level set.

@param message the message to print
 */
void c_log_info(const char* message);

#endif
