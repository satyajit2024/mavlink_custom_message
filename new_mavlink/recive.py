import sys
from pymavlink import mavutil
import time
import threading

# Add the directory containing the generated MAVLink module to the Python path
# sys.path.append('')  # Replace with the actual path to the directory containing mavlink.py

# Import the generated MAVLink module for the custom message
import mavlink

# Set the ngrok tunnel URL and port
ngrok_url = '0.0.0.0'
ngrok_port = '14550'

# Create a MAVLink connection over UDP via ngrok
master = mavutil.mavlink_connection(f'udpout:{ngrok_url}:{ngrok_port}', source_system=1, source_component=1, dialect='custom_message', verbose=True)

def handle_my_custom_command_message(msg):
    print(f"Received MY_CUSTOM_COMMAND: {msg}")

def handle_another_custom_command_message(msg):
    print(f"Received ANOTHER_CUSTOM_COMMAND: {msg}")

def receive_messages():
    while True:
        msg = master.recv_match(blocking=True)
        if not msg:
            continue

        msg_type = msg.get_type()

        if msg_type == 'MY_CUSTOM_COMMAND':
            handle_my_custom_command_message(msg)
        elif msg_type == 'ANOTHER_CUSTOM_COMMAND':
            handle_another_custom_command_message(msg)

# Start receiving messages
receive_messages()
