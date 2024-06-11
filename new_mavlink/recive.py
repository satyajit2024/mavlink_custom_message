from pymavlink import mavutil
import time
import mavlink  # Import the generated MAVLink module

# Set the ngrok tunnel URL and port
ngrok_url = '0.0.0.0'
ngrok_port = '14550'

master = mavutil.mavlink_connection(f'udpin:{ngrok_url}:{ngrok_port}')
while True:
    msg = master.recv_match(blocking=True)
    if msg:
        print("Recive Message....",msg)
    time.sleep(1)