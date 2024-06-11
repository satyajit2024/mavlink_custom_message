from pymavlink import mavutil

# Create a MAVLink UDP connection (replace '127.0.0.1:14550' with your target IP and port)
master = mavutil.mavlink_connection('udp:127.0.0.1:14550')

# Define your custom message parameters
target_system = 1
target_component = 1
param1 = "Hello, MAVLink!"
param2 = 3.14
param3 = 42.0
param4 = 1.618
param5 = 2.718
param6 = 0.577
param7 = 1.414

# Pack the custom message and send it
msg = master.mav.command_long_encode(target_system, target_component,
                                     mavutil.mavlink.MAV_CMD_USER_1,
                                     0,  # Confirmation
                                     param1, param2, param3, param4, param5, param6, param7)
master.mav.send(msg)
print("Custom message sent")

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
