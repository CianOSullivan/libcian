#include "c_log.h"
#include <stdio.h>  // printf()
#include <time.h>   // time_t, time(), strftime()

int log_level = OFF;    // The current logging level

void c_set_logger(int level) {
    if (level == 1) {
        log_level = INFO;
        printf("INFO logging set.\n");
    } else if (level == 2) {
        log_level = DEBUG;
        printf("DEBUG logging set.\n");
    } else
        printf("No logging set.\n");
}

/**
Print the current time in the format:
Day Month Year Hour:Minute:second:
 */
void print_time() {
    char time_str[500];
    time_t now = time(NULL);
    struct tm *time_format = localtime(&now);
    strftime(time_str, 500, "%d %B %Y %H:%M:%S", time_format);
    printf("%s: ", time_str);
}

void c_log_info(const char* message) {
    if (log_level == INFO){
        printf("[INFO] ");
        print_time();
        printf("%s\n", message);
    }
}

void c_log_debug(const char* message) {
    if (log_level == DEBUG) {
        printf("[DEBUG] ");
        print_time();
        printf("%s\n", message);
    }
}
