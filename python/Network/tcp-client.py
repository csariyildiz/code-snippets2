import socket

def Main():
    host = '127.0.0.1'
    port = 5000

    s = socket.socket()
    s.connect((host, port))
    print ("[*] Print your message. Print q for quit")
    message = input("-> ")
    if message != '':
        s.send(message.encode('utf-8'))
        data = s.recv(1024).decode('utf-8')
        print('Received from server: ' + data)
    s.close()

if __name__ == '__main__':
    Main()
