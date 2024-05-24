# Step 1: Create custom_message.xml File

Create a file named `custom_message.xml` where you will define your custom MAVLink message. This XML file will contain the structure and fields of your custom message.

```xml
<mavlink>
    <messages>
        <!-- Define your custom message here -->
        <message id="180" name="MY_CUSTOM_COMMAND">
            <description>My custom MAVLink command</description>
            <field type="uint8_t" name="target_system">System ID</field>
            <field type="uint8_t" name="target_component">Component ID</field>
            <field type="char[50]" name="param1">Parameter 1</field>
            <field type="float" name="param2">Parameter 2</field>
            <!-- Add more fields as needed -->
        </message>
        <!-- Add other custom messages if required -->
    </messages>
</mavlink>
```

Replace placeholders such as `MY_CUSTOM_COMMAND`, `target_system`, `target_component`, `param1`, `param2`, etc., with actual values and field definitions according to your custom message requirements.

# Step 2: Generate Custom MAVLink Message Bindings

Use the MAVLink generator (`mavgen.py`) to generate Python bindings for your custom message. Run the following command in your terminal:

```bash
mavgen.py --lang=Python --output=generated custom_message.xml
```

This command will generate Python files in a directory named `generated`, containing the necessary bindings for your custom MAVLink message.

# Step 3: Use Custom MAVLink Message in Python Scripts

After generating the bindings, you can use the custom MAVLink message in your Python scripts. Here's an example of how to send a custom message using the generated bindings:

```python
import sys
sys.path.append('/home/satyajit/home/mavlink_custom_message/generated.py')  # Include the path to the generated directory

from pymavlink import mavutil
import time
import generated as mavlink  # Import the generated MAVLink module

# Set the ngrok tunnel URL and port
ngrok_url = 'localhost'
ngrok_port = '14550'

# Create a MAVLink connection over UDP via ngrok
master = mavutil.mavlink_connection(f'udpout:{ngrok_url}:{ngrok_port}')

# Function to send a custom MAVLink message
def send_custom_mavlink_message():
    # Define the custom message fields
    target_system = 1  # Example System ID
    target_component = 1  # Example Component ID
    param1 = "Hello, MAVLink!"  # Example string parameter
    param2 = 1.0  # Example float parameter

    # Encode the string parameter to bytes
    param1_encoded = param1.encode("utf-8")

    # Encode the custom message
    msg = mavlink.MAVLink_MY_CUSTOM_COMMAND_message(
        target_system,
        target_component,
        param1_encoded,
        param2
    )

    # Send the message
    master.mav.send(msg)
    print(f"Custom MAVLink message sent: {msg}")

# Main loop to send messages periodically
while True:
    send_custom_mavlink_message()
    time.sleep(2)  # Send every 2 seconds
```
