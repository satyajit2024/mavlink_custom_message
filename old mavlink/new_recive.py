from pymavlink import mavutil

# Create a MAVLink UDP connection (replace '127.0.0.1:14550' with your receiving IP and port)
master = mavutil.mavlink_connection('udp:127.0.0.1:14550')

# Wait for the custom message to be received
while True:
    msg = master.recv_match(type='COMMAND_LONG', blocking=True)
    if msg.get_cmd() == mavutil.mavlink.MAV_CMD_USER_1:
        print("Received custom message:")
        print(f"Param1: {msg.param1}")
        print(f"Param2: {msg.param2}")
        print(f"Param3: {msg.param3}")
        print(f"Param4: {msg.param4}")
        print(f"Param5: {msg.param5}")
        print(f"Param6: {msg.param6}")
        print(f"Param7: {msg.param7}")
        break
