import socket
from pymavlink import mavutil

# Define the ESP32's IP address and port
esp32_ip = '192.168.0.150'  # Replace with your ESP32's IP address
esp32_port = 14550  # Common MAVLink UDP port

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Create a MAVLink connection
master = mavutil.mavlink_connection(f'udpout:{esp32_ip}:{esp32_port}')

# Define the "Hello World" message
message = "Hello World"

# Create the MAVLink message
mav_msg = master.mav.statustext_encode(
    severity=6,  # MAV_SEVERITY_INFO
    text=message
)

# Pack the MAVLink message
packed_msg = mav_msg.pack(master.mav)

# Send the packed MAVLink message to the ESP32
sock.sendto(packed_msg, (esp32_ip, esp32_port))

print("Hello World message sent to ESP32")