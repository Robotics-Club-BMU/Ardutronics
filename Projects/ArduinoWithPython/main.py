import serial
import time 

class App:
    def __init__(self):
        self.ser = serial.Serial('COM4', 9600, timeout=1)
        self.NUMBERS = {
            0: 'ABCDEFH',
            1: 'BCH',
            2: 'ABGDEH',
            3: 'ABCDGH',
            4: 'BCFGH',
            5: 'ABCDGH',
            6: 'AFGCDEH',
            7: 'ABCH',
            8: 'ABCDEFGH',
            9: 'ABFGCH'
        }

    def write_number(self, number: int):
        assert number in range(10), "Number should be between 0 to 9"
        self.ser.write(self.NUMBERS[number].encode())

    def close_connection(self):
        self.ser.close()



def take_choice():
    print("PyArduino")
    print('-'*50)
    print("1 to print a number")
    print("2 to loop through 0 to 9 numbers one by one")
    print("3 to exit")
    print('-'*50)
    choice = int(input("Enter your choice: "))
    return choice


def main():
    app = App()
    while True:
        choice = take_choice()
        if choice == 1:
            number = int(input("Enter the number you wanna write: "))
            if 0 <= number <= 9:
                app.write_number(number)
                print("Printed the number!")
            else:
                print("Please make sure the number is between 0 to 9")
        elif choice == 2:
            for i in range(10):
                print(f"Printing the number {i}")
                app.write_number(i)
                time.sleep(1)                
            print("done with printing the numbers")
        elif choice == 3:
            app.close_connection()
            exit()
        else:
            print("Wrong choice")
        
                
if __name__ == "__main__":
    main()