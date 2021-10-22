from flask import Flask, render_template, url_for, request, redirect, make_response
import random
import json
from time import time
from random import random
import serial 


app = Flask(__name__)
arduino = None 
try:
    arduino = serial.Serial(port='/dev/ttyACM2', baudrate=115200, timeout=.1)
except:
    print("Can't connect to arduino. Please check port!")


@app.route('/', methods=["GET", "POST"])
def main():
    return render_template('index.html')


@app.route('/data', methods=["GET", "POST"])
def data():
    # Data Format
    # [TIME, Value Of Sensor 1]
    arduino_data = 0
    try:
        arduino.flushInput()
        arduino_data = arduino.readline()
        arduino_data = str(arduino_data, encoding="utf-8").strip("\n")
        if len(arduino_data) == 0:
            arduino_data = 0
    except:
        print("no data recv")
    print(f"Data from arduino: {arduino_data}")
    data = [time() * 1000, int(arduino_data)]
    response = make_response(json.dumps(data))
    response.content_type = 'application/json'

    return response


if __name__ == "__main__":
    app.run(debug=True, port=5002)
