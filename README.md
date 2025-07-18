# 🚨 Burglary Detection System using GSM Module

This project is a standalone home security system that detects motion using a PIR sensor and alerts the owner via a phone call using a GSM module (SIM900A). It uses Arduino UNO and keypad input for secure access.

---

## 🔧 Features

- Motion detection using PIR sensor
- Secure keypad password verification
- Automatic phone call on intrusion
- GSM communication without internet
- Timeout mechanism and alert retry

---

## 📦 Components Used

- Arduino UNO (ATmega328p)
- PIR Motion Sensor
- SIM900A GSM Module
- 4x3 Matrix Keypad
- Jumper Wires, Breadboard, Power Supply

---

## ⚙️ Working

1. Motion is detected using the PIR sensor.
2. The system prompts the user to enter a 4-digit password.
3. If the correct password is not entered within 60 seconds or is wrong:
   - A call is triggered using the GSM module.
4. If the password is correct:
   - No call is made, and access is granted.

---

## 📁 File Structure

- `burglary_detection.ino`: Main Arduino source code
- `mini_projectDoc.pdf`: Detailed project report and documentation
- `circuit_diagram.png`: Circuit layout (if available)
- `README.md`: Project overview and setup

---

## 🚀 Setup Instructions

1. Upload the `.ino` code to your Arduino Uno via Arduino IDE.
2. Connect PIR sensor to digital pin 10.
3. Connect Keypad to pins 3-9.
4. Connect GSM TX to pin 11, RX to pin 12.
5. Insert SIM card into the GSM module.
6. Power everything with suitable supply (Arduino + GSM = ~12V Adapter).

---

## 🔐 Default Password

1234

yaml
Copy
Edit

Press `#` to submit the password.

---

## 📞 Call Behavior

If an intruder enters and password is incorrect or delayed:
- The GSM module automatically dials a predefined number.

---

## 📚 Future Improvements

- Add EEPROM to store numbers permanently
- Include SMS alert along with call
- Add camera module for face detection
- AI/ML-based motion classification

---

## 📄 License

This project is open-source and free to use under the MIT License.

---

## 👥 Authors
- P Rajeev Kumar (S200919)
- N Sowjanya (S201079)
- V Sowmya (S200349)
- B Nithin Kumar (S200746)
- M Shyam Prakash (S200737)
- K Reddy Chaithanya (S201133)

> Guided by: Mr. V Appala Naidu, M.Tech (Assistant Professor, ECE Dept., RGUKT-Srikakulam)
