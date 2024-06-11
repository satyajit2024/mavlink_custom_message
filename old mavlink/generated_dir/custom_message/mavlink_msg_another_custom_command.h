#pragma once
// MESSAGE ANOTHER_CUSTOM_COMMAND PACKING

#define MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND 181


typedef struct __mavlink_another_custom_command_t {
 float param1; /*<  Parameter 1*/
 float param2; /*<  Parameter 2*/
 float param3; /*<  Parameter 2*/
 float param4; /*<  Parameter 2*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_another_custom_command_t;

#define MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN 18
#define MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN 18
#define MAVLINK_MSG_ID_181_LEN 18
#define MAVLINK_MSG_ID_181_MIN_LEN 18

#define MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC 19
#define MAVLINK_MSG_ID_181_CRC 19



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ANOTHER_CUSTOM_COMMAND { \
    181, \
    "ANOTHER_CUSTOM_COMMAND", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_another_custom_command_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_another_custom_command_t, target_component) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_another_custom_command_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_another_custom_command_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_another_custom_command_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_another_custom_command_t, param4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ANOTHER_CUSTOM_COMMAND { \
    "ANOTHER_CUSTOM_COMMAND", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_another_custom_command_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_another_custom_command_t, target_component) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_another_custom_command_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_another_custom_command_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_another_custom_command_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_another_custom_command_t, param4) }, \
         } \
}
#endif

/**
 * @brief Pack a another_custom_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 2
 * @param param4  Parameter 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_another_custom_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
#else
    mavlink_another_custom_command_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
}

/**
 * @brief Pack a another_custom_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 2
 * @param param4  Parameter 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_another_custom_command_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
#else
    mavlink_another_custom_command_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
#endif
}

/**
 * @brief Pack a another_custom_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 2
 * @param param4  Parameter 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_another_custom_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,float param1,float param2,float param3,float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
#else
    mavlink_another_custom_command_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
}

/**
 * @brief Encode a another_custom_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param another_custom_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_another_custom_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_another_custom_command_t* another_custom_command)
{
    return mavlink_msg_another_custom_command_pack(system_id, component_id, msg, another_custom_command->target_system, another_custom_command->target_component, another_custom_command->param1, another_custom_command->param2, another_custom_command->param3, another_custom_command->param4);
}

/**
 * @brief Encode a another_custom_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param another_custom_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_another_custom_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_another_custom_command_t* another_custom_command)
{
    return mavlink_msg_another_custom_command_pack_chan(system_id, component_id, chan, msg, another_custom_command->target_system, another_custom_command->target_component, another_custom_command->param1, another_custom_command->param2, another_custom_command->param3, another_custom_command->param4);
}

/**
 * @brief Encode a another_custom_command struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param another_custom_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_another_custom_command_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_another_custom_command_t* another_custom_command)
{
    return mavlink_msg_another_custom_command_pack_status(system_id, component_id, _status, msg,  another_custom_command->target_system, another_custom_command->target_component, another_custom_command->param1, another_custom_command->param2, another_custom_command->param3, another_custom_command->param4);
}

/**
 * @brief Send a another_custom_command message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param1  Parameter 1
 * @param param2  Parameter 2
 * @param param3  Parameter 2
 * @param param4  Parameter 2
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_another_custom_command_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND, buf, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
#else
    mavlink_another_custom_command_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.target_system = target_system;
    packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
#endif
}

/**
 * @brief Send a another_custom_command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_another_custom_command_send_struct(mavlink_channel_t chan, const mavlink_another_custom_command_t* another_custom_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_another_custom_command_send(chan, another_custom_command->target_system, another_custom_command->target_component, another_custom_command->param1, another_custom_command->param2, another_custom_command->param3, another_custom_command->param4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND, (const char *)another_custom_command, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
#endif
}

#if MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_another_custom_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND, buf, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
#else
    mavlink_another_custom_command_t *packet = (mavlink_another_custom_command_t *)msgbuf;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->target_system = target_system;
    packet->target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND, (const char *)packet, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_CRC);
#endif
}
#endif

#endif

// MESSAGE ANOTHER_CUSTOM_COMMAND UNPACKING


/**
 * @brief Get field target_system from another_custom_command message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_another_custom_command_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field target_component from another_custom_command message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_another_custom_command_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field param1 from another_custom_command message
 *
 * @return  Parameter 1
 */
static inline float mavlink_msg_another_custom_command_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from another_custom_command message
 *
 * @return  Parameter 2
 */
static inline float mavlink_msg_another_custom_command_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from another_custom_command message
 *
 * @return  Parameter 2
 */
static inline float mavlink_msg_another_custom_command_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from another_custom_command message
 *
 * @return  Parameter 2
 */
static inline float mavlink_msg_another_custom_command_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a another_custom_command message into a struct
 *
 * @param msg The message to decode
 * @param another_custom_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_another_custom_command_decode(const mavlink_message_t* msg, mavlink_another_custom_command_t* another_custom_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    another_custom_command->param1 = mavlink_msg_another_custom_command_get_param1(msg);
    another_custom_command->param2 = mavlink_msg_another_custom_command_get_param2(msg);
    another_custom_command->param3 = mavlink_msg_another_custom_command_get_param3(msg);
    another_custom_command->param4 = mavlink_msg_another_custom_command_get_param4(msg);
    another_custom_command->target_system = mavlink_msg_another_custom_command_get_target_system(msg);
    another_custom_command->target_component = mavlink_msg_another_custom_command_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN? msg->len : MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN;
        memset(another_custom_command, 0, MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND_LEN);
    memcpy(another_custom_command, _MAV_PAYLOAD(msg), len);
#endif
}
