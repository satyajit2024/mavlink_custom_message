import sys
sys.path.append('/home/satyajit/home/mavlink_custom_message/generated.py')  # Replace '/path/to/generated' with the actual path to the generated directory

from pymavlink import mavutil
import time
import generated as mavlink  # Import the updated MAVLink module

# Set the ngrok tunnel URL and port
ngrok_url = 'localhost'
ngrok_port = '14550'

# Create a MAVLink connection over UDP via ngrok
master = mavutil.mavlink_connection(f'udpout:{ngrok_url}:{ngrok_port}')

# Function to send a custom MAVLink message with a string parameter
def send_custom_mavlink_message():
    # Define the custom message fields for MY_CUSTOM_COMMAND
    target_system = 0
    target_component = 0
    param1 = "Hello, MAVLink!"  # Example string parameter
    param2 = 1.0
    param3 = 2.0
    param4 = 3.0
    param5 = 4.0
    param6 = 5.0
    param7 = 6.0

    # Encode the string parameter to bytes
    param1_encoded = param1.encode("utf-8")

    # Encode the custom message MY_CUSTOM_COMMAND
    msg1 = mavlink.MAVLink_my_custom_command_message(
        target_system,
        target_component,
        param1_encoded,
        param2,
        param3,
        param4,
        param5,
        param6,
        param7
    )

    # Send the MY_CUSTOM_COMMAND message
    master.mav.send(msg1)
    print(f"MY_CUSTOM_COMMAND sent: {msg1}")

    # Define the custom message fields for ANOTHER_CUSTOM_COMMAND
    target_system = 0
    target_component = 0
    param1 = 10.0
    param2 = 20.0
    param3 = 80.5
    param4 = 78.6

    # Encode the custom message ANOTHER_CUSTOM_COMMAND
    msg2 = mavlink.MAVLink_another_custom_command_message(
        target_system,
        target_component,
        param1,
        param2,
        param3,
        param4
    )

    # Send the ANOTHER_CUSTOM_COMMAND message
    master.mav.send(msg2)
    print(f"ANOTHER_CUSTOM_COMMAND sent: {msg2} \n")

# Main loop to send messages periodically
while True:
    send_custom_mavlink_message()
    time.sleep(2)  # Send every 2 seconds
