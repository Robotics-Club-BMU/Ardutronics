from flask import Flask 
import serial

app = Flask(__name__)


class Arduino:
    def __init__(self):
        self.ser = serial.Serial('COM4', 9600, timeout=1)

    def set_number(self, number: int):
        command = f"cnt {number}"
        self.ser.write(command.encode())

    def set_text(self, text: str):
        command = f"txt {text}"
        self.ser.write(command.encode())

    def slide_on(self):
        command = "sld on"
        self.ser.write(command.encode())
    
    def slide_off(self):
        command = "sld off"
        self.ser.write(command.encode())

    def increase(self):
        command = "icr"
        self.ser.write(command.encode())

    def decrease(self):
        command = "dcr"
        self.ser.write(command.encode())

    def close_connection(self):
        self.ser.close()


COUNT=0
conn = Arduino()

@app.route("/")
def home():
    return f"Basic counter server for arduino.\nCurrent Counter: {COUNT}"


@app.route("/increase")
def increase():
    global COUNT
    COUNT += 1
    conn.increase()
    print(f"The count is: {COUNT}")
    return f"The count is: {COUNT}"

@app.route("/decrease")
def decrease():
    global COUNT
    COUNT -= 1
    conn.decrease()
    print(f"The count is: {COUNT}")
    return f"The count is: {COUNT}"

@app.route("/txt/<text>")
def txt(text):
    conn.set_text(text)
    return text

@app.route("/count/<counter>")
def count(counter:int):
    try:
        COUNT = int(counter)
        conn.set_number(COUNT)
        return f"COUNTER IS {COUNT}"
    except:
        return "Error"

if __name__ == "__main__":
    app.run(debug=True, host="192.168.0.102")
    conn.close_connection()