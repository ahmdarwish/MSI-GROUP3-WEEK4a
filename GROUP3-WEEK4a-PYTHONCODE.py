import serial
ser = serial.Serial('COM6', 9600)


while True:
    try:
        data = ser.readline().decode('utf-8').strip()
        print(f"{data}")
        u[]
        if data == "Detected Gesture: Gesture 1":
            # Perform an action for Gesture 1
                print("'Servo Left'")
        elif data == "Detected Gesture: Gesture 2":
            # Perform an action for Gesture 2
                print("'Servo Right'")
            # Add more gesture actions as needed
    except Exception as e:
        print(f"Error reading data: {e}")
