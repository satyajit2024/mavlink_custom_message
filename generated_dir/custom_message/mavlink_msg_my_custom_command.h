#pragma once
// MESSAGE MY_CUSTOM_COMMAND PACKING

#define MAVLINK_MSG_ID_MY_CUSTOM_COMMAND 180


typedef struct __mavlink_my_custom_command_t {
 float param2; /*<  Parameter 2*/
 float param3; /*<  Parameter 3*/
 float param4; /*<  Parameter 4*/
 float param5; /*<  Parameter 5*/
 float param6; /*<  Parameter 6*/
 float param7; /*<  Parameter 7*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 char param1[50]; /*<  Parameter 1*/
} mavlink_my_custom_command_t;

#define MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN 76
#define MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN 76
#define MAVLINK_MSG_ID_180_LEN 76
#define MAVLINK_MSG_ID_180_MIN_LEN 76

#define MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC 44
#define MAVLINK_MSG_ID_180_CRC 44

#define MAVLINK_MSG_MY_CUSTOM_COMMAND_FIELD_PARAM1_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MY_CUSTOM_COMMAND { \
    180, \
    "MY_CUSTOM_COMMAND", \
    9, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_my_custom_command_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_my_custom_command_t, target_component) }, \
         { "param1", NULL, MAVLINK_TYPE_CHAR, 50, 26, offsetof(mavlink_my_custom_command_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_my_custom_command_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_my_custom_command_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_my_custom_command_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_my_custom_command_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_my_custom_command_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_my_custom_command_t, param7) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MY_CUSTOM_COMMAND { \
    "MY_CUSTOM_COMMAND", \
    9, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_my_custom_command_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_my_custom_command_t, target_component) }, \
         { "param1", NULL, MAVLINK_TYPE_CHAR, 50, 26, offsetof(mavlink_my_custom_command_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_my_custom_command_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_my_custom_command_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_my_custom_command_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_my_custom_command_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_my_custom_command_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_my_custom_command_t, param7) }, \
         } \
}
#endif

/**
 * @brief Pack a my_custom_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 3
 * @param param4  Parameter 4
 * @param param5  Parameter 5
 * @param param6  Parameter 6
 * @param param7  Parameter 7
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_my_custom_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param2);
    _mav_put_float(buf, 4, param3);
    _mav_put_float(buf, 8, param4);
    _mav_put_float(buf, 12, param5);
    _mav_put_float(buf, 16, param6);
    _mav_put_float(buf, 20, param7);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_char_array(buf, 26, param1, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
#else
    mavlink_my_custom_command_t packet;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.param1, param1, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MY_CUSTOM_COMMAND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
}

/**
 * @brief Pack a my_custom_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 3
 * @param param4  Parameter 4
 * @param param5  Parameter 5
 * @param param6  Parameter 6
 * @param param7  Parameter 7
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_my_custom_command_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param2);
    _mav_put_float(buf, 4, param3);
    _mav_put_float(buf, 8, param4);
    _mav_put_float(buf, 12, param5);
    _mav_put_float(buf, 16, param6);
    _mav_put_float(buf, 20, param7);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_char_array(buf, 26, param1, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
#else
    mavlink_my_custom_command_t packet;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.param1, param1, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MY_CUSTOM_COMMAND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
#endif
}

/**
 * @brief Pack a my_custom_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 3
 * @param param4  Parameter 4
 * @param param5  Parameter 5
 * @param param6  Parameter 6
 * @param param7  Parameter 7
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_my_custom_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const char *param1,float param2,float param3,float param4,float param5,float param6,float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param2);
    _mav_put_float(buf, 4, param3);
    _mav_put_float(buf, 8, param4);
    _mav_put_float(buf, 12, param5);
    _mav_put_float(buf, 16, param6);
    _mav_put_float(buf, 20, param7);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_char_array(buf, 26, param1, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
#else
    mavlink_my_custom_command_t packet;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.param1, param1, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MY_CUSTOM_COMMAND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
}

/**
 * @brief Encode a my_custom_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param my_custom_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_my_custom_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_my_custom_command_t* my_custom_command)
{
    return mavlink_msg_my_custom_command_pack(system_id, component_id, msg, my_custom_command->target_system, my_custom_command->target_component, my_custom_command->param1, my_custom_command->param2, my_custom_command->param3, my_custom_command->param4, my_custom_command->param5, my_custom_command->param6, my_custom_command->param7);
}

/**
 * @brief Encode a my_custom_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param my_custom_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_my_custom_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_my_custom_command_t* my_custom_command)
{
    return mavlink_msg_my_custom_command_pack_chan(system_id, component_id, chan, msg, my_custom_command->target_system, my_custom_command->target_component, my_custom_command->param1, my_custom_command->param2, my_custom_command->param3, my_custom_command->param4, my_custom_command->param5, my_custom_command->param6, my_custom_command->param7);
}

/**
 * @brief Encode a my_custom_command struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param my_custom_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_my_custom_command_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_my_custom_command_t* my_custom_command)
{
    return mavlink_msg_my_custom_command_pack_status(system_id, component_id, _status, msg,  my_custom_command->target_system, my_custom_command->target_component, my_custom_command->param1, my_custom_command->param2, my_custom_command->param3, my_custom_command->param4, my_custom_command->param5, my_custom_command->param6, my_custom_command->param7);
}

/**
 * @brief Send a my_custom_command message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 3
 * @param param4  Parameter 4
 * @param param5  Parameter 5
 * @param param6  Parameter 6
 * @param param7  Parameter 7
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_my_custom_command_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const char *param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param2);
    _mav_put_float(buf, 4, param3);
    _mav_put_float(buf, 8, param4);
    _mav_put_float(buf, 12, param5);
    _mav_put_float(buf, 16, param6);
    _mav_put_float(buf, 20, param7);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_char_array(buf, 26, param1, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND, buf, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
#else
    mavlink_my_custom_command_t packet;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.param1, param1, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
#endif
}

/**
 * @brief Send a my_custom_command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_my_custom_command_send_struct(mavlink_channel_t chan, const mavlink_my_custom_command_t* my_custom_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_my_custom_command_send(chan, my_custom_command->target_system, my_custom_command->target_component, my_custom_command->param1, my_custom_command->param2, my_custom_command->param3, my_custom_command->param4, my_custom_command->param5, my_custom_command->param6, my_custom_command->param7);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND, (const char *)my_custom_command, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
#endif
}

#if MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_my_custom_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, const char *param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param2);
    _mav_put_float(buf, 4, param3);
    _mav_put_float(buf, 8, param4);
    _mav_put_float(buf, 12, param5);
    _mav_put_float(buf, 16, param6);
    _mav_put_float(buf, 20, param7);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_char_array(buf, 26, param1, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND, buf, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
#else
    mavlink_my_custom_command_t *packet = (mavlink_my_custom_command_t *)msgbuf;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->param5 = param5;
    packet->param6 = param6;
    packet->param7 = param7;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->param1, param1, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND, (const char *)packet, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_CRC);
#endif
}
#endif

#endif

// MESSAGE MY_CUSTOM_COMMAND UNPACKING


/**
 * @brief Get field target_system from my_custom_command message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_my_custom_command_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field target_component from my_custom_command message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_my_custom_command_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field param1 from my_custom_command message
 *
 * @return  Parameter 1
 */
