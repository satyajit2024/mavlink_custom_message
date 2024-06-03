#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>  // Include the <stdlib.h> header for exit()
#include <string.h>
#include "generated_dir/custom_message/mavlink.h"

// Define the target message ID to wait for
#define TARGET_MESSAGE_ID MAVLINK_MSG_ID_MY_CUSTOM_COMMAND

// Explicit declaration of exit() function
void exit(int status);

void handle_mavlink_message(const mavlink_message_t *msg) {
    switch (msg->msgid) {
        case MAVLINK_MSG_ID_MY_CUSTOM_COMMAND: {
            mavlink_my_custom_command_t custom_msg;
            mavlink_msg_my_custom_command_decode(msg, &custom_msg);
            printf("Received MY_CUSTOM_COMMAND: target_system=%d, target_component=%d, param1=%s, param2=%.2f, param3=%.2f, param4=%.2f, param5=%.2f, param6=%.2f, param7=%.2f\n",
                   custom_msg.target_system, custom_msg.target_component, custom_msg.param1, custom_msg.param2, custom_msg.param3, custom_msg.param4, custom_msg.param5, custom_msg.param6, custom_msg.param7);
            // Exit the program after receiving the target message
            exit(0);
            break;
        }
        default:
            printf("Received message with ID: %d\n", msg->msgid);
            break;
    }
}

void mavlink_receive(const uint8_t *buf, uint16_t len) {
    mavlink_message_t msg;
    mavlink_status_t status;

    for (uint16_t i = 0; i < len; ++i) {
        if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status)) {
            printf("Received a MAVLink message\n");  // Debug output
            handle_mavlink_message(&msg);
        } else {
            printf("Failed to parse a MAVLink message\n");  // Debug output
        }
    }
}


int main() {
    // Example buffer containing MAVLink messages (replace with actual data)
    uint8_t example_buffer[] = {
        // Example MAVLink message bytes go here
    };
    uint16_t buffer_length = sizeof(example_buffer) / sizeof(example_buffer[0]);

    // Process received data until the target message is received
    while (1) {
        mavlink_receive(example_buffer, buffer_length);
    }

    return 0;
}
