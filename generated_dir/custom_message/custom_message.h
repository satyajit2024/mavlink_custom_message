/** @file
 *  @brief MAVLink comm protocol generated from custom_message.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_CUSTOM_MESSAGE_H
#define MAVLINK_CUSTOM_MESSAGE_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_CUSTOM_MESSAGE.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_CUSTOM_MESSAGE_XML_HASH 5523623672625756805

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{180, 44, 76, 76, 3, 24, 25}, {181, 19, 18, 18, 3, 16, 17}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_CUSTOM_MESSAGE

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_my_custom_command.h"
#include "./mavlink_msg_another_custom_command.h"

// base include



#if MAVLINK_CUSTOM_MESSAGE_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_MY_CUSTOM_COMMAND, MAVLINK_MESSAGE_INFO_ANOTHER_CUSTOM_COMMAND}
# define MAVLINK_MESSAGE_NAMES {{ "ANOTHER_CUSTOM_COMMAND", 181 }, { "MY_CUSTOM_COMMAND", 180 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_CUSTOM_MESSAGE_H
