/*
 *  logging.c:  Logging facilities for nwipe.
 *
 *  Copyright Darik Horn <dajhorn-dban@vanadac.com>.
 *
 *  This program is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free Software
 *  Foundation, version 2.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along with
 *  this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef LOGGING_H_
#define LOGGING_H_

/* Maximum size of a log message */
#define MAX_LOG_LINE_CHARS 512

#define MAX_SIZE_OS_STRING 512 /* Maximum size of acceptable OS string */
#define OS_info_Line_offset 31 /* OS_info line offset in log */
#define OS_info_Line_Length 48 /* OS_info line length */

typedef enum nwipe_log_t_ {
    NWIPE_LOG_NONE = 0,
    NWIPE_LOG_DEBUG,  // TODO:  Very verbose logging.
    NWIPE_LOG_INFO,  // TODO:  Verbose logging.
    NWIPE_LOG_NOTICE,  // Most logging happens at this level.
    NWIPE_LOG_WARNING,  // Things that the user should know about.
    NWIPE_LOG_ERROR,  // Non-fatal errors that result in failure.
    NWIPE_LOG_FATAL,  // Errors that cause the program to exit.
    NWIPE_LOG_SANITY,  // Programming errors.
    NWIPE_LOG_NOTIMESTAMP  // logs the message without the timestamp
} nwipe_log_t;

void nwipe_log( nwipe_log_t level, const char* format, ... );
void nwipe_perror( int nwipe_errno, const char* f, const char* s );
void nwipe_log_OSinfo();
int nwipe_log_sysinfo();
void nwipe_log_summary( nwipe_context_t**, int );  // This produces the wipe status table on exit
void Determine_C_B_nomenclature( u64, char*, int );
void convert_seconds_to_hours_minutes_seconds( u64, int*, int*, int* );
int nwipe_strip_path( char*, char* );

#endif /* LOGGING_H_ */
