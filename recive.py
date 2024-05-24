from pymavlink import mavutil
import time
import generated as mavlink  # Import the generated MAVLink module


ngrok_url = 'localhost'
ngrok_port = '14550'

master = mavutil.mavlink_connection(f'udpin:{ngrok_url}:{ngrok_port}')

def handle_my_custom_command(msg):
    print(f"Received MY_CUSTOM_COMMAND: {msg}")

def handle_another_custom_command(msg):
    print(f"Received ANOTHER_CUSTOM_COMMAND: {msg}")

# master.set_callback('MY_CUSTOM_COMMAND', handle_my_custom_command)
# master.set_callback('ANOTHER_CUSTOM_COMMAND', handle_another_custom_command)

while True:
    msg = master.recv_match(blocking=True)
    if msg:
        print(f"Received message type: {msg.get_type()}")
        if msg.get_type() == 'MY_CUSTOM_COMMAND':
            handle_my_custom_command(msg)
        elif msg.get_type() == 'ANOTHER_CUSTOM_COMMAND':
            handle_another_custom_command(msg)
    time.sleep(1)  # Adjust the sleep time as needed
