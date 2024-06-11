import sys
sys.path.append('/home/satyajit/home/mavlink_custom_message/generated.py')  # Adjust the path as needed

from pymavlink import mavutil
import time
import generated as mavlink  # Import the generated MAVLink module

# Set the ngrok tunnel URL and port
ngrok_url = 'localhost'
ngrok_port = '14550'

# Create a MAVLink connection over UDP via ngrok
master = mavutil.mavlink_connection(f'udpout:{ngrok_url}:{ngrok_port}')

def handle_custom_message(msg):
    if msg.get_msgId() == mavlink.MAVLINK_MSG_ID_MY_CUSTOM_COMMAND:
        # Handle MY_CUSTOM_COMMAND message
        target_system = msg.target_system
        target_component = msg.target_component
        param1 = msg.param1.decode("utf-8")  # Decode bytes to string
        param2 = msg.param2
        param3 = msg.param3
        param4 = msg.param4
        param5 = msg.param5
        param6 = msg.param6
        param7 = msg.param7
        print(f"Received MY_CUSTOM_COMMAND: target_system={target_system}, target_component={target_component}, param1={param1}, param2={param2}, param3={param3}, param4={param4}, param5={param5}, param6={param6}, param7={param7}")
    elif msg.get_msgId() == mavlink.MAVLINK_MSG_ID_ANOTHER_CUSTOM_COMMAND:
        # Handle ANOTHER_CUSTOM_COMMAND message
        target_system = msg.target_system
        target_component = msg.target_component
        param1 = msg.param1
        param2 = msg.param2
        param3 = msg.param3
        param4 = msg.param4
        print(f"Received ANOTHER_CUSTOM_COMMAND: target_system={target_system}, target_component={target_component}, param1={param1}, param2={param2}, param3={param3}, param4={param4}")

while True:
    msg = master.recv_match(blocking=True)
    if msg:
        handle_custom_message(msg)
    time.sleep(1)
