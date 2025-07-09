# Arduino_Gate_System
Developed an automated gate using proximity sensors to detect vehicles from either side, opening on approach and closing only after the vehicle has fully passed.
📌 Features
Bidirectional Sensing: Detects vehicles approaching from either side.

Safe Closing Logic: Gate closes only after the car has moved a safe distance away.

Fully Automated: No human interaction required.

Real-Time Operation: Uses proximity sensors for responsive control.

Flexible Deployment: Suitable for homes, commercial lots, or industrial zones.

🛠️ Technologies Used
Microcontroller (e.g., Arduino, ESP32, or Raspberry Pi)

Ultrasonic or IR proximity sensors (front and rear)

Servo or motor-controlled gate arm

Power supply and safety components (limit switches, etc.)

(Optional) LED indicators or buzzer for feedback

⚙️ How It Works
Idle State: The gate remains closed by default.

Approach Detection: A car approaching within a defined range triggers the gate to open.

Exit Detection: The gate remains open until the car moves away from both proximity zones.

Auto-Close: Once clear, the gate closes automatically.