static inline uint16_t mavlink_msg_my_custom_command_get_param1(const mavlink_message_t* msg, char *param1)
{
    return _MAV_RETURN_char_array(msg, param1, 50,  26);
}

/**
 * @brief Get field param2 from my_custom_command message
 *
 * @return  Parameter 2
 */
static inline float mavlink_msg_my_custom_command_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param3 from my_custom_command message
 *
 * @return  Parameter 3
 */
static inline float mavlink_msg_my_custom_command_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param4 from my_custom_command message
 *
 * @return  Parameter 4
 */
static inline float mavlink_msg_my_custom_command_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param5 from my_custom_command message
 *
 * @return  Parameter 5
 */
static inline float mavlink_msg_my_custom_command_get_param5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field param6 from my_custom_command message
 *
 * @return  Parameter 6
 */
static inline float mavlink_msg_my_custom_command_get_param6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field param7 from my_custom_command message
 *
 * @return  Parameter 7
 */
static inline float mavlink_msg_my_custom_command_get_param7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a my_custom_command message into a struct
 *
 * @param msg The message to decode
 * @param my_custom_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_my_custom_command_decode(const mavlink_message_t* msg, mavlink_my_custom_command_t* my_custom_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    my_custom_command->param2 = mavlink_msg_my_custom_command_get_param2(msg);
    my_custom_command->param3 = mavlink_msg_my_custom_command_get_param3(msg);
    my_custom_command->param4 = mavlink_msg_my_custom_command_get_param4(msg);
    my_custom_command->param5 = mavlink_msg_my_custom_command_get_param5(msg);
    my_custom_command->param6 = mavlink_msg_my_custom_command_get_param6(msg);
    my_custom_command->param7 = mavlink_msg_my_custom_command_get_param7(msg);
    my_custom_command->target_system = mavlink_msg_my_custom_command_get_target_system(msg);
    my_custom_command->target_component = mavlink_msg_my_custom_command_get_target_component(msg);
    mavlink_msg_my_custom_command_get_param1(msg, my_custom_command->param1);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN? msg->len : MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN;
        memset(my_custom_command, 0, MAVLINK_MSG_ID_MY_CUSTOM_COMMAND_LEN);
    memcpy(my_custom_command, _MAV_PAYLOAD(msg), len);
#endif
}
