# RGB LED Serial Controller 🎨🔴🟢🔵

This is a simple Arduino project that allows you to control an RGB LED using serial communication.  
You can send commands in the format `Rxxx Gxxx Bxxx` (e.g., `R255 G100 B50`) through the Serial Monitor to change the LED color in real time.

---

## 🛠️ Components Used

- Arduino UNO (or compatible board)
- RGB LED (common **cathode**)
- 3x 220Ω resistors
- Breadboard + jumper wires

---

## 🔌 Circuit Diagram

See the `docs/` folder for:
- `circuit.pdf` – full circuit diagram
- `circuit.png` – preview image

---

## 📄 How It Works

1. The Arduino listens for serial input.
2. When a string like `R255 G0 B128` is received:
   - It parses the red, green, and blue components.
   - It sends PWM signals to the respective pins to set the LED color.
3. Feedback is printed on the Serial Monitor.

---

## 🧪 Usage

1. Upload the code in `code/rgb_serial_controller.ino` to your Arduino.
2. Open the **Serial Monitor** (baud rate: `9600`).
3. Send RGB values in this format:

