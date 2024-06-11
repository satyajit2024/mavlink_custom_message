#include <stdio.h>
#include "generated_dir/custom_message/mavlink.h"

// Declare the send_custom_message function before main
void send_custom_message(mavlink_channel_t chan);

int main() {
    // Initialize MAVLink channel (if needed)
    mavlink_channel_t chan = MAVLINK_COMM_0;

    // Call your send_custom_message function
    send_custom_message(chan);

    return 0;
}

// Define the send_custom_message function after main
void send_custom_message(mavlink_channel_t chan) {
    mavlink_message_t msg;
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    mavlink_my_custom_command_t custom_msg;

    custom_msg.target_system = 1;  // Example target system ID
    custom_msg.target_component = 1;  // Example target component ID
    strncpy(custom_msg.param1, "Hello, MAVLink!", sizeof(custom_msg.param1));
    custom_msg.param2 = 3.14;
    custom_msg.param3 = 42.0;
    custom_msg.param4 = 1.618;
    custom_msg.param5 = 2.718;
    custom_msg.param6 = 0.577;
    custom_msg.param7 = 1.414;

    mavlink_msg_my_custom_command_encode(1, 200, &msg, &custom_msg);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    // Send the buffer over your communication channel (e.g., serial, UDP, etc.)
    // send_uart_bytes(buf, len);
    printf("Custom message sent\n");
}
