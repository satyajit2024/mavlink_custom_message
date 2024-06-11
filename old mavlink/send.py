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

def send_custom_mavlink_message():
    target_system = 1
    target_component = 1
    param1 = "Hello, MAVLink!".encode("utf-8")
    param2 = 1.0
    param3 = 2.0
    param4 = 3.0
    param5 = 4.0
    param6 = 5.0
    param7 = 6.0

    msg = mavlink.MAVLink_my_custom_command_message(
        target_system,
        target_component,
        param1,
        param2,
        param3,
        param4,
        param5,
        param6,
        param7
    )
    master.mav.send(msg)
    print(f"MY_CUSTOM_COMMAND sent: {msg}")

def send_another_custom_mavlink_message():
    target_system = 1
    target_component = 1
    param1 = 10.0
    param2 = 20.0
    param3 = 80.5
    param4 = 78.6

    msg = mavlink.MAVLink_another_custom_command_message(
        target_system,
        target_component,
        param1,
        param2,
        param3,
        param4
    )
    master.mav.send(msg)
    print(f"ANOTHER_CUSTOM_COMMAND sent: {msg}")

while True:
    send_custom_mavlink_message()
    # send_another_custom_mavlink_message()
    time.sleep(1)


# send_custom_mavlink_message()
# send_another_custom_mavlink_message()