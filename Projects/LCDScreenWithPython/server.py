from flask import Flask, render_template, redirect, url_for, jsonify, request
import serial


class Arduino:
    def __init__(self):
        self.ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

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


COUNT = 0
TEXT = "Flask Count: "
app = Flask(__name__)
conn = Arduino()


@app.route("/", methods=['GET', 'POST'])
def home():
    return render_template("home.html", COUNT=COUNT, TEXT=TEXT)


@app.route("/increase")
def increase():
    global COUNT
    COUNT += 1
    conn.increase()
    print(f"The count is: {COUNT}")
    return redirect(url_for("home"))


@app.route("/decrease")
def decrease():
    global COUNT
    COUNT -= 1
    conn.decrease()
    print(f"The count is: {COUNT}")
    return redirect(url_for("home"))


@app.route("/txt")
def txt():
    value1 = request.args.get('val1')
    global TEXT
    TEXT = value1
    print(f"The display text is: {TEXT}")
    conn.set_text(TEXT)
    return jsonify(result=TEXT)


@app.route("/slide_on")
def slide_on():
    conn.slide_on()
    return redirect(url_for("home"))


@app.route("/slide_off")
def slide_off():
    conn.slide_off()
    return redirect(url_for("home"))


@app.route("/count")
def count():
    value1 = request.args.get('val1')
    global COUNT
    COUNT = int(value1)
    print(f"The count is: {COUNT}")
    conn.set_number(COUNT)
    return jsonify(result=COUNT)


if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0")
    conn.close_connection()
