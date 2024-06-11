from pymavlink import mavutil
import time
import threading

# Import the generated MAVLink message definitions
import mavlink

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

def send_messages():
    while True:
        send_custom_mavlink_message()
        # Uncomment the line below to send another custom message
        # send_another_custom_mavlink_message()
        time.sleep(1)

# Start sending messages in a separate thread
send_thread = threading.Thread(target=send_messages)
send_thread.start()

# Start receiving messages
receive_messages()
