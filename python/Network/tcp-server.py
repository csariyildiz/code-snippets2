import socket
import threading

host = "127.0.0.1"
port = 5000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((host, port))

server.listen(5)

print ("[*] Listening on %s:%d" % (host, port))

def handle_client(client_socket):
    
    # send something
    client_socket.send(("Connected").encode('utf-8'))
    
    # print out what the client sends
    request = client_socket.recv(1024).decode('utf-8')
    
    print ("[*] Received: %s" % request)
    
    # send back a packet
    client_socket.send(("ACK!\r\n").encode('utf-8'))
    client_socket.close()
    
while True:
    client, addr = server.accept()
    print ("[*] Accepted connection from: %s:%d" % (addr[0], addr[1]))
    # spin up our client thread to handle incoming data
    client_handler = threading.Thread(target=handle_client,args=(client,))
    client_handler.start()